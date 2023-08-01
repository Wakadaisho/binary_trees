#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_height - get the height of a tree
 * to its furthest leaf
 * @tree: root node of the binary tree
 * Return: void
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_left, height_right;

	if (!tree || (!(tree->left || tree->right)))
		return (0);

	height_left = binary_tree_height(tree->left);
	height_right = binary_tree_height(tree->right);

	return (height_right > height_left ? height_right + 1 : height_left + 1);
}
