#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * navigate - navigate a binary tree based on a path array
 * @node: node to start from
 * @path: array of 1 for right, 0 for left, -1 for stop
 * Return: pointer to the new node, NULL on non-exhaustive path
 */
binary_tree_t *navigate(binary_tree_t *node, char *path)
{
	for (; node && *path; path++)
		node = *path == '1' ? node->right : node->left;

	return (node);
}
