#include <stdio.h>

/**
 * min - Returns the minimum of two integers
 * @a: First integer
 * @b: Second integer
 *
 * Return: The minimum of a and b
 */
size_t min(size_t a, size_t b)
{
    return (a < b ? a : b);
}

/**
 * binary_search - Searches for a value in a sorted array of integers
 *                 using the Binary search algorithm.
 * @array: Pointer to the first element of the array to search in.
 * @low: The starting index of the array to search.
 * @high: The ending index of the array to search.
 * @value: The value to search for.
 *
 * Return: If the value is not present, -1.
 *         Otherwise, the index where the value is located.
 *
 * Description: Prints the [sub]array being searched after each change.
 */
int binary_search(int *array, size_t low, size_t high, int value)
{
    size_t i;
    size_t mid;

    while (low <= high)
    {
        printf("Searching in array: ");
        for (i = low; i <= high; i++)
        {
            printf("%d", array[i]);
            if (i < high)
                printf(", ");
        }
        printf("\n");

        mid = (low + high) / 2;
        if (array[mid] == value)
            return mid;
        else if (array[mid] < value)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

/**
 * exponential_search - Searches for a value in a sorted array of integers
 *                      using the Exponential search algorithm.
 * @array: Pointer to the first element of the array to search in.
 * @size: The number of elements in the array.
 * @value: The value to search for.
 *
 * Return: If the value is not present, -1.
 *         Otherwise, the index where the value is located.
 *
 * Description: Prints the value checked array after each comparison.
 */
int exponential_search(int *array, size_t size, int value)
{
    size_t bound = 1;

    if (array == NULL || size == 0)
        return -1;

    while (bound < size && array[bound] < value)
    {
        printf("Value checked array[%lu] = [%d]\n", bound, array[bound]);
        bound *= 2;
    }

    printf("Value found between indexes [%lu] and [%lu]\n", bound / 2, min(bound, size - 1));

    return binary_search(array, bound / 2, min(bound, size - 1), value);
}

