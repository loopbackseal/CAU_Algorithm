//
// Created by Young Soo Hwang on 2022/04/20.
//

#include <stdio.h>

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
	bubbleSort(arr, 10);
	while (--i > -1)
	{
		printf("%d ", arr[9 - i]);
	}
	printf("\n");
	return (0);
}
