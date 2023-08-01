#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_preorder - parse a tree, left side (to leaf) first
 * @tree: root node of the binary tree
 * @func: function to call on each node
 * Return: void
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	func(tree->n);
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}
