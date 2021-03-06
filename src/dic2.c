/* Kynan Justis
 * kfjmbb
 * 14212450
 * 2/5/17
 * Digital Image Compression
 * Homework 2 - Problem 5
 */

#include "entropy.h"
#include "huffman.h"
#include "tree.h"

int float_comparator (const void* a, const void* b) {
	float f1 = *(const float*) a;
	float f2 = *(const float*) b;
	return (f1 > f2) - (f1 < f2);
}

int node_comparator (const void* a, const void* b) {
	node_t n1 = *(const node_t*) a;
	node_t n2 = *(const node_t*) b;
	return (n1.px > n2.px) - (n1.px < n2.px);
}

int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("Invalid input!\nUsage: %s <input file>\n", argv[0]);
		return -1;
	}

	// run huffman first

	// create array with random character distributions
	float dist[DIST_SIZE] = {1.0};
	int i = 0;
	for (i = 0; i < DIST_SIZE; i++) {
		dist[i] = 1.0;
	}

	if (generate_dist_array(dist, DIST_SIZE) != 0) {
		printf("Failed to generate distribution array!\n");
		return -1;
	}

	if (print_dist_array(dist, DIST_SIZE) != 0) {
		printf("Invalid array or size; could not print!\n");
		return -1;
	}

	// generate node array from dist array
	node_t* nodes = calloc(DIST_SIZE, sizeof(node_t));
	for (i = 0; i < DIST_SIZE; i++) {
		nodes[i].data = i;
		nodes[i].px = dist[i];
	}

	// print from node array
	printf("\n");
	printf("--GENERATED NODE ARRAY--\n");
	for (i = 0; i < DIST_SIZE; i++) {
		printf("i: %d :: c: %c :: px: %f\n", i, nodes[i].data, nodes[i].px);
	}

	// qsort and print random distributions
	qsort(nodes, DIST_SIZE, sizeof(node_t), node_comparator);

	// print after sort
	printf("\n--AFTER SORT--\n");
	for (i = 0; i < DIST_SIZE; i++) {
		printf("i: %d :: c: %c :: px: %f\n", i, nodes[i].data, nodes[i].px);
	}

	// generate huffman tree from sorted array here
	float firstSum = 0;
	node_t* root;
	i = 0;

	firstSum = nodes[i].px + nodes[i+1].px;
	root = create_node(0, firstSum);

	/* set used float values in node array to -1 for sorting purposes
	 * and override one of the consumed nodes so super character gets
	 * placed back in the array */
	nodes[i].px = -1.0;
	memcpy(&nodes[i+1], &root, sizeof(node_t));
	
	// sort again for loop
	qsort(nodes, DIST_SIZE, sizeof(node_t), node_comparator);

	// print before loop
	printf("\n--BEFORE LOOP--\n");
	for (i = 0; i < DIST_SIZE; i++) {
		printf("i: %d :: c: %c :: px: %f\n", i, nodes[i].data, nodes[i].px);
	}

	float tempSum = 0;
	node_t* tempNode;
	for (i = 0; i < DIST_SIZE-1; i++) {
		if (nodes[i].px != -1.0) {
			tempSum = nodes[i].px + nodes[i+1].px;
			tempNode = create_node(0, tempSum);

			// copy joined nodes into children of root
			tempNode->left = root;
			tempNode->right = NULL;
			//memcpy(tempNode->left, &nodes[i], sizeof(node_t));
			//memcpy(tempNode->right, &nodes[i+1], sizeof(node_t));
			root = tempNode;

			nodes[i].px = -1.0;
			memcpy(&nodes[i+1], &root, sizeof(node_t));

			// sort again for loop
			qsort(nodes, DIST_SIZE, sizeof(node_t), node_comparator);
		}
	}

	// print after loop
	printf("\n--AFTER LOOP--\n");
	for (i = 0; i < DIST_SIZE; i++) {
		printf("i: %d :: c: %c :: px: %f\n", i, nodes[i].data, nodes[i].px);
	}

	printf("tnode: %c:: %f\n", tempNode->data, tempNode->px);

	// print tree
	inorder_print_tree(root);

	///////////////////////////////////////////////////////////////////

	// Create distribution array from file
	float file_dist[DIST_SIZE] = {0};
	for (i = 0; i < DIST_SIZE; i++) { // Init probabilities to 1.0
		file_dist[i] = 1.0;
	}

	if (compute_char_dist_from_file(argv[1], file_dist) != 0) {
		printf("Failed to make distribution from file!\n");
		return -1;
	}	

	// qsort and print file distributions
	qsort(file_dist, DIST_SIZE, sizeof(float), float_comparator);

	printf("\n");
	printf("--FILE DISTRIBUTIONS--\n");
	if (print_char_dist_array(file_dist) != 0) {
		printf("Failed to print sorted char dist from file!\n");
		return -1;
	}
	
	return 0;
}
