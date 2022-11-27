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
#include "Image.h"

using namespace std;

// Implement the Image constructor here
Image::Image()
{
    rows = 0;
    cols = 0;
    pixels = vector<int>();
}
