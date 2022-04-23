#include <stdio.h>

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
		int idx = 0;
		printf("%d try\n", i);
		while (idx < size)
		{
			printf("%d ", arr[idx]);
			idx++;
		}
		printf("\n\n");
	}
}

int main()
{
	int	arr[100];
	int i;

	i = -1;
	while (++i < 100)
	{
		arr[i] = 100 - i;
		printf("%d ", arr[i]);
	}
	printf("\n\n");
	radixSort(arr, 100, 2);
	while (--i > -1)
		printf("%d ", arr[99 - i]);
	printf("\n");
	return (0);
}
