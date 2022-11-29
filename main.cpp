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

int main()
{

    // Create an image object
    Image image("test.pgm");

    // Print the image pixels vector

    vector<int> pixels = image.getPixels();
    for (int i = 0; i < pixels.size(); i++)
    {
        cout << pixels[i] << " ";
    }
    


    // Return 0 to signal success
    return 0;
}
