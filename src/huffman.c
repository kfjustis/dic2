#include <huffman.h>

int generate_dist_array(float* buffer, unsigned int size) {
	if (!buffer || size == 0) {
		return -1;
	}

	srand(time(NULL));

	int i = 0;
	float random = 0.0, sum = 0.0;
	for (i = 0; i < size; i++) {
		random = ((float)rand()/(float)(RAND_MAX)) * 1.0;
		buffer[i] = random;
		sum += random;
	}

	for (i = 0; i < size; i++) {
		buffer[i] = buffer[i] / sum;
	}

	return 0;
}
