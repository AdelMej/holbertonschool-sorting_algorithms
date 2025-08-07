#include "sort.h"
#include <stddef.h>
#include <stdio.h>
/* --- Function declarations --- */
static void swap(int *a, int *b);
static void quick_sort_printing(int *array, size_t size,
								int *original_array,
								size_t max_size);

/**
 * quick_sort - a function that sort an array using quick sort algorithm
 * @array: an array to sort
 * @size: th size of the array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;

	quick_sort_printing(array, size, array, size);
}

/**
 * swap - a function to swap 2 integers in an array
 * @a: the pointer to an int
 * @b: the pointer to an int
 *
 * Return: void
 */
static void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

/**
 * quick_sort_printing - sort the array while printing the full array
 * @array: the array to sort
 * @size: the size of the array to sort
 * @original_array: the original array
 * @max_size: the size of the original array
 *
 * Return: void
 */
static void quick_sort_printing(int *array,
								size_t size,
								int *original_array,
								size_t max_size)
{
	size_t pivot, i, j;

	if (array == NULL || size < 2)
		return;

	/* selecting last element as a pivot */
	pivot = size - 1;

	i = 0;
	/* partition the array with pivot */
	for (j = 0; j < pivot; j++)
	{
		if (array[j] < array[pivot])
		{
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(original_array, max_size);
			}
			i++;
		}
	}
	if (i != pivot)
	{
		swap(&array[pivot], &array[i]);
		print_array(original_array, max_size);
	}
	/*
	 * recursively sort left size
	 * start at the begining of the array
	 * ends at i (before the pivot)
	 */
	if (i > 0)
		quick_sort_printing(array, i, original_array, max_size);
	 /*
	  * recursively sort right size
	  * array + i + 1 to place the start
	  * of the array in the right parition
	  */
	if (i + 1 > 0)
		quick_sort_printing(array + i + 1, size - i - 1, original_array, max_size);
}
