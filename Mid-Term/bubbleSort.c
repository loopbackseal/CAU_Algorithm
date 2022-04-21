//
// Created by Young Soo Hwang on 2022/04/20.
//

#include <stdio.h>

void bubbleSort(int *a, int len)
{
	int	t;
	int	i;
	int	j;

	t = -1;
	for(i = 0; i < len; i++)
	{
		for (j = 0;  j < len - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
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
