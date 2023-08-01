#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_is_leaf - check whether a node is the last child
 * @node: node of the binary tree
 * Return: 1 if is leaf, 0 if not
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (!node)
		return (0);

	return (node->left || node->right ? 0 : 1);
}
