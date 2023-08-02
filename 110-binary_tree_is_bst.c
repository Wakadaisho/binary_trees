#include "binary_trees.h"
#include <stdlib.h>
#include <limits.h>

/**
 * is_bst - recursively check each node if is a bst
 * @tree: node to start checking at
 * @min: current smallest value allowed
 * @max: current largest value allowed
 * Return: 1 if is a BST, 0 if not
 */
int is_bst(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);

	return (is_bst(tree->left, min, tree->n - 1) &&
		is_bst(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_is_bst - check if a binary tree is a BST
 * @tree: binary tree
 * Return: 1 if is a BST, 0 if not
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (is_bst(tree, INT_MIN, INT_MAX));
}
