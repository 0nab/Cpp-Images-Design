### For handling bytes, we might want to use

std:uint8_t

### What is a wedge?

It's the same as a gradient.
The starting point should have the value of 0,
and the end point should have the value of 255.
In this case, the max value happens to be 255 because
all data happen to be stored as 8 bits. 2^8 = 256

### No need to implement smooth.. function

For HW7 Part 2, we don't need to implement this function.
However, we need to implement it if we're doing it as our
final project.

This can be implemented by finding the average of all points
around that particular pixel.

Likewise, constructor for reading a file is not necessary
for HW7 Part 2. It's required only for final project.
