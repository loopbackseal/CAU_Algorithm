#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void	genMatrix(int *matrix, int p, int q)
{
	int	i;
	int	row;
	int	col;

	srand((unsigned int)time(0));
	col = 0;
	i = 1;
	while (col < p)
	{
		row = 0;
		while (row < q)
		{
			*(matrix + col * q + row) = rand() % 100;
			row++;
			i++;
		}
		col++;
	}
}

void	printMatrix(int	*matrix, int p, int q)
{
	int	i;
	int	j;

	i = 0;
	while (i < p)
	{
		j = 0;
		while (j < q)
		{
			printf("%7d ", *(matrix + i * q + j));
			j++;
		}
		printf("\n");
		i++;
	}
}

int	minMemoised(int	*arr, int i, int j, int *m)
{
	int	idx;
	int	tmp;

	if (i == j)
		return (0);
	if (*(m + i * 100 + j) != -1)
		return (*(m + i * 100 + j));
	*(m + i * 100 + j) = 2147483647;
	idx = i;
	while (idx < j)
	{
		tmp = minMemoised(arr, i, idx, m) + minMemoised(arr, idx + 1, j, m) +
			arr[i - 1] * arr[idx] * arr[j];
		*(m + i * 100 + j) = *(m + i * 100 + j) < tmp ? 
			*(m + i * 100 + j) : tmp;
		idx++;
	}
	return (*(m + i * 100 + j));
}

int	minComputation(int *arr, int n, int *m)
{
	int i;
	int	j;

	i = 1;
	j = n - 1;
	return (minMemoised(arr, i, j, m));
}

void	mulMatrix(int *result, int *m1, int *m2, int p, int q, int r)
{
	int	mul, i, j, k = 0;

	while (i < p)
	{
		j = 0;
		while (j < r)
		{
			mul = 0;
			k = 0;
			while (k < q)
			{
				mul += *(m1 + i * q + k) * *(m2 + k * r + j);
				k++;
			}
			*(result + i * r + j) = mul;
			j++;
		}
		i++;
	}
}

int	main()
{
	int	p = 5,q = 3,r = 7,s = 10;
	int	matrix1[p][q];
	int	matrix2[q][r];
	int	matrix3[r][s];
	int	result[p][s];
	int	i,j,k = 0;
	int arr[] = {p, q, r, s};
	int m[100][100];
	int	n = 4;

	while (i < 100)
	{
		j = 0;
		while (j < 100)
		{
			m[i][j] = -1;
			j++;
		}
		i++;
	}

	genMatrix(*matrix1, p, q);
	genMatrix(*matrix2, q, r);
	genMatrix(*matrix3, r, s);
	printf("Matrix 1 :\n");
	printMatrix(*matrix1, p, q);
	printf("\n");
	printf("Matrix 2 :\n");
	printMatrix(*matrix2, q, r);
	printf("\n");
	printf("Matrix 3 :\n");
	printMatrix(*matrix3, r, s);
	printf("\n");

	int answer = minComputation(arr, n, *m);
	if (answer == p * r * (q + s))
	{
		// 1 * 2 * 3
		printf("123\n");
		int	matrix4[p][r];

		mulMatrix(*matrix4, *matrix1, *matrix2, p, q, r);
		printf("Result of first Calculation: \n");
		printMatrix(*matrix4, p, r);
		mulMatrix(*result, *matrix4, *matrix3, p, r, s);
	} else if (answer == (p + r) * q * s)
	{
		// 2 * 3 * 1
		int	matrix4[q][s];

		mulMatrix(*matrix4, *matrix2, *matrix3, q, r, s);
		printf("Result of first Calculation: \n");
		printMatrix(*matrix4, q, s);
		mulMatrix(*result, *matrix1, *matrix4, p, q, s);
	} else
	{
		printf("Something is wrong!");
	}
	printf("\nMinimal number of computation: %d\n", answer);
	printf("Result of calculation: \n");
	printMatrix(*result, p, s);
	return (0);
}
