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
 * binary_trees_ancestor - find the first common ancestor of two nodes
 * @first: first node
 * @second: second node
 * Return: address of common ancestor, NULL if none found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
									 const binary_tree_t *second)
{
	size_t first_depth, second_depth;

	if (!first || !second)
		return (NULL);

	first_depth = node_depth(first);
	second_depth = node_depth(second);

	for (; first_depth >= second_depth; first_depth--)
	{
		if (second == first->parent || first->parent == second->parent)
			return (first->parent);
		first = first->parent;
	}

	for (; second_depth >= first_depth; second_depth--)
	{
		if (first == second->parent || first->parent == second->parent)
			return (second->parent);
		second = second->parent;
	}

	return (NULL);
}
