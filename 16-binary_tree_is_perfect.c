#include "binary_trees.h"
#include <stdlib.h>

/**
 * node_depth - get the depth of a node
 * from the root node
 * @tree: root node of the binary tree
 * Return: unsigned integer
 */
size_t node_depth(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return ((!!tree->parent) + node_depth(tree->parent));
}

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
 * is_perfect - comparatively check if branches are equal
 *				and if leaf node depth matches tree height
 * @node: the node under investigation
 * @tree_height: the height of the entire tree
 * Return: 1 if perfect, 0 otherwise
 */
size_t is_perfect(const binary_tree_t *node, size_t tree_height)
{
	if (!node)
		return (0);

	/* Leaf node: check if corresponds to leaf depth tree height*/
	if (node->left == NULL && node->right == NULL)
		return (node_depth(node) == tree_height);

	return (is_perfect(node->left, tree_height) &&
			is_perfect(node->right, tree_height));
}

/**
 * binary_tree_is_perfect - check if there are no hanging branches
 * and all leaves are of the same level
 * @tree: root node of the binary tree
 * Return: 1 if no hanging branches, 0 otherwise
 */
size_t binary_tree_is_perfect(const binary_tree_t *tree)
{

	return (is_perfect(tree, node_height(tree)));
}
