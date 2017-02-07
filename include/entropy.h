#ifndef ENTROPY_H
#define ENTROPY_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h> // for UCHAR_MAX
#include <ctype.h>  // for isalpha()

// Computes the character frequency distribution from a given file
// and stores the values in the passed array
// param: filename - the filepath char string for the file to process
// param: probs - an array sizeof (UCHAR_MAX + 1) init'd to all 1s
// return: -1 on error, 0 on success
int compute_char_dist_from_file(char* filename, float* probs);

// Prints the distribution of characters stored in given array
// param: probs - UCHAR_MAX+1 sized array with valid dist values
// return: -1 on error, 0 on success
int print_char_dist_array(float* probs);

#endif
