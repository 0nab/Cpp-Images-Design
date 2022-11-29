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
using namespace std;

class Image {
public :
    using value_type = int;
    using iterator = int*;

private:
    // ----------------------------------------------------------------
    // PGM IMAGE FILE STRUCTURE
    // PGM stands for "Portale Graymap Format"
    //
    // - Starts with the magic number, which indicates the pgm type.
    //   There are two possible values:
    //    - `P2` is the human readable version encoded with ASCII.
    //    - `P4` is encoded in binary, thereby using less disk storage.
    // - The next two int numbers are totalColumn and totalRow.
    //   The image dimension is determined by these two numbers.
    //   These numbers are seperated by a whitespace. The whitespace
    //   seperating these numbers can be more than one.
    // - Finally, int maxValue indicates the maximum possible color
    //   value. In other words, this indicates how many grey colors
    //   there can be between the black (0) and white (maxValue).
    // - Every number afterwards is the actual color value for the
    //   image. In `P2`, every value is seperated by a whitespace.
    //   In `P4`, however, there's no whitespace. Instead,
    //   every 8 bit (1 byte) is considerred a color value.
    // - Plus, any line starting with # is ignored as a comment.
    //
    // Example:
    //   P2
    //   18 7
    //   255
    //   0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
    //   0  7  7  7  7  0  0 11 11 11 11  0  0 15 15 15 15  0
    //   0  7  0  0  0  0  0 11  0  0  0  0  0 15  0  0 15  0
    //   0  7  7  7  0  0  0 11 11 11  0  0  0 15 15 15 15  0
    //   0  7  0  0  0  0  0 11  0  0  0  0  0 15  0  0  0  0
    //   0  7  7  7  7  0  0 11 11 11 11  0  0 15  0  0  0  0
    //   0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
    // ----------------------------------------------------------------
    std::string pgmType;
    int totalColumn;
    int totalRow;
    int maxValue;

};

int main() {





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
