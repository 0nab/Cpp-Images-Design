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

Image& Image::operator=(Image&& image) {
    pgmType = image.pgmType;
    totalColumn = image.totalColumn;
    totalRow = image.totalRow;
    maxValue = image.maxValue;

    // Move the pointer to the new values and delete the old values
    delete[] values;
    values = image.values;
    return *this;
}

bool operator==(const Image& image1, const Image& image2) {
    // Check the magic number and the image dimension
    if (image1.pgmType!=image2.pgmType ||
        image1.totalColumn!=image2.totalColumn ||
        image1.totalRow!=image2.totalRow ||
        image1.maxValue!=image2.maxValue) {
        return false;
    }

    // Compare all values
    else {
        for (int i=0; i<image1.size(); ++i) {
            if (image1[i]!=image2[i]) return false;
        }
    }

    return true;
}

bool operator!=(const Image& image1, const Image& image2) {
    return !(image1==image2);
}

std::ostream& operator<<(std::ostream& ost, const Image image) {
    /*
     *  OUTPUT STREAM OPERATOR OVERLOADING
     *
     *  Two possibilities:
     *  1. pgmType is P2. In this case, print all values in ASCII.
     *  2. pgmType is P5. In this case, print all values as bytes.
     */

    if (image.pgmType=="P2") {
        // Output the magic number, image dimension, and maximum value
        ost<<image.pgmType<<'\n'
                 <<image.totalColumn<<' '<<image.totalRow<<'\n'
                 <<image.maxValue;

        // Output all color values in ASCII
        for (int i=0; i<image.size(); ++i) {
            if (i%image.totalColumn==0) ost<<'\n';
            ost<<image.values[i]<<' ';
        }
    }

    else if (image.pgmType=="P5") {
        // Output the magic number, image dimension, and maximum value
        ost<<image.pgmType<<'\n'
                 <<image.totalColumn<<' '<<image.totalRow<<'\n'
                 <<image.maxValue<<'\n';

        // Output all color values as bytes
        for (int i=0; i<image.size(); ++i) {
            ost<<char(image.values[i]);
        }
    }

    return ost;
}

void pgmSaveAsFile(const Image& image, std::string fileName) {
    std::ofstream ofs {fileName};
    if (!ofs) std::cout<<"[ERROR] Failed to initiate an output stream.\n";
    else ofs<<image;
}

void Image::printHistogram() {
    // Count occurences of each color value.
    // Initialize a vector with `maxValue+1` elements
    // and initial value of 0.
    std::vector<int> counts(maxValue+1, 0);
    for (int i=0; i<size(); ++i) ++counts[values[i]];

<<<<<<< HEAD
// Implement the getSubset() helper function here
Image getSubset(const Image &image, int top, int bottom, int left, int right) 
{
    // Find a what to index thru the pixel vector.
    return image;
}

// Implement the getSmoothedSubset() helper function here
Image getSmoothedSubset(const Image &image, const int &smoothValue) 
{
    //How do we smothen the values? 
    return image;
}

// Implement the printHistogram() helper function here
void printHistogram(const Image &image)
{
    //Change this, make it value information. like an actual terminal printed histogram.
    //(Marcus) I used the code that Deepak created to try printing out values from the test.pgm file he created.
    vector<int> pixels = image.getPixels();
    vector<int> histogram;
    for (int i = 0; i < pixels.size(); i++)
    {
        int element = pixels.at(i);
        vector<int>::iterator it = find(histogram.begin(), histogram.end(), element);
        if (it != histogram.end()) {
            histogram.at(it - histogram.begin()) = element + 1;
=======
    // Print the results. Align all values neatly.
    // Find how many widths are required for alignment.
    const int howManyTens=std::floor(std::log10(maxValue))+1;
    for (int i=0; i<maxValue+1; ++i) {
        std::cout<<std::setw(howManyTens)<<i<<':';

        // Calculate percentage and print '*' the same amount
        double percentage = static_cast<double>(counts[i])/size()*100;
        percentage = std::round(percentage);
        for (int count=0; count<percentage; ++count) {
            std::cout<<'*';
>>>>>>> bfc662d6d4818d33ad151efe327befe807912aa0
        }

        // End of histogram
        std::cout<<'\n';
    }
}
