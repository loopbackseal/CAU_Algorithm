//
// Created by Young Soo Hwang on 2022/04/21.
//

#include <stdio.h>

void insertionSort(int *arr, int n) {
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
	insertionSort(arr, 10);
	while (--i > -1)
	{
		printf("%d ", arr[9 - i]);
	}
	printf("\n");
	return (0);
}

