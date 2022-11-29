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
using namespace std;

class Image {
private :
    // Used for constructors. You can customize these if you want.
    const string DEFAULT_PGM_TYPE {"P2"};
    static const int DEFAULT_COLUMN {50};
    static const int DEFAULT_ROW {50};
    static const int DEFAULT_MAX_VALUE {255};
    static const int DEFAULT_COLOR_VALUE {0};
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

    using value_type = int;
    using iterator = int*;

    std::string pgmType;
    int totalColumn;
    int totalRow;
    int maxValue;
    int* values;

    // Default constructor creates a wedge pgm image.
    // Example:
    //   0 1 2 3 4 5 6 7
    //   1 1 2 3 4 5 6 7
    //   2 2 2 3 4 5 6 7
    //   3 3 3 3 4 5 6 7
    //   4 4 4 4 4 5 6 7
    //   5 5 5 5 5 5 6 7
    //   6 6 6 6 6 6 6 7
    //   7 7 7 7 7 7 7 7
    Image() :
        pgmType{DEFAULT_PGM_TYPE},
        totalColumn{DEFAULT_COLUMN},
        totalRow{DEFAULT_ROW},
        maxValue{DEFAULT_MAX_VALUE},
        values{new int[DEFAULT_COLUMN*DEFAULT_ROW]} {
            int countColumn {0};
            int countRow {0};
            for (int i=0; i<DEFAULT_COLUMN*DEFAULT_ROW; ++i) {
                ++countColumn;
                if (i!=1 && i%DEFAULT_COLUMN==0) {
                    ++countRow;
                    countColumn = 1;
                }

                if (countColumn<countRow) {
                    values[i] = countRow;
                }
                else {
                    values[i] = countColumn;
                }

                // TODO: Delete after debug
                /* cout<<i<<" | countColumn="<<countColumn<<" | countRow="<<countRow<<'\n'; */
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
};

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
        int totalPixels = image.totalColumn * image.totalRow;
        for (int i=0; i<totalPixels; ++i) {
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
        int totalPixels = image.totalColumn * image.totalRow;
        for (int i=0; i<totalPixels; ++i) {
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

    std::cout<<image;
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
