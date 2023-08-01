#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_sibling - return the sibling of a node
 * @node: root node of the binary tree
 * Return: address if sibling exists, NULL if not
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);

	if (node->parent->left == node)
		return (node->parent->right);
	else
		return (node->parent->left);
}
