#include "search_algos.h"
#include <stdio.h>

/**
 * binary_search - Searches for a value in a sorted array of integers
 *                 using the Binary search algorithm.
 * @array: Pointer to the first element of the array to search in.
 * @size: Number of elements in @array.
 * @value: Value to search for.
 *
 * Return: The index where @value is located,
 *         or -1 if @value is not present in @array or if @array is NULL.
 */
int binary_search(int *array, size_t size, int value)
{
    size_t left = 0, right = size - 1, mid;
    size_t i;

    if (array == NULL)
        return -1;

    while (left <= right)
    {
        /* Calculate the middle index */
        mid = (left + right) / 2;

        /* Print the array being searched */
        printf("Searching in array: ");
        for (i = left; i <= right; i++)
        {
            printf("%d", array[i]);
            if (i < right)
                printf(", ");
            else
                printf("\n");
        }

        /* If value is found at mid, return mid */
        if (array[mid] == value)
            return mid;
        /* If value is less than mid, search the left subarray */
        else if (array[mid] > value)
            right = mid - 1;
        /* If value is greater than mid, search the right subarray */
        else
            left = mid + 1;
    }

    /* If value is not found, return -1 */
    return -1;
}

