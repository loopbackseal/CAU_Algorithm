#include <stdio.h>
#include <stdlib.h>

void	conquer(int arr[], int arr1[], int arr2[], int left, int len1, int len2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < len1 && j < len2)
	{
		if (arr1[i] < arr2[j])
			arr[left] = arr1[i++];
		else
			arr[left] = arr2[j++];
		++left;
	}
	while (i < len1)
	{
		arr[left] = arr1[i];
		++i;
		++left;
	}
	while (j < len2)
	{
		arr[left] = arr2[j];
		++j;
		++left;
	}
}

void	divide(int arr[], int left, int mid, int right)
{
	int idx;
	int	len1;
	int	len2;
	int	*arr1;
	int	*arr2;

	len1 = mid - left + 1;
	len2 = right - mid;
	arr1 = malloc(sizeof(int) * len1);
	arr2 = malloc(sizeof(int) * len2);
	if (arr1 == 0 || arr2 == 0)
		return ;
	idx = -1;
	while (++idx < len1)
		arr1[idx] = arr[idx + left];
	idx = -1;
	while (++idx < len2)
		arr2[idx] = arr[idx + mid + 1];
	conquer(arr, arr1, arr2, left, len1, len2);
	free(arr1);
	free(arr2);
}

void	mergeSort(int arr[], int left, int right)
{
	int	mid;

	mid = (left + right) / 2;
	if (right - left > 0)
	{
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		divide(arr, left, mid, right);
	}
}

int main()
{
	int	arr[10];
	int i;

	i = -1;
	while (++i < 10)
	{
		arr[i] = 10 - i;
		printf("%d ", arr[i]);
	}
	printf("\n");
	mergeSort(arr, 0, 9);
	while (--i > -1)
	{
		printf("%d ", arr[9 - i]);
	}
	printf("\n");
	return (0);
}

