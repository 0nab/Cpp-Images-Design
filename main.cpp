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
    // 1. Create a gradient image
    // ----------------------------------------------------------------
    Image imageGradient {};
    std::cout<<imageGradient;
    pgmSaveAsFile(imageGradient,"imageGradient.pgm");

    // Print whitespace for readability
    cout<<'\n'
        <<'\n';

    // ----------------------------------------------------------------
    // 2. Create an image with a constant value
    // ----------------------------------------------------------------
    Image imageGrey {123};
    std::cout<<imageGrey;
    pgmSaveAsFile(imageGrey,"imageGrey.pgm");





    // Return 0 to signal success
    return 0;
}
