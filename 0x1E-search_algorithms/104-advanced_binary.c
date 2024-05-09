#include <stdio.h>

/**
 * advanced_binary_recursive - Searches for a value in a sorted array of integers
 *                             using the Advanced binary search algorithm recursively.
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
int advanced_binary_recursive(int *array, size_t low, size_t high, int value)
{
    size_t mid, i;

    if (low <= high)
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
        if (array[mid] == value && (mid == low || array[mid - 1] != value))
            return mid;
        else if (array[mid] < value)
            return advanced_binary_recursive(array, mid + 1, high, value);
        else
            return advanced_binary_recursive(array, low, mid, value);
    }

    return -1;
}

/**
 * advanced_binary - Searches for a value in a sorted array of integers
 *                   using the Advanced binary search algorithm.
 * @array: Pointer to the first element of the array to search in.
 * @size: The number of elements in the array.
 * @value: The value to search for.
 *
 * Return: If the value is not present, -1.
 *         Otherwise, the index where the value is located.
 *
 * Description: Calls the recursive function advanced_binary_recursive.
 */
int advanced_binary(int *array, size_t size, int value)
{
    if (array == NULL || size == 0)
        return -1;

    return advanced_binary_recursive(array, 0, size - 1, value);
}

