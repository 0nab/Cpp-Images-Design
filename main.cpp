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

// A function for setting brightness via scale and offset
void Image::setBrightness(double scale, int offset) {
    /*
     *  NOTE:
     *  - This function isn't supposed to be here at main.cpp
     *  but I'm developing it just for the time being because
     *  it's more convenient to do it here.
     *
     *  - With this function, our homework is complete :)
     *
     *  - When submitting this homework, we should only submit
     *    these three files:
     *      main.cpp, Image.cpp, and Image.h
     *
     *    It's okey to sumbit other files here as well, but
     *    it's just that those files are not necessary part of the
     *    assignment.
     *
     *  - For our final project, we just gotta add a few member
     *    functions. Other than that, we've already implemented
     *    everything requred for the final project specifications 🤩
     */

    // Research on whta is scale (gain) and offset (bias)?

}

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
    // 3. Save the example image files
    // ----------------------------------------------------------------
    cout<<imageGrey
        <<"\n\n"
        <<imageGradient;
    pgmSaveAsFile(imageGrey,"imageGrey.pgm");
    pgmSaveAsFile(imageGradient,"imageGradient.pgm");

    // Print a whitespace for better readability
    cout<<'\n';

    // ----------------------------------------------------------------
    // 4. Initiate an Image instance using an existing pgm file
    // ----------------------------------------------------------------
    Image imageFromFile {"imageGradient.pgm"};
    cout<<imageFromFile;

    // ----------------------------------------------------------------
    // 5. Adjust brightness and then save as a new file
    // ----------------------------------------------------------------
    // imageFromFile.setBrightness(0.5,-50);
    // pgmSaveAsFile(imageFromFile,"imageGradientAdjusted.pgm");

    // Return 0 to signal success
    return 0;
}
