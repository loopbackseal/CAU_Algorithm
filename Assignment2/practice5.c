#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void	generateMatrix(int *matrix)
{
	int	i;
	int	j;

	srand((unsigned int)time(0));
	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 5)
		{
			*(matrix + i * 5 + j) = rand() % 1000;
			j++;
		}
		i++;
	}
}

void	printMatrix(int *matrix)
{
	int	i;
	int	j;

	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 5)
		{
			printf("%3d ", *(matrix + i * 5 + j));
			j++;
		}
		i++;
		printf("\n");
	}
}

void	rotateMatrix(int *newMatrix, int *matrix)
{
	int	i;
	int	j;

	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 5)
		{
			*(newMatrix + (4 - i) + j * 5) = *(matrix + i * 5 + j);
			j++;
		}
		i++;
	}
}

int	main()
{
	int	matrix[5][5];
	int newMatrix[5][5];
	int	i;
	int	j;

	i = 0;
	generateMatrix(*matrix);
	printMatrix(*matrix);
	printf("\n");
	rotateMatrix(*newMatrix, *matrix);
	printMatrix(*newMatrix);
}

