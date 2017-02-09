#ifndef TREE_H
#define TREE_H

#include <stdlib.h>

typedef struct node {
  char data;
  float px;
  struct node *left;
  struct node *right;
}node_t;


node_t* create_node(char data, float px);
void destroy_tree(node_t* root);

#endif
