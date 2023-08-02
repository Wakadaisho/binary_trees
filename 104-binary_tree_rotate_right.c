#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_rotate_right - rotate a binary tree right on a node
 * @tree: node of a binary tree
 * Return: new parent node of the rotated node
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *child, *parent;

	parent = tree->parent;
	child = tree->left;

	tree->left = child->right;
	if (child->right)
		child->right->parent = tree;

	child->right = tree;
	tree->parent = child;
	child->parent = parent;

	if (!parent)
		return (child);

	if (parent->right == tree)
		parent->right = child;
	else
		parent->left = child;

	return (child);
}
