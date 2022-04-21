//
// Created by Young Soo Hwang on 2022/04/21.
//

#include <stdio.h>

void insertionSort(int *a, int len) {
	int i;
	int j;
	int key;

	j = 0;
	while (++j < len)
	{
		key = a[j];
		i = j;
		while (--i >= 0 && a[i] > key)
			a[i + 1] = a[i];
		a[i + 1] = key;
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

