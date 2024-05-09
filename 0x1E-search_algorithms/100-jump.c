#include <stdio.h>
#include <math.h>

/**
 * jump_search - Searches for a value in a sorted array of integers
 *               using the Jump search algorithm.
 * @array: Pointer to the first element of the array to search in.
 * @size: Number of elements in the array.
 * @value: Value to search for.
 *
 * Return: The index of the value if found, or -1 otherwise.
 */
int jump_search(int *array, size_t size, int value)
{
    size_t jump, prev, i;

    if (array == NULL || size == 0)
        return -1;

    jump = sqrt(size);
    prev = 0;

    printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);
    while (array[jump] <= value && jump < size)
    {
        printf("Value checked array[%lu] = [%d]\n", jump, array[jump]);
        prev = jump;
        jump += sqrt(size);
        if (jump >= size)
            break;
    }

    printf("Value found between indexes [%lu] and [%lu]\n", prev, jump);

    for (i = prev; i <= (jump < size ? jump : size - 1); i++)
    {
        printf("Value checked array[%lu] = [%d]\n", i, array[i]);
        if (array[i] == value)
            return i;
    }

    return -1;
}

