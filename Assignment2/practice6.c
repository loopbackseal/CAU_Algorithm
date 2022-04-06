#include <stdio.h>
#include <stdlib.h>

char	*makeString(int *arr, int i, int j)
{
	char	*result;
	int		idx;

	result = malloc(6);
	if (result == 0)
		return (0);
	idx = 0;
	if (arr[i] >= 0)
	{
		result[idx] = arr[i] + '0';
		idx++;
	}
	else
	{
		result[idx] = '-';
		idx++;
		result[idx] = -1 * arr[i] + '0';
		idx++;
	}
	result[idx] = '+';
	idx++;
	if (arr[j] >= 0)
	{
		result[idx] = arr[j] + '0';
		idx++;
	}
	else
	{
		result[idx] = '-';
		idx++;
		result[idx] = -1 * arr[j] + '0';
		idx++;
	}
	result[idx] = '\0';
	return (result);
}

char	**pairSum(int *arr, int target)
{
	int			i;
	int			j;
	int			idx;
	char		*answer;
	static char	*result[20];

	i = 0;
	idx = 0;
	while (i < 9)
	{
		j = i + 1;
		while (j < 10)
		{
			if (arr[i] + arr[j] == target)
			{
				answer = makeString(arr, i, j);
				result[idx] = answer;
				idx++;
			}
			j++;
		}
		i++;
	}
	return (result);
}

int main()
{
	int		i;
	int		target;
	char	**s;

	target = 7;
	int arr[10] = {2, 4, 3, 5, 6, -2, 4, 7, 8, 9};
	s = pairSum(arr, target);
	i = 0;

	while (s[i] != 0)
		printf("%s ",s[i++]);
	printf("\n");
}
