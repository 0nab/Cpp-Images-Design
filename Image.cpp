/*
 *    Deepak Krishnaa Govindarajan
 *    Marcus Naess
 *    Soobin Rho
 *    Fall, 2022
 *    COSC 226: C++ Programming
 *
 *    Hw: A Container class for handling images.
 */

#include <iostream> // Required for cout
#include <string>   // Required for string
#include "Image.h"
#include <fstream>

using namespace std;

// Implement the Image constructor here
Image::Image()
{
    rows = 0;
    cols = 0;
    pixels = vector<int>();
    maxValue = 0;
}

Image::Image(const string &filename)
{
    ifstream file(filename);

    // Check if file exists
    if (!file)
    {
        cout << "File does not exist" << endl;
        // Calling the default constructor to create an empty image
        Image();
        return;
    }

    // Read the file and get the rows, cols, and max value
    string line;

    while(file >> line)
    {
        if (line == "P2")
        {
            file >> cols;
            file >> rows;
            file >> maxValue;
            break;
        }
    }

    // Read the pixels
    int pixel;
    while(file >> pixel)
    {
        pixels.push_back(pixel);
    }

    file.close();
}

Image::Image(const int &valueRGB)
{
    rows = 1;
    cols = 1;
    pixels = vector<int>();
    pixels.push_back(valueRGB);
    maxValue = 255;
}

Image::Image(const vector<int> pixels)
{
    rows = 1;
    cols = pixels.size();
    this->pixels = pixels;
    maxValue = 255;
}

Image::Image(const Image &imageCopy)
{
    rows = imageCopy.rows;
    cols = imageCopy.cols;
    pixels = imageCopy.pixels;
    maxValue = imageCopy.maxValue;
}

Image::~Image()
{
    // Nothing to do here
}

// Implement the getPixels() method here
vector<int> Image::getPixels() const
{
    return pixels;
}
