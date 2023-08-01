#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_size - get the size of a tree
 * to its furthest leaf
 * @tree: root node of the binary tree
 * Return: unsigned integer
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}
