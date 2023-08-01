#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_delete - delete an entire binary tree
 * @tree: node of the binary tree, typically root node
 * Return: void
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL)
		return;

	binary_tree_delete(tree->left);
	binary_tree_delete(tree->right);
	free(tree);
}
