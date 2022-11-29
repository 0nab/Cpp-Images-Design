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
    // 1. Create a constant image and histogram the image
    // ----------------------------------------------------------------
    const int CONSTANT_COLOR {13};
    Image imageGrey {CONSTANT_COLOR};
    imageGrey.printHistogram();

    // Print whitespace for better readability
    cout<<'\n';

    // ----------------------------------------------------------------
    // 2. Create a wedge image and histogram the image
    // ----------------------------------------------------------------
    Image imageGradient {};
    imageGradient.printHistogram();

    // ----------------------------------------------------------------
    // 3. Save the example image files
    // ----------------------------------------------------------------
    pgmSaveAsFile(imageGrey,"imageGrey.pgm");
    pgmSaveAsFile(imageGradient,"imageGradient.pgm");

    // Return 0 to signal success
    return 0;
}
