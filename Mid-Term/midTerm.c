//
// Created by Young Soo Hwang on 2022/04/25.
//

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

long long timestamp()
{
	long long milliseconds;

	struct timeval te;
	gettimeofday(&te, NULL); // get current time
	milliseconds = te.tv_sec*1000LL + te.tv_usec/1000; // calculate milliseconds
	//printf("milliseconds: %lld\n", milliseconds);
	return milliseconds;
}

void bubbleSort(int *arr, int n)
{
	int	t;
	int	i;
	int	j;

	t = -1;
	for(i = 0; i < n; i++)
	{
		for (j = 0;  j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
			}
		}
	}
}

void insertionSort(int *arr, int n)
{
	int i;
	int j;
	int key;

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

int	tenPow(int count)
{
	int	i = 0;
	int	result = 10;
	while (i++ < count)
		result *= 10;
	return (result);
}

void	countingSort(int array[], int size, int pow)
{
	int	output[10000];
	int	max = array[0] % tenPow(pow);
	int tmp;
	for (int i = 1; i < size; i++)
	{
		tmp = array[i] % tenPow(pow);
		if (tmp > max)
			max = tmp;
	}
	int count[10000];
	for (int i = 0; i <= max; ++i)
	{
		count[i] = 0;
	}
	for (int i = 0; i < size; i++)
	{
		tmp = array[i] % tenPow(pow);
		count[tmp]++;
	}
	for (int i = 1; i <= max; i++)
	{
		count[i] += count[i - 1];
	}
	for (int i = size - 1; i >= 0; i--)
	{
		tmp = array[i] % tenPow(pow);
		output[count[tmp] - 1] = array[i];
		count[tmp]--;
	}
	for (int i = 0; i < size; i++)
	{
		array[i] = output[i];
	}
}

void	radixSort(int arr[], int size, int count)
{
	int	i;

	i = -1;
	while (++i <= count)
	{
		countingSort(arr, size, i);
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
	bubbleSort(arr, 1000);
	while (--i > -1)
	{
		printf("%d ", arr[999 - i]);
	}
	i = -1;
	while (++i < 1000)
	{
		arr[i] = 1000 - i;
	}
	printf("\n\n");
	insertionSort(arr, 1000);
	while (--i > -1)
	{
		printf("%d ", arr[999 - i]);
	}
	i = -1;
	while (++i < 1000)
	{
		arr[i] = 1000 - i;
	}
	printf("\n\n");
	mergeSort(arr, 0, 999);
	while (--i > -1)
	{
		printf("%d ", arr[999 - i]);
	}
	i = -1;
	while (++i < 1000)
	{
		arr[i] = 1000 - i;
	}
	printf("\n\n");
	quickSort(arr, 0, 999);
	i = -1;
	while (++i < 1000)
	{
		arr[i] = 1000 - i;
	}
	printf("\n\n");
	radixSort(arr, 1000, 3);
	i = -1;
	while (++i < 1000)
	{
		arr[i] = 1000 - i;
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
