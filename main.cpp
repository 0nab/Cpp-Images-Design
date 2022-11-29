/*
 *    Deepak Krishnaa Govindarajan
 *    Marcus Naess
 *    Soobin Rho
 *    Fall, 2022
 *    COSC 226: C++ Programming
 *
 *    Hw: A Container class for handling images.
 */

#include "Image.h"

// TODO: First, copy these to Image.cpp and then copy only the
// declartions to Image.h and finally create main.cpp
// following the homework instructions.

#include <string>
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

// Constructor variables
const string DEFAULT_PGM_TYPE {"P2"};  // "P2" or "P5"
const int DEFAULT_COLUMN {500};         // Any integer
const int DEFAULT_ROW {500};            // Any integer
const int DEFAULT_MAX_VALUE {255};     // Any integer from 0 to 255

class Image {
private :

public :
    /*
     *  PGM IMAGE FILE STRUCTURE
     *  PGM stands for Portale GrayMap format.
     *
     *  - Starts with the magic number, which indicates the pgm type.
     *    There are two possible values:
     *     - `P2` is the human readable version encoded with ASCII.
     *     - `P4` is encoded in binary, thereby using less disk storage.
     *  - The next two int numbers are totalColumn and totalRow.
     *    The image dimension is determined by these two numbers.
     *    These numbers are seperated by a whitespace. The whitespace
     *    seperating these numbers can be more than one.
     *  - Finally, int maxValue indicates the maximum possible color
     *    value. In other words, this indicates how many grey colors
     *    there can be between the black (0) and white (maxValue).
     *  - Every number afterwards is the actual color value for the
     *    image. In `P2`, every value is seperated by a whitespace.
     *    In `P4`, however, there's no whitespace. Instead,
     *    every 8 bit (1 byte) is considerred a color value.
     *  - Plus, any line starting with # is ignored as a comment.
     *
     *  Example:
     *    # example.pgm
     *    P2
     *    18 7
     *    255
     *    0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
     *    0  7  7  7  7  0  0 11 11 11 11  0  0 15 15 15 15  0
     *    0  7  0  0  0  0  0 11  0  0  0  0  0 15  0  0 15  0
     *    0  7  7  7  0  0  0 11 11 11  0  0  0 15 15 15 15  0
     *    0  7  0  0  0  0  0 11  0  0  0  0  0 15  0  0  0  0
     *    0  7  7  7  7  0  0 11 11 11 11  0  0 15  0  0  0  0
     *    0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
     */

    std::string pgmType;
    int totalColumn;
    int totalRow;
    int maxValue;
    int* values;

    // ----------------------------------------------------------------
    // STL Requirements
    // ----------------------------------------------------------------
    using iterator = int*;
    using const_iterator = const int*;

    unsigned int size() const { return totalColumn*totalRow; }

    iterator begin() { return values; }
    iterator end() { return values+size(); }
    const iterator begin() const { return values; }
    const iterator end() const { return values+size(); }

    int operator[](int i) { return values[i]; }
    const int operator[](int i) const { return values[i]; }

    // Default constructor
    Image() :
        pgmType{DEFAULT_PGM_TYPE},
        totalColumn{DEFAULT_COLUMN},
        totalRow{DEFAULT_ROW},
        maxValue{DEFAULT_MAX_VALUE},
        values{new int[DEFAULT_COLUMN*DEFAULT_ROW]} {
            // --------------------------------------------------------
            // Default constructor creates a pgm image with a gradient
            // Example:
            //   0 1 2 3 4 5 6 7
            //   1 1 2 3 4 5 6 7
            //   2 2 2 3 4 5 6 7
            //   3 3 3 3 4 5 6 7
            //   4 4 4 4 4 5 6 7
            //   5 5 5 5 5 5 6 7
            //   6 6 6 6 6 6 6 7
            //   7 7 7 7 7 7 7 7
            // --------------------------------------------------------

            // Calculate the right color value increment.
            // This depends on the dimension of the image
            // as well as the maximum possible color value.
            const int largerPixels = std::max(DEFAULT_ROW,DEFAULT_COLUMN);
            const double gradientQuotient = (
                DEFAULT_MAX_VALUE/static_cast<double>(largerPixels)
            );
            int gradientCalculated;

            int countColumn {0};
            int countRow {0};
            for (int i=0; i<DEFAULT_COLUMN*DEFAULT_ROW; ++i) {
                // Count how many columns and how many rows
                ++countColumn;
                if (i!=1 && i%DEFAULT_COLUMN==0) {
                    ++countRow;
                    countColumn = 1;
                }

                // Assign the color value as a gradient
                if (countColumn<countRow) {
                    gradientCalculated = (
                        std::min(
                            std::floor(countRow*gradientQuotient),
                            static_cast<double>(DEFAULT_MAX_VALUE)
                        )
                    );
                    values[i] = gradientCalculated;
                }
                else {
                    gradientCalculated = (
                        std::min(
                            std::floor(countColumn*gradientQuotient),
                            static_cast<double>(DEFAULT_MAX_VALUE)
                        )
                    );
                    values[i] = gradientCalculated;
                }
            }
        }

