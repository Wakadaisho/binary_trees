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
 * _free - free a doubly linked list
 * @head: doubly linked list to free
 * Return: void
 */
void _free(stack_t *head)
{
	stack_t *tmp, *p = head;

	while (p)
	{
		tmp = p;
		p = p->next;
		free(tmp);
	}
}

/**
 * binary_tree_is_complete - check if a binary tree is complete
 * @tree: root node of the binary tree
 * Return: 1 if complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	stack_t *queue = NULL;
	const binary_tree_t *curr;
	int complete = 1, null_right = 0;

	if (!tree)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (complete);

	for (curr = tree; complete; curr = pop(&queue))
	{
		if (curr->left == NULL && curr->right != NULL)
		{
			complete = 0;
			continue;
		}
		if (curr->left)
		{
			if (null_right)
			{
				complete = 0;
				continue;
			}
			push(&queue, curr->left);
		}
		if (curr->right)
			push(&queue, curr->right);
		else
			null_right = 1;
		if (queue == NULL)
			return (complete);
	}
	_free(queue);
	return (complete);
}
