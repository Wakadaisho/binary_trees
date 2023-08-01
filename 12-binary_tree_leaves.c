#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_leaves - count the leaves of a tree
 * to its furthest leaf
 * @tree: root node of the binary tree
 * Return: unsigned integer
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (!(tree->left || tree->right) +
			binary_tree_leaves(tree->left) +
			binary_tree_leaves(tree->right));
}
