#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_uncle - return the uncle of a node
 * @node: root node of the binary tree
 * Return: address if uncle exists, NULL if not
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *parent, *grandparent;

	if (!node || !node->parent || !node->parent->parent)
		return (NULL);

	parent = node->parent;
	grandparent = node->parent->parent;

	if (grandparent->left == parent)
		return (grandparent->right);
	else
		return (grandparent->left);
}
