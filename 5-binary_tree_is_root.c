#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_is_root - check whether a node is the root
 * @node: node of the binary tree
 * Return: 1 if root node, 0 if not
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (!node)
		return (0);

	return (node->parent ? 0 : 1);
}
