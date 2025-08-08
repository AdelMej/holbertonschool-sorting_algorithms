#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap_with_prev - swaps a node with its previous node in a doubly linked list
 * @list: pointer to the head of the list
 * @node: the node to swap backwards
 */
static void swap_with_prev(listint_t **list, listint_t *node)
{
	listint_t *prev = node->prev;

	if (!prev || !node)
		return;

	/* Detach node from current position */
	prev->next = node->next;
	if (node->next)
		node->next->prev = prev;

	/* Move node before prev */
	node->prev = prev->prev;
	node->next = prev;

	if (prev->prev)
		prev->prev->next = node;
	prev->prev = node;

	/* Update head if needed */
	if (!node->prev)
		*list = node;
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 * @list: double pointer to head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current;

	if (!list || !*list || !(*list)->next)
		return;

	current = (*list)->next;
	while (current)
	{
		listint_t *temp = current;

		while (temp->prev && temp->n < temp->prev->n)
		{
			swap_with_prev(list, temp);
			print_list(*list);
		}
		current = current->next;
	}
}
