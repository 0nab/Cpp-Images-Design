/*
 *    Deepak Krishnaa Govindarajan
 *    Marcus Naess
 *    Soobin Rho
 *    Fall, 2022
 *    COSC 226: C++ Programming
 *
 *    Hw: A Container class for handling images.
 */
















// ------------------------------------------
// Commented Out
// ------------------------------------------

/* #include <string> */
/* #include <iostream> */
/* #include <vector> */
/*  */
/* using namespace std; */
/*  */
/*  */
/* class Image */
/* { */
/* public: */
/*     Image(); */
/*     Image(const string &filename); */
/*     Image(const int &valueRGB, const int &rows, const int &cols, const int &maxValue); */
/*     Image(const vector<int>, const int & rows, const int &cols); */
/*     Image(const Image &imageCopy); */
/*     ~Image(); */
/*  */
/*     // Image &Image::operator=(Image &&image); */
/*     //Getter for pixels */
/*     vector<int> getPixels() const; */
/*     //Getter for rows */
/*     int getRows() const; */
/*     //Getter for cols */
/*     int getCols() const; */
/*     //Getter for maxValue */
/*     int getMaxValue() const; */
/*  */
/*     //Setters for pixels */
/*     void setPixels(const vector<int> &pixels); */
/*     //Setters for rows */
/*     void setRows(const int &rows); */
/*     //Setters for cols */
/*     void setCols(const int &cols); */
/*     //Setters for maxValue */
/*     void setMaxValue(const int &maxValue); */
/*  */
/* private: */
/*     int rows; */
/*     int cols; */
/*     // Vector of pixels */
/*     vector<int> pixels; */
/*     // Max value of the pixels */
/*     int maxValue; */
/* }; */
/*  */
/* // Helper declarations for the Image class */
/* Image clone(const Image &image); */
/* Image getSubset(const Image &image, int top, int bottom, int left, int right); */
/* Image getSmoothedSubset(const Image &image, const int &smoothValue); */
/* void printHistogram(const Image &image); */
/* void setBrightness(Image &image, const int &gain, const int &bias); */