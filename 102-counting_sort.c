#include "sort.h"
/**
 * counting_sort - Sorts an array of integers in ascending order using
 * the Counting sort algorithm
 * @array: The array to be sorted
 * @size: Size of the array
 */
void counting_sort(int *array, size_t size)
{
	int max = array[0];
	size_t i, j;
	int *counting_array;
	int *sorted_array;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	counting_array = malloc((max + 1) * sizeof(int));

	if (counting_array == NULL)
		return;

	for (i = 0; i <= (size_t)max; i++)
		counting_array[i] = 0;
	for (i = 0; i < size; i++)
		counting_array[array[i]]++;
	for (i = 1; i <= (size_t)max; i++)
		counting_array[i] += counting_array[i - 1];
	printf("%d", counting_array[0]);
	for (i = 1; i <= (size_t)max; i++)
		printf(", %d", counting_array[i]);
	printf("\n");
	sorted_array = malloc(size * sizeof(int));
	if (sorted_array == NULL)
	{
		free(counting_array);
		return;
	}
	for (j = 0; j < size; j++)
	{
		sorted_array[counting_array[array[j]] - 1] = array[j];
		counting_array[array[j]]--;
	}
	for (i = 0; i < size; i++)
		array[i] = sorted_array[i];
	free(sorted_array);
	free(counting_array);
}
