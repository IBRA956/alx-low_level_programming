#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a new node at a given position
 * @h: pointer to head of list
 * @idx: index of the list where the new node should be added
 * @n: data of the new node
 * 
 * Return: the address of the new node, or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
    if (!h)  // Check if the double pointer to the head is NULL
        return NULL;

    // Allocate memory for the new node
    dlistint_t *new_node = malloc(sizeof(dlistint_t));
    if (!new_node)
        return NULL;

    // Assign data to the new node
    new_node->n = n;
    new_node->prev = NULL;
    new_node->next = NULL;

    // If the list is empty and index is not 0, return NULL
    if (!*h && idx != 0)
    {
        free(new_node);
        return NULL;
    }

    // If inserting at the beginning
    if (idx == 0)
    {
        new_node->next = *h;
        if (*h)
            (*h)->prev = new_node;
        *h = new_node;
        return new_node;
    }

    // Traverse to the specified index
    dlistint_t *current = *h;
    for (unsigned int i = 0; i < idx - 1 && current; i++)
    {
        current = current->next;
    }

    // If index is out of bounds or current node is NULL
    if (!current)
    {
        free(new_node);
        return NULL;
    }

    // Adjust pointers to insert the new node
    new_node->next = current->next;
    new_node->prev = current;
    if (current->next)
        current->next->prev = new_node;
    current->next = new_node;

    return new_node;
}

