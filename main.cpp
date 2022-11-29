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
using namespace std;

class Image {
private :
    // Used by the default constructor for creating an empty image
    const string DEFAULTPGMTYPE {"P2"};
    static const int DEFAULTCOLUMN {30};
    static const int DEFAULTROW {10};
    static const int DEFAULTMAXVALUE {255};
    static const int DEFAULTCOLORVALUE {0};
public :
    /*
     * PGM IMAGE FILE STRUCTURE
     * PGM stands for Portale GrayMap format.
     *
     * - Starts with the magic number, which indicates the pgm type.
     *   There are two possible values:
     *    - `P2` is the human readable version encoded with ASCII.
     *    - `P4` is encoded in binary, thereby using less disk storage.
     * - The next two int numbers are totalColumn and totalRow.
     *   The image dimension is determined by these two numbers.
     *   These numbers are seperated by a whitespace. The whitespace
     *   seperating these numbers can be more than one.
     * - Finally, int maxValue indicates the maximum possible color
     *   value. In other words, this indicates how many grey colors
     *   there can be between the black (0) and white (maxValue).
     * - Every number afterwards is the actual color value for the
     *   image. In `P2`, every value is seperated by a whitespace.
     *   In `P4`, however, there's no whitespace. Instead,
     *   every 8 bit (1 byte) is considerred a color value.
     * - Plus, any line starting with # is ignored as a comment.
     *
     * Example:
     *   # example.pgm
     *   P2
     *   18 7
     *   255
     *   0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
     *   0  7  7  7  7  0  0 11 11 11 11  0  0 15 15 15 15  0
     *   0  7  0  0  0  0  0 11  0  0  0  0  0 15  0  0 15  0
     *   0  7  7  7  0  0  0 11 11 11  0  0  0 15 15 15 15  0
     *   0  7  0  0  0  0  0 11  0  0  0  0  0 15  0  0  0  0
     *   0  7  7  7  7  0  0 11 11 11 11  0  0 15  0  0  0  0
     *   0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
     */

    using value_type = int;
    using iterator = int*;

    std::string pgmType;
    int totalColumn;
    int totalRow;
    int maxValue;
    int* values;

    // Default constructor creates an empty pgm image
    Image() :
        pgmType{DEFAULTPGMTYPE},
        totalColumn{DEFAULTCOLUMN},
        totalRow{DEFAULTROW},
        maxValue{DEFAULTMAXVALUE},
        values{new int[DEFAULTCOLUMN*DEFAULTROW]} {
            for (int i=0; i<DEFAULTCOLUMN*DEFAULTROW; ++i) {
                values[i] = DEFAULTCOLORVALUE;
            }
        }

    // Constructor by a constant color value
    Image(int valueNew) :
        pgmType{DEFAULTPGMTYPE},
        totalColumn{DEFAULTCOLUMN},
        totalRow{DEFAULTROW},
        maxValue{DEFAULTMAXVALUE},
        values{new int[DEFAULTCOLUMN*DEFAULTROW]} {
            for (int i=0; i<DEFAULTCOLUMN*DEFAULTROW; ++i) {
                values[i] = valueNew;
            }
        }
};

std::ostream& operator<<(std::ostream& ost, const Image image) {
    /*
     *
     */
    if (image.pgmType=="P2") {
        // Output the magic number, image dimension, and maximum value
        cout<<image.pgmType<<'\n'
            <<image.totalColumn<<' '<<image.totalRow<<'\n'
            <<image.maxValue;

        // Output all color values
        int totalPixels = image.totalColumn * image.totalRow;
        for (int i=0; i<totalPixels; ++i) {
            if (i%image.totalColumn==0) cout<<'\n';
            cout<<image.values[i]<<' ';
        }
    }

    else if (image.pgmType=="P5") {
    }

    else {

    }

    return ost;
}

int main() {


    Image image {0};

    cout<<image;




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
