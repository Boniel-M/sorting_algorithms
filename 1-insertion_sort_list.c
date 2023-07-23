#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list in ascending order using
 *                        Insertion sort algorithm
 *
 * @list: Double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *sorted, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		sorted = current->prev;
		temp = current;

		while (sorted != NULL && sorted->n > temp->n)
		{
			if (sorted->prev != NULL)
				sorted->prev->next = temp;

			temp->prev = sorted->prev;
			sorted->prev = temp;
			sorted->next = temp->next;

			if (temp->next != NULL)
				temp->next->prev = sorted;

			temp->next = sorted;
			sorted = temp->prev;
			if (sorted == NULL)
				*list = temp;
			print_list(*list);
		}
		current = current->next;
	}
}
