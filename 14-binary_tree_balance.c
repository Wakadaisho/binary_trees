#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_balance - get the balance value of a binary tree
 * @tree: root node of the binary tree
 * Return: unsigned integer
 */
size_t binary_tree_balance(const binary_tree_t *tree)
{
	size_t height_left, height_right;

	if (!tree)
		return (0);

	height_left = !!tree->left + binary_tree_balance(tree->left);
	height_right = !!tree->right + binary_tree_balance(tree->right);

	return (height_left - height_right);
}
