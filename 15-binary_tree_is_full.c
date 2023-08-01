#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_is_full - check if there are no hanging branches
 * @tree: root node of the binary tree
 * Return: 1 if no hanging branches, 0 otherwise
 */
size_t binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	if (!tree->left == !tree->right)
		return (binary_tree_is_full(tree->left) ==
				binary_tree_is_full(tree->right));

	return (0);
}
