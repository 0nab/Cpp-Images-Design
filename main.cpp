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

// --------------------------------
// START
// --------------------------------
#include <vector>
// Scale function
/* Image& Image::adjust(double percentage) { */
/*  */
/* } */

// Offset function
/* Image& Image::adjust(int xOffset, int yOffset) { */
/*  */
/* } */

// Histogram function
void Image::printHistogram() {
    // Count occurence of each color value
    vector<int> counts(maxValue+1, 0);
    for (int i=0; i<size(); ++i) ++counts[values[i]];

    // Print the results. Align all values neatly.
    // Find how many setfills are required for alignment.
    const int howManyTens=std::floor(std::log10(maxValue))+1;
    for (int i=0; i<maxValue+1; ++i) {
        cout<<setw(howManyTens)<<i<<':';

        // Calculate percentage and print '*' the same amount
        double percentage = static_cast<double>(counts[i])/size()*100;
        percentage = std::round(percentage);
        for (int count=0; count<percentage; ++count) {
            cout<<'*';
        }

        // End of histogram
        cout<<'\n';
    }
}

int main() {

    // ----------------------------------------------------------------
    // 1. Create a constant image and histogram the image
    // ----------------------------------------------------------------
    Image imageGrey {13};
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

// Turn in your code and some sample output in a text file.  Note -- this is NOT a GUI program!
    // Return 0 to signal success
    return 0;
}
