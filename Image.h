#include <string>
#include <iostream>
#include <vector>

using namespace std;
/*
 *    Deepak Krishnaa Govindarajan
 *    Marcus Naess
 *    Soobin Rho
 *    Fall, 2022
 *    COSC 226: C++ Programming
 *
 *    Hw: A Container class for handling images.
 */

class Image{
    public:
        Image();
        Image(const string& filename);
        Image(const int& valueRGB);
        Image(const vector<int>);
        Image(const Image& imageCopy);
        ~Image();

        Image& Image::operator=(Image&& image);
    private:
        int rows;
        int cols;
        // Vector of pixels
        vector<int> pixels;
        // Max value of the pixels
        int maxValue;
};

// Helper declarations for the Image class
Image clone(const Image& image);
Image getSubset (const Image& image, int top, int bottom, int left, int right);
Image getSmoothedSubset (const Image& image, const int& smoothValue);
void printHistogram (const Image& image);
void setBrightness (Image& image, const int& gain, const int& bias);