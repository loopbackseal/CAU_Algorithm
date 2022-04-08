#include <stdio.h>

void	binarySearch(int arr[10], int key, int len)
{
	int	low;
	int	high;
	int	mid;
	int	count;

	low = 0;
	high = len - 1;
	count = 0;
	while (low <= high)
	{
		count++;
		mid = (low + high) / 2;
		if (arr[mid] == key)
		{
			printf("%d : key is at %d\n", count, mid);
			break;
		}
		else if (arr[mid] > key)
			high = mid - 1;
		else
			low = mid + 1;
	}
}
	

int	main()
{
	int	arr[10] = {12, 34, 37, 45, 57, 82, 99, 120, 134};
	int len = sizeof arr / sizeof arr[0];
	binarySearch(arr, 120, len);
}
