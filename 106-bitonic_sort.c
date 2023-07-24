#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge - Helper function to merge two subarrays
 * @array: The array to be sorted
 * @low: Lower index of the subarray
 * @count: Number of elements to be merged
 * @dir: Direction (1 for ascending, 0 for descending)
 */
void merge(int *array, size_t low, size_t count, int dir)
{
	if (count > 1)
	{
		size_t k = count / 2;
		size_t i;

		for (i = low; i < low + k; i++)
		{
			if (dir == (array[i] > array[i + k]))
			{
				int temp = array[i];

				array[i] = array[i + k];
				array[i + k] = temp;
			}
		}

		merge(array, low, k, dir);
		merge(array, low + k, k, dir);
	}
}

/**
 * bitonic_sort_recursive - Recursive function to sort a bitonic sequence
 * @array: The array to be sorted
 * @low: Lower index of the bitonic sequence
 * @count: Number of elements in the bitonic sequence
 * @dir: Direction (1 for ascending, 0 for descending)
 */
void bitonic_sort_recursive(int *array, size_t low, size_t count, int dir)
{
	if (count > 1)
	{
		size_t k = count / 2;

		printf("Merging [%lu/%lu] (%s):\n", count, count, dir ? "UP" : "DOWN");
		print_array(array + low, count);

		bitonic_sort_recursive(array, low, k, 1);
		bitonic_sort_recursive(array, low + k, k, 0);
		merge(array, low, count, dir);

		printf("Result [%lu/%lu] (%s):\n", count, count, dir ? "UP" : "DOWN");
		print_array(array + low, count);
	}
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order using
 * the Bitonic sort algorithm
 * @array: The array to be sorted
 * @size: Size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_sort_recursive(array, 0, size, 1);
}