    // Constructor by a constant color value
    Image(int valueNew) :
        pgmType{DEFAULT_PGM_TYPE},
        totalColumn{DEFAULT_COLUMN},
        totalRow{DEFAULT_ROW},
        maxValue{DEFAULT_MAX_VALUE},
        values{new int[DEFAULT_COLUMN*DEFAULT_ROW]} {
            for (int i=0; i<DEFAULT_COLUMN*DEFAULT_ROW; ++i) {
                values[i] = valueNew;
            }
        }

    // Copy construtor
    Image(const Image& image) :
        pgmType{image.pgmType},
        totalColumn{image.totalColumn},
        totalRow{image.totalRow},
        maxValue{image.maxValue},
        values{new int[image.size()]} {
            copy(image.begin(),image.end(),values);
        }

    // Destructor
    ~Image() { delete[] values; }

    // Move assignment operator overloading
    Image& operator=(Image&& image);
};

Image& Image::operator=(Image&& image) {
    pgmType = image.pgmType;
    totalColumn = image.totalColumn;
    totalRow = image.totalRow;
    maxValue = image.maxValue;

    // Move the pointer to the new values and delete the old values
    delete[] values;
    values = image.values;
    return *this;
}

bool operator==(const Image& image1, const Image& image2) {
    // Check the magic number and the image dimension
    if (image1.pgmType!=image2.pgmType ||
        image1.totalColumn!=image2.totalColumn ||
        image1.totalRow!=image2.totalRow ||
        image1.maxValue!=image2.maxValue) {
        return false;
    }

    // Compare all values
    else {
        for (int i=0; i<image1.size(); ++i) {
            if (image1[i]!=image2[i]) return false;
        }
    }

    return true;
}

bool operator!=(const Image& image1, const Image& image2) {
    return !(image1==image2);
}

std::ostream& operator<<(std::ostream& ost, const Image image) {
    /*
     *  OUTPUT STREAM OPERATOR OVERLOADING
     *
     *  Two possibilities:
     *  1. pgmType is P2. In this case, print all values in ASCII.
     *  2. pgmType is P5. In this case, print all values as bytes.
     */

    if (image.pgmType=="P2") {
        // Output the magic number, image dimension, and maximum value
        ost<<image.pgmType<<'\n'
                 <<image.totalColumn<<' '<<image.totalRow<<'\n'
                 <<image.maxValue;

        // Output all color values in ASCII
        for (int i=0; i<image.size(); ++i) {
            if (i%image.totalColumn==0) ost<<'\n';
            ost<<image.values[i]<<' ';
        }
    }

    else if (image.pgmType=="P5") {
        // Output the magic number, image dimension, and maximum value
        ost<<image.pgmType<<'\n'
                 <<image.totalColumn<<' '<<image.totalRow<<'\n'
                 <<image.maxValue<<'\n';

        // Output all color values as bytes
        for (int i=0; i<image.size(); ++i) {
            ost<<char(image.values[i]);
        }
    }

    return ost;
}

void pgmSaveAsFile(const Image& image, string fileName) {
    std::ofstream ofs {fileName};
    if (!ofs) std::cout<<"[ERROR] Failed to initiate an output stream.\n";
    else ofs<<image;
}

int main() {


    // TEST
    Image image {};

    /* std::cout<<image; */
    pgmSaveAsFile(image,"testtest.pgm");




    // Return 0 to signal success
    return 0;
}

































// ------------------------------------------
// Commented Out
// ------------------------------------------

/* #include "Image.h" */
/* int main() */
/* { */
/*     // Create an image object */
/*     Image image("test.pgm"); */
/*  */
/*     // Print the image pixels vector */
/*  */
/*     vector<int> pixels = image.getPixels(); */
/*     for (int i = 0; i < pixels.size(); i++) */
/*     { */
/*         cout << pixels[i] << " "; */
/*     } */
/*  */
/*  */
/*     // Return 0 to signal success */
/*     return 0; */
/* } */
