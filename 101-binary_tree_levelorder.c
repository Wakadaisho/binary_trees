#include "binary_trees.h"
#include <stdlib.h>

/**
 * push - adds node to a queue
 * @head: queue data structure
 * @node: node pointer to add to queue
 * Return: stack pointer
 */
stack_t *push(stack_t **head, binary_tree_t *node)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	stack_t *h = *head;

	if (new_node == NULL)
		return (NULL);

	new_node->node = node;
	new_node->next = NULL;

	while (h && h->next)
		h = h->next;

	if (h)
	{
		h->next = new_node;
		new_node->prev = h;
	}
	else
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	return (new_node);

}

/**
 * pop - remove node from a queue and return it
 * @head: queue data structure
 * Return: binary tree pointer
 */
binary_tree_t *pop(stack_t **head)
{
	stack_t *top = *head;
	binary_tree_t *pop_value;

	if (top)
		pop_value = top->node;
	else
		return (NULL);

	top->prev = NULL;
	*head = top->next;
	free(top);
	return (pop_value);
}

/**
 * binary_tree_levelorder - parse a binary tree using level order
 * @tree: root node of the binary tree
 * @func: function to call on each node
 * Return: void
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	stack_t *queue = NULL;
	const binary_tree_t *curr;

	if (!tree || !func)
		return;

	for (curr = tree;; curr = pop(&queue))
	{
		func(curr->n);
		if (curr->left)
			push(&queue, curr->left);
		if (curr->right)
			push(&queue, curr->right);
		if (queue == NULL)
			return;
	}
}
