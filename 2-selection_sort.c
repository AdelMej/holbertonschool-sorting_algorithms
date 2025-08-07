#include "sort.h"
#include <stddef.h>

void swap(int *a, int *b);

void selection_sort(int *array, size_t size)
{
	size_t i, j, swap_idx;

	if (array == NULL || size <= 1)
		return;

	for (i = 0; i < size; i++)
	{
		swap_idx = i;
		for (j = i + 1; j < size; j++)
		{
			if(array[swap_idx] > array[j])
				swap_idx = j; /* change stored index */
		}
		if (i != swap_idx) /* if we need to swap */
		{
			swap(&array[i], &array[swap_idx]);
			print_array(array, size);
		}
	}
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
