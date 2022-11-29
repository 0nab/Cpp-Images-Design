/*
 *    Deepak Krishnaa Govindarajan
 *    Marcus Naess
 *    Soobin Rho
 *    Fall, 2022
 *    COSC 226: C++ Programming
 *
 *    Hw: A Container class for handling images.
 */

#include <cmath>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>    // Required for cout<<setw(...)
#include <iostream>

// Constructor variables
const std::string DEFAULT_PGM_TYPE {"P2"};  // "P2" or "P5"
const int DEFAULT_COLUMN {25};              // Any integer
const int DEFAULT_ROW {10};                 // Any integer
const int DEFAULT_MAX_VALUE {15};           // Any integer from 0 to 255

class Image {
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
            std::copy(image.begin(),image.end(),values);
        }

    // Destructor
    ~Image() { delete[] values; }

    // Move assignment operator overloading
    Image& operator=(Image&& image);

    // Histogram function
    void printHistogram();
};

// Operator overloading
bool operator==(const Image& image1, const Image& image2);
bool operator!=(const Image& image1, const Image& image2);
std::ostream& operator<<(std::ostream& ost, const Image image);

// Helper functions
void pgmSaveAsFile(const Image& image, std::string fileName);