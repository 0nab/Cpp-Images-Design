<p align="center">
  <img alt="Image example" src="https://twemoji.maxcdn.com/v/latest/svg/1f60e.svg" width="200px">
</p>

# A C++ class for images

Created as a part of
our *C++ Programming* course assignment.

<br>

```bash
# tree
├── main.cpp     # main driver
├── Image.cpp    # definitions for the class and helper functions
└── Image.h      # declarations for the class and helper functions
```

<br>

***Core Design***
- [ ] All bits are stored as a single-dimension array with `vector<unsigned int>`.
- [ ] Internally, we keep track of the image structure using
three variables: `nl` number of lines, `ns` number of samples,
and `nb` number of bands.
- [ ] Support for 8-bit images, but at the same time,
all of our variables are future proof for 16-bit and 32-bit images as well.

<br>

***Constructor Design***
- [ ] Constructor by reading `.png` files.
- [ ] Constructor by a constant value for testing purposes.
- [ ] Constructor by a wedge of pixel values for testing purposes.
- [ ] Copy / move operator overloads.
- [ ] Destructors to prevent memory leaks.

<br>

***Helper Function Design***
```c++
// Image.h
getSubset(Image image, int top, int left, int right, int bottom);
setBrightness(Image image, int gain, int bias);
```
- [ ] A function for subsetting an image -- i.e.
extracting a subset of the image.
- [ ] A function for adjusting brightness by scaling and offsetting
-- i.e. gain and bias.
- [ ] A function for extracting a smoothed, downsampled subset.

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

