#include "sort.h"

/**
 * lomuto_partition - Partitions the array using the Lomuto scheme
 *
 * @array: The array to be sorted
 * @low: The lower index of the partition
 * @high: The higher index of the partition
 *
 * Return: The index of the pivot after partitioning
 */
int lomuto_partition(int *array, int low, int high)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				int temp = array[i];

				array[i] = array[j];
				array[j] = temp;
				print_array(array, high + 1);
			}
		}
	}

	if ((i + 1) != high)
	{
		int temp = array[i + 1];

		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, high + 1);
	}
	return (i + 1);
}

/**
 * quick_sort_recursive - Recursive function to implement Quick sort
 *
 * @array: The array to be sorted
 * @low: The lower index of the partition
 * @high: The higher index of the partition
 */
void quick_sort_recursive(int *array, int low, int high)
{
	int pivot;

	if (low < high)
	{
		pivot = lomuto_partition(array, low, high);
		quick_sort_recursive(array, low, pivot - 1);
		quick_sort_recursive(array, pivot + 1, high);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick sort
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1);
}

