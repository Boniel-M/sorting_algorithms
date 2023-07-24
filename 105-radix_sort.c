#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sort.h"

/**
 * get_max - Helper function to find the maximum element in the array
 * @array: The array to be sorted
 * @size: Size of the array
 * Return: The maximum element in the array
 */
int get_max(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

/**
 * counting_sort_radix - Helper function to perform counting sort based on
 * a specific significant digit
 * @array: The array to be sorted
 * @size: Size of the array
 * @exp: The significant digit (exponent)
 */
void counting_sort_radix(int *array, size_t size, int exp)
{
	int count[10] = {0};
	size_t i;
	int *output = malloc(size * sizeof(int));

	if (output == NULL)
		return;

	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size; i > 0; i--)
	{
		output[count[(array[i - 1] / exp) % 10] - 1] = array[i - 1];
		count[(array[i - 1] / exp) % 10]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(output);
}

/**
 * radix_sort - Sorts an array of integers in ascending order using
 * the Radix sort algorithm (LSD)
 * @array: The array to be sorted
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max = get_max(array, size);
	int exp;

	if (array == NULL || size <= 1)
		return;

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		counting_sort_radix(array, size, exp);
		print_array(array, size);
	}
}

