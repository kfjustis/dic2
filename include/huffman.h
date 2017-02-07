#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <time.h>
#include <stdlib.h>
#include <limits.h> // for UCHAR_MAX

#define DIST_SIZE UCHAR_MAX + 1

// Generates a random distribution
int generate_dist_array(float* buffer, unsigned int size);

#endif
