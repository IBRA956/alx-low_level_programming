#include "lists.h"
#include <stdlib.h>

/**
 * insert_dnodeint_at_index - inserts a new node at a given position
 * @h: pointer to head of list
 * @idx: index of the list where the new node should be added
 * @n: data of the new node
 * 
 * Return:  the address of the new node, or NULL if it failed
 */

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
    if (h == NULL)
        return NULL;

    dlistint_t *new_node = malloc(sizeof(dlistint_t));
    if (new_node == NULL)
        return NULL;

    new_node->n = n;
    new_node->prev = NULL;
    new_node->next = NULL;

    if (idx == 0) {
        // Insert at the beginning
        new_node->next = *h;
        if (*h != NULL)
            (*h)->prev = new_node;
        *h = new_node;
    } else {
        dlistint_t *current = *h;
        for (unsigned int i = 0; i < idx - 1 && current != NULL; i++) {
            current = current->next;
        }

        if (current == NULL && idx != 0) {
            free(new_node);
            return NULL; // Index out of bounds
        }

        // Insert in the middle or at the end
        new_node->prev = current;
        new_node->next = (current != NULL) ? current->next : NULL;
        if (current != NULL && current->next != NULL)
            current->next->prev = new_node;
        if (current != NULL)
            current->next = new_node;
    }

    return new_node;
}

