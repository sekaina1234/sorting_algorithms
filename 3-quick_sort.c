#include "sort.h"
/**
 * partition - Lomuto partition scheme for Quick sort
 * @array: The array to be sorted
 * @low: Starting index of the partition to be sorted
 * @high: Ending index of the partition to be sorted
 * @size: The size of the array
 *
 * Return: Index of the pivot after partitioning
 */
int partition(int *array, int low, int high, size_t size)
{
int pivot = array[high];
int i = low - 1, j, temp;
for (j = low; j <= high - 1; j++)
{
if (array[j] <= pivot)
{
i++;
if (i != j)
{
temp = array[i];
array[i] = array[j];
array[j] = temp;
print_array(array, size);
}
}
}
if ((i + 1) != high)
{
temp = array[i + 1];
array[i + 1] = array[high];
array[high] = temp;
print_array(array, size);
}
return (i + 1);
}
/**
 * quicksort - Recursive function to perform Quick sort
 * @array: The array to be sorted
 * @low: Starting index of the partition to be sorted
 * @high: Ending index of the partition to be sorted
 * @size: The size of the array
 */
void quicksort(int *array, int low, int high, size_t size)
{
int pi;
if (low < high)
{
pi = partition(array, low, high, size);
quicksort(array, low, pi - 1, size);
quicksort(array, pi + 1, high, size);
}
}
/**
 * quick_sort - Sorts an array of integers in ascending order
 *              using the Quick sort algorithm (Lomuto partition scheme).
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;
quicksort(array, 0, size - 1, size);
}
