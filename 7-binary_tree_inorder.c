#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_inorder - parse a binary tree inorder
 * @tree: root node of the binary tree
 * @func: function to call on each node
 * Return: void
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	binary_tree_inorder(tree->left, func);
	func(tree->n);
	binary_tree_inorder(tree->right, func);
}
