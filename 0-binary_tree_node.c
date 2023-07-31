#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_node - create a new node and attach it to a parent node
 * @parent: parent node to attach the new node to
 * @value: value of the new node
 * Return: pointer to the new node, NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *child_node;

	child_node = malloc(sizeof(binary_tree_t));

	if (!child_node)
		return (NULL);

	child_node->n = value;

	if (parent)
		child_node->parent = parent;

	return (child_node);
}
