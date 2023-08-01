#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_nodes - count the nodes of a tree with at least one child
 * to its furthest leaf
 * @tree: root node of the binary tree
 * Return: unsigned integer
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return ((tree->left || tree->right) +
			binary_tree_nodes(tree->left) +
			binary_tree_nodes(tree->right));
}
