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
#include <string> // Required for string
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

Image::Image(const string& filename)
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
    
    // Read the first line of the file
    string line;
    while (getline(file, line))
    {
        // Check if the line is a comment
        if (line[0] == '#')
        {
            continue;
        }
        // Check if the line is the image size
        else if (line[0] == 'P')
        {
            // Read the image size
            file >> cols >> rows;
            // Read the max value
            file >> maxValue;
            // Read the pixels
            int pixel;
            while (file >> pixel)
            {
                pixels.push_back(pixel);
            }
        }
    }

    file.close();

}

Image::Image(const int& valueRGB)
{
    rows = 1;
    cols = 1;
    pixels = vector<int>();
    pixels.push_back(valueRGB);
    maxValue = 255;
}
