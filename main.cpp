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
using namespace std;

int main() {

    // ----------------------------------------------------------------
    // 1. Create a constant image and print a histogram of the image
    // ----------------------------------------------------------------
    const int CONSTANT_COLOR {13};
    Image imageGrey {CONSTANT_COLOR};
    imageGrey.printHistogram();

    // Print a whitespace for better readability
    cout<<'\n';

    // ----------------------------------------------------------------
    // 2. Create a wedge image and print a histogram of the image
    // ----------------------------------------------------------------
    Image imageGradient {};
    imageGradient.printHistogram();

    // Print a whitespace for better readability
    cout<<'\n';

    // ----------------------------------------------------------------
    // 3. Print and save the example image files
    // ----------------------------------------------------------------
    cout<<imageGrey
        <<"\n\n"
        <<imageGradient;
    pgmSaveAsFile(imageGrey,"imageGrey.pgm");
    pgmSaveAsFile(imageGradient,"imageGradient.pgm");

    // Return 0 to signal success
    return 0;
}
