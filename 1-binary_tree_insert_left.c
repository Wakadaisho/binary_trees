#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_insert_left - create a new node and attach it to
 * the left node of the parent
 * @parent: parent node to attach the new node to
 * @value: value of the new node
 * Return: pointer to the new node, NULL on failure
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *child_node = NULL;

	if (!parent)
		return (NULL);

	child_node = malloc(sizeof(binary_tree_t));

	if (!child_node)
		return (NULL);

	child_node->n = value;
	child_node->left = NULL;
	child_node->right = NULL;
	child_node->parent = parent;

	if (parent->left)
	{
		child_node->left = parent->left;
		child_node->left->parent = child_node;
	}

	parent->left = child_node;

	return (child_node);
}
