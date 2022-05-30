#include <stdio.h>
#include <stdlib.h>

void	bubbleSort(int arr[], int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (arr[j] < arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	findIndex(int n, int arr[])
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (arr[i] == n)
			return i;
		i++;
	}
	return (0);
}

int	main()
{
	int	itemList[6];
	int	itemSort[6];
	int	i;
	int	capacity;
	int	knapsack[6];
	int	count;
	int	maxValue;

	int weight[] = {6, 10, 3, 5, 1, 3};
	int value[] = {60, 20, 12, 80, 30, 60};

	i = 0;
	while (i < 6)
	{
		int item = value[i] / weight[i];
		*(itemList + i) = item;
		*(itemSort + i) = item;
		printf("item %d = value: %d weight: %d /: %d\n", i, value[i], weight[i], itemList[i]);
		i++;
	}
	bubbleSort(itemSort, 6);
	count = 0;
	capacity = 0;
	maxValue = 0;
	i = 0;
	while (i < 6)
	{
		int idx = findIndex(itemSort[i], itemList);
		if (capacity + weight[idx] <= 16)
		{
			*(knapsack + count) = idx + 1;
			capacity += weight[idx];
			maxValue += value[idx];
			++count;
		}
		i++;
	}
	printf("Max value: %d Fraction: %d\n", maxValue, capacity);
	i = 0;
	printf("associated items: ");
	while (i < count)
	{
		printf("%d ", knapsack[i]);
		i++;
	}
	printf("\n");
	return (0);
}
