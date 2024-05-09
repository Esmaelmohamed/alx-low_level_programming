#include <stdio.h>
#include <math.h>
#include "search_algos.h"

/**
 * linear_skip - Searches for a value in a sorted skip list of integers
 *               using the Jump search algorithm.
 * @list: Pointer to the head of the skip list to search in.
 * @value: The value to search for.
 *
 * Return: If the value is not present, NULL.
 *         Otherwise, a pointer to the first node where value is located.
 *
 * Description: Prints the [sub]list being searched after each change.
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
    skiplist_t *current, *prev;

    if (list == NULL)
        return NULL;

    current = list;
    while (current)
    {
        printf("Value checked at index [%lu] = [%d]\n", current->index, current->n);
        if (current->n >= value)
            break;
        prev = current;
        if (current->express == NULL)
        {
            while (current->next != NULL)
                current = current->next;
            break;
        }
        current = current->express;
    }

    printf("Value found between indexes [%lu] and [%lu]\n", prev->index, current->index);
    while (prev != NULL && prev->index <= current->index)
    {
        printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
        if (prev->n == value)
            return prev;
        prev = prev->next;
    }

    return NULL;
}

