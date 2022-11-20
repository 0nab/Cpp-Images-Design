<p align="center">
  <img alt="Image example" src="https://twemoji.maxcdn.com/v/latest/svg/1f60e.svg" width="200px">
</p>

# A C++ class for images

Created as a part of
our *C++ Programming* assignment.

<br>

```bash
# Project structure
├── main.cpp     # Main driver
├── Image.cpp    # Definitions for the class and helper functions
└── Image.h      # Declarations for the class and helper functions
```

<br>

***Core Design***
- [ ] All bits are stored as a single-dimension array with `vector<unsigned int>`.
- [ ] Internally, we keep track of the image structure using
three variables: `nl` number of lines, `ns` number of samples,
and `nb` number of bands.
- [ ] Support for 8-bit images, but at the same time,
all of our variables are future proof for 16-bit and 32-bit images as well.
We'll paramatize the image bit value -- e.g. `int BIT = 8`.

<br>

***Constructor Design***
```c++
// Image.h
Image(const String& fileName);
Image(const int& valueRGB);
Image(const vector<int>& valuesRGB);
Image(const Image& imageCopy);
~Image();

// Move operator overloading
Image& Image::operator=(const Image& image);
```
- [ ] Constructor by reading `.png` files.
- [ ] Constructor by a constant value for testing purposes.
- [ ] Constructor by a wedge of pixel values for testing purposes.
- [ ] Constructor by copying a pre-existing image.
- [ ] Destructor to prevent memory leaks.
- [ ] Move operator overloading.

<!--
MOVE OPERATOR OVERLOADING EXAMPLE
Source: our textbook
vector& vector::operator=(vector&& a) // move assignment
{
delete[] elem; // deallocate old space
elem = a.elem; // copy a’s elem and sz
sz = a.sz;
a.elem = nullptr; // make a the empty vector
a.sz = 0;
return *this; // return a self-reference (see §17.10)
}
-->

<br>

***Helper Function Design***
```c++
// Image.h
Image getSubset(const Image& image, const int& top, const int& left, const int& right, const int& bottom);
Image getSmoothedSubset(const Image& image, const int& smoothValue);
void printHistogram(Image& image);
void setBrightness(Image& image, const int& gain, const int& bias);
```
- [ ] A function for subsetting an image -- i.e.
extracting a subset of the image.
- [ ] A function for extracting a smoothed, downsampled subset.
- [ ] A function for printing a histogram, which is a vector of brightness-pixel-value counts.
- [ ] A function for adjusting brightness by scaling and offsetting
-- i.e. gain and bias.

<br>
<br>
<br>

<!--
TO DO
- How do we make our data structures future proof
for 16-bit and 32-bit images?

HOW TO ADD CO-AUTHORS IN COMMIT MESSAGES:
Co-authored-by: Deepak <77573925+deepakkrish212@users.noreply.github.com>
Co-authored-by: Marcus <79320268+0nab@users.noreply.github.com>
Co-authored-by: Soobin <soobinrho@gmail.com>

