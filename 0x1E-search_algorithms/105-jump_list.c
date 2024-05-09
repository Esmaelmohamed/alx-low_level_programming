#include <stdio.h>
#include <math.h>
#include "search_algos.h"

/**
 * jump_list - Searches for a value in a sorted list of integers
 *             using the Jump search algorithm.
 * @list: Pointer to the head of the list to search in.
 * @size: The number of nodes in the list.
 * @value: The value to search for.
 *
 * Return: If the value is not present, NULL.
 *         Otherwise, a pointer to the first node where value is located.
 *
 * Description: Prints the [sub]list being searched after each change.
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
    listint_t *current, *prev;
    size_t jump, step;

    if (list == NULL || size == 0)
        return NULL;

    jump = sqrt(size);
    current = list;
    prev = NULL;

    while (current->index < size && current->n < value)
    {
        prev = current;
        step = jump;
        while (step > 0 && current->next != NULL && current->n < value)
        {
            current = current->next;
            step--;
        }
        printf("Value checked at index [%lu] = [%d]\n", current->index, current->n);
    }

    printf("Value found between indexes [%lu] and [%lu]\n", prev->index, current->index);
    printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);

    while (prev != NULL && prev->n < value)
    {
        printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
        prev = prev->next;
    }

    if (prev == NULL || prev->n > value)
        return NULL;

    return prev;
}

