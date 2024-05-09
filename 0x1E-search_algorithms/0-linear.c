#include <stdio.h>
#include "search_algos.h"

/**
 * linear_search - Searches for a value in an array of integers
 *                 using the Linear search algorithm.
 * @array: Pointer to the first element of the array to search in.
 * @size: Number of elements in the array.
 * @value: Value to search for.
 *
 * Return: The index of the value if found, or -1 otherwise.
 *
 * Description: This function iterates through the array linearly,
 * comparing each element with the target value until a match is found
 * or the end of the array is reached.
 * It prints each value checked during the search.
 */
int linear_search(int *array, size_t size, int value)
{
    int i;

    /* Check if the array is NULL */
    if (array == NULL)
        return -1;

    /* Loop through the array */
    for (i = 0; i < (int)size; i++)
    {
        printf("Value checked array[%u] = [%d]\n", i, array[i]);
        /* If the value is found, return the index */
        if (value == array[i])
            return i;
    }

    /* If the value is not found, return -1 */
    return -1;
}

