#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h> // for UCHAR_MAX

#define DIST_SIZE (UCHAR_MAX + 1)

// Generates a random distribution
int generate_dist_array(float* buffer, unsigned int size);

// Prints an entire array of floating point values
int print_dist_array(float* dist_array, unsigned int size);

#endif
