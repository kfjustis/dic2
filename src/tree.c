#include "tree.h"

node_t* create_node(char data, float px) {
	if (px < 0.0) {
		return NULL;
	}

	node_t* newNode = malloc(sizeof(node_t));
	newNode->data = data;
	newNode->px = px;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}

void destroy_tree(node_t* root) {
	if (root) {
		destroy_tree(root->left);
		destroy_tree(root->right);
		free(root);
	}
}

void inorder_print_tree(node_t* root) {
	if (!root) {
		return;
	}

	inorder_print_tree(root->left);
	//printf("%c :: %f -> ", root->data, root->px);
	inorder_print_tree(root->right);
}
