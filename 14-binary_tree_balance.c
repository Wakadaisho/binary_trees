#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * node_height - get the height of a tree
 * to its furthest leaf
 * @tree: root node of the binary tree
 * Return: void
 */
size_t node_height(const binary_tree_t *tree)
{
	size_t height_left, height_right;

	if (!tree || (!(tree->left || tree->right)))
		return (0);

	height_left = node_height(tree->left);
	height_right = node_height(tree->right);

	return (height_right > height_left ? height_right + 1 : height_left + 1);
}

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

	height_left = !!tree->left + node_height(tree->left);
	height_right = !!tree->right + node_height(tree->right);

	return (height_left - height_right);
}
