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
Image& Image::operator=(Image&& image);
```
- [ ] Constructor by reading `.pgm` files.
- [ ] Constructor by a constant value for testing purposes.
- [ ] Constructor by a wedge of pixel values for testing purposes.
- [ ] Constructor by copying a pre-existing image.
- [ ] Destructor to prevent memory leaks.
- [ ] Move operator overloading.

<!--
MOVE OPERATOR OVERLOADING EXAMPLE
Source: Chapter 18 on our textbook
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
Image clone(const Image& image);
Image getSubset(const Image& image, const int& top, const int& left, const int& right, const int& bottom);
Image getSmoothedSubset(const Image& image, const int& smoothValue);
void printHistogram(Image& image);
void setBrightness(Image& image, const int& gain, const int& bias);
Image sharpening(const Image& image, int& width, int& height);
```
- [ ] A function for getting a copy.
- [ ] A function for subsetting an image -- i.e.
extracting a subset of the image.
- [ ] A function for extracting a smoothed, downsampled subset.
- [ ] A function for printing a histogram, which is a vector of brightness-pixel-value counts.
- [ ] A function for adjusting brightness by scaling and offsetting
-- i.e. gain and bias.
- [ ] A function to sharpen your image using Gaussian Blur

<br>

***What are `.pgm` image files?***<br>
Source: https://en.wikipedia.org/wiki/Netpbm#File_formats

> Netpbm (formerly Pbmplus) is an open-source package of graphics programs and a programming library. It is used mainly in the Unix world ...
> Several graphics formats are used and defined by the Netpbm project. The portable pixmap format (PPM), the portable graymap format (PGM) and the portable bitmap format (PBM) are image file formats designed to be easily exchanged between platforms ...
> The "magic number" (Px) at the beginning of a file determines the type, not the file extension ...
> By the end of 1988, Poskanzer had developed the PGM and PPM formats along with their associated tools and added them to Pbmplus. The final release of Pbmplus was December 10, 1991 ...
>
> Each file starts with a two-byte magic number (in ASCII) that identifies the type of file it is (PBM, PGM, and PPM) and its encoding (ASCII/"plain" or binary/"raw"). The magic number is a capital P followed by a single-digit number.
>
> | ***Type*** | ***Magic number*** | ***Extension*** | ***Colors*** |
> | ---------- | ------------------ | --------------- | ------------ |
> | Portable BitMap | `P1` (ASCII, plain) or `P4` (Binary, raw)  | `.pbm` | `0-1` (white & black) |
> | Portable GrayMap | `P2` (ASCII, plain) or `P5` (Binary, raw)  | `.pgm` | `0-255` (gray scale) or `0-65535` (gray scale) or `any vairable number` (black-to-white- range) |
> | Portable PixMap | `P3` (ASCII, plain) or `P6` (Binary, raw)  | `.ppm` | `16 777 216` (0-255 for each RGB channel) or some support for `0-65535` per channel |
>
> The ASCII ("plain") formats allow for human readability and easy transfer to other platforms; the binary ("raw") formats are more efficient in file size but may have native byte-order issues.
>
> In the binary formats, PBM uses 1 bit per pixel, PGM uses 8 or 16 bits per pixel, and PPM uses 24 bits per pixel: 8 for red, 8 for green, 8 for blue. Some readers and writers may support 48 bits per pixel (16 each for R,G,B), but this is still rare ...
>
> Conventionally PGM stores values in linear color space ...
>
> It is not required that pixels are nicely lined up, the format ignores whitespaces and linefeeds in the data section, although it's recommended that no line is longer than 76 characters ...
>
> The P4 binary format of the same image represents each pixel with a single bit, packing 8 pixels per byte, with the first pixel as the most significant bit. Extra bits are added at the end of each row to fill a whole byte ...
>
> ***PGM example***
> The PGM and PPM formats (both ASCII and binary versions) have an additional parameter for the maximum value (numbers of grey between black and white) after the X and Y dimensions and before the actual pixel data. Black is 0 and max value is white. There is a newline character at the end of each line.
> ```
> P2
> # Shows the word "FEEP" (example from Netpbm man page on PGM)
> 24 7
> 15
> 0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
> 0  3  3  3  3  0  0  7  7  7  7  0  0 11 11 11 11  0  0 15 15 15 15  0
> 0  3  0  0  0  0  0  7  0  0  0  0  0 11  0  0  0  0  0 15  0  0 15  0
> 0  3  3  3  0  0  0  7  7  7  0  0  0 11 11 11  0  0  0 15 15 15 15  0
> 0  3  0  0  0  0  0  7  0  0  0  0  0 11  0  0  0  0  0 15  0  0  0  0
> 0  3  0  0  0  0  0  7  7  7  7  0  0 11 11 11 11  0  0 15  0  0  0  0
> 0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
> ```
> ![pgm file example](https://user-images.githubusercontent.com/19341857/204419255-f9d0e254-d8d8-4b05-9359-00d7900a2deb.png)
>

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
-->
