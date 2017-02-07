#include "entropy.h"

int compute_char_dist_from_file(char* filename, float* probs) {
	if (filename == NULL || probs == NULL) {
		return -1;
	}

	int ch = 0, i = 0, j = 0;

	/* Array to store character frequencies
	 * (init to 1 to make Huffman nicer) */
	unsigned long long counts[UCHAR_MAX+1] = {1};

	// Stores total sum of characters
	unsigned long totalChars = 0;

	// Open file
	FILE *file = fopen(filename, "r");
	if (file == NULL) {
		return -1;
	}

	/* Read chars in from file and track frequencies
	 * and total character count */
	while ((ch = fgetc(file)) != EOF) {
		counts[ch]++;
		totalChars++;
	}

	// Calculate probabilities
	for (i = 0; i <= UCHAR_MAX; i++) {
		probs[j] = (float)(counts[j]) / (float)totalChars;
	}

	fclose(file);
	return 0;
}

int print_char_dist_array(float* probs) {
	if (probs == NULL) {
		return -1;
	}

	int i = 0;
	for (i = 0; i <= UCHAR_MAX; i++) {
		//if (isalpha(i) && i >= 32 && i <= 126) {
			printf("%d :: %f\n", i, probs[i]);
		//}
	}

	return 0;
}
