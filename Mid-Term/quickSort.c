#include <stdio.h>

void	swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	quickSort(int arr[], int start, int end)
{
	int	left;
	int	right;
	int	pivot;

	if (end <= start)
		return ;
	pivot = arr[start];
	left = start;
	right = end;
	while (left < right)
	{
		while (left <= end && arr[left] < pivot)
			++left;
		while (right >= start && arr[right] > pivot)
			--right;
		if (left < right)
			swap(&arr[left], &arr[right]);
	}
	swap(&arr[left], &arr[right]);
	quickSort(arr, start, right);
	quickSort(arr, right + 1, end);
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
	quickSort(arr, 0, 9);
	while (--i > -1)
	{
		printf("%d ", arr[9 - i]);
	}
	printf("\n");
	return (0);
}

