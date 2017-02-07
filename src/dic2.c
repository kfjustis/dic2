/* Kynan Justis
 * kfjmbb
 * 14212450
 * 2/5/17
 * Digital Image Compression
 * Homework 2 - Problem 5
 */

#include "entropy.h"
#include "huffman.h"

int main(int argc, char *argv[]) {

	// Run huffman first

	// Create array with random character distributions
	float dist[DIST_SIZE] = {1.0};

	if (generate_dist_array(dist, DIST_SIZE) != 0) {
		printf("Failed to generate distribution array!\n");
	}

	// Print distributions	
	if (print_char_dist_array(dist) != 0) {
		printf("Failed to print character distribution!\n");
	}

	return 0;
}
