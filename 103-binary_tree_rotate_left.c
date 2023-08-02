#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_rotate_left - rotate a binary tree left on a node
 * @tree: node of a binary tree
 * Return: new parent node of the rotated node
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *child, *parent;

	parent = tree->parent;
	child = tree->right;

	tree->right = child->left;
	if (child->left)
		child->left->parent = tree;

	child->left = tree;
	tree->parent = child;
	child->parent = parent;

	if (!parent)
		return (child);

	if (parent->left == tree)
		parent->left = child;
	else
		parent->right = child;

	return (child);
}
