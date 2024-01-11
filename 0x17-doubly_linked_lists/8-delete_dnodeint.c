#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - deletes the node at index of a dlistint_t linked list
 * @head: pointer to head of list
 * @index: index of the node to delete
 * 
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    if (head == NULL || *head == NULL)
        return -1;

    dlistint_t *current = *head;

    // If deleting the first node
    if (index == 0)
    {
        *head = current->next;
        if (*head != NULL)
            (*head)->prev = NULL;
        free(current);
        return 1;
    }

    // Traverse to the node at the specified index
    for (unsigned int i = 0; i < index && current != NULL; i++)
    {
        current = current->next;
    }

    if (current == NULL)
        return -1; // Index out of bounds

    // Update the pointers to skip the node to be deleted
    if (current->prev != NULL)
        current->prev->next = current->next;

    if (current->next != NULL)
        current->next->prev = current->prev;

    // Free the node
    free(current);

    return 1;
}

