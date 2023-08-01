#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_depth - get the depth of a tree
 * from the root node
 * @tree: root node of the binary tree
 * Return: unsigned integer
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return ((!!tree->parent) + binary_tree_depth(tree->parent));
}
