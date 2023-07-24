#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap - Swaps two integers.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * hoare_partition - Partitions the array using the Hoare scheme.
 * @array: Pointer to the array.
 * @low: Starting index of the partition.
 * @high: Ending index of the partition.
 * @size: Size of the array.
 *
 * Return: Index of the partition.
 */
int hoare_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j = high + 1;

	while (1)
	{
		do {
			i++;
		} while (i < high && array[i] < pivot);

		do {
			j--;
		} while (j > low && array[j] > pivot);

		if (i >= j)
			return (j);

		swap(&array[i], &array[j]);
		print_array(array, size);
	}
}

/**
 * quick_sort_hoare_recursive - Recursively sorts the array using Quick sort.
 * @array: Pointer to the array.
 * @low: Starting index of the partition.
 * @high: Ending index of the partition.
 * @size: Size of the array.
 */
void quick_sort_hoare_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot = hoare_partition(array, low, high, size);

		if (pivot > 0)
			quick_sort_hoare_recursive(array, low, pivot - 1, size);

		quick_sort_hoare_recursive(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort_hoare - Sorts an array of integers using Quick sort algorithm
 *                    with Hoare partition scheme.
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_hoare_recursive(array, 0, size - 1, size);
}
