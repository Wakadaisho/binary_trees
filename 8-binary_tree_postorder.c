#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_postorder - parse a binary tree postorder
 * @tree: root node of the binary tree
 * @func: function to call on each node
 * Return: void
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
	func(tree->n);
}
