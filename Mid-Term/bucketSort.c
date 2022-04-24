#include <stdio.h>

void	insertionSort(int *arr, int n)
{
	int	i;
	int	j;
	int	key;

	j = 0;
	while (++j < n)
	{
		key = arr[j];
		i = j;
		while (--i >= 0 && arr[i] > key)
			arr[i + 1] = arr[i];
		arr[i + 1] = key;
	}
}

void	bucketSort(int arr[], int size, int n)
{
	int	buckets[n][size];
	int	counts[n];
	int tmp;
	int	idx;
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i < n)
		counts[i++] = 0;
	j = 0;
	while (j < size)
	{
		if (arr[j] == size)
			tmp = arr[j] / 20 - 1;
		else
			tmp = arr[j] / 20;
		buckets[tmp][counts[tmp]] = arr[j];
		j++;
		counts[tmp]++;
	}
	k = 0;
	idx = 0;
	while (k < n)
	{
		tmp = counts[k];
		insertionSort(buckets[k], tmp);
		while (tmp-- > 0)
		{
			arr[idx++] = buckets[k][counts[k] - 1 - tmp];
		}
		k++;
	}
}

int main()
{
	int	arr[1000];
	int i;

	i = -1;
	while (++i < 1000)
	{
		arr[i] = 1000 - i;
		printf("%d ", arr[i]);
	}
	printf("\n\n");
	bucketSort(arr, 1000, 50);
	while (--i > -1)
	{
		printf("%d ", arr[999 - i]);
	}
	printf("\n");
	return (0);
}
