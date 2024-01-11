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

    // Step 1: Check if the given index is valid
    if (idx != 0 && !*h)
        return NULL;

    // Step 2: Allocate memory for the new node
    dlistint_t *new_node = malloc(sizeof(dlistint_t));
    if (!new_node)
        return NULL;

    // Step 3: Assign data to the new node
    new_node->n = n;
    new_node->prev = NULL;
    new_node->next = NULL;

    // Step 4: Traverse to the specified index
    if (idx == 0)
    {
        new_node->next = *h;
        if (*h)
            (*h)->prev = new_node;
        *h = new_node;
        return new_node;
    }

    dlistint_t *current = *h;
    for (unsigned int i = 0; i < idx - 1 && current; i++)
    {
        current = current->next;
    }

    if (!current)
    {
        free(new_node);
        return NULL;  // Index out of bounds
    }

    // Step 5: Adjust pointers to insert the new node
    new_node->next = current->next;
    new_node->prev = current;
    if (current->next)
        current->next->prev = new_node;
    current->next = new_node;

    return new_node;
}

