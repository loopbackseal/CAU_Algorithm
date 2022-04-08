#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void	generateNMatrix(int *matrix, int n, int m)
{
	int	i;
	int	j;

	srand((unsigned int)time(0));
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < m)
		{
			*(matrix + i * m + j) = rand() % 1000;
			j++;
		}
		i++;
	}
}

void	divideNMatrix(int *matrix, int *aMatrix, int *bMatrix, int *cMatrix, int *dMatrix, int n, int m)
{
	int	i;
	int	j;
	int	p;
	int	q;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < m)
		{
			if (i < n / 2 && j < m / 2)
			{
				*(aMatrix + i * m / 2 + j) = *(matrix + i * m + j);
			}
			else if (i < n / 2 && j >= m / 2)
			{
				*(bMatrix + i * m / 2 + j - m / 2) = *(matrix + i * m + j);
			}
			else if (i >= n / 2 && j < m / 2)
			{
				*(cMatrix + (i - n / 2) * m / 2 + j) = *(matrix + i * m + j);
			}
			else 
			{
				*(dMatrix + (i - n / 2) * m / 2 + j - m / 2) = *(matrix + i * m + j);
			}
			j++;
		}
		i++;
	}
}

void	multiplyNMatrix(int	*aMatrix, int *bMatrix, int n, int m, int p, int *cMatrix)
{
	int	i;
	int	j;
	int	k;
	int	tmp;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < p)
		{
			k = 0;
			tmp = 0;
			while (k < m)
			{
				tmp += *(aMatrix + i * m + k) * *(bMatrix + k * p + j);
				k++;
			}
			*(cMatrix + i * p + j) = tmp;
			j++;
		}
		i++;
	}
}

void	addNMatrix(int *aMatrix, int *bMatrix, int n, int m, int *cMatrix)
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < m)
		{
			*(cMatrix + i * m + j) = *(aMatrix + i * m + j) + *(bMatrix + i * m + j);
			j++;
		}
		i++;
	}
}

void	printNMatrix(int *matrix, int n, int m)
{
	int	i;
	int	j;
	
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < m)
		{
			printf("%8d ", *(matrix + i * m + j));
			j++;
		}
		i++;
		printf("\n");
	}
	printf("\n");
}

int main()
{
	int matrix3010[30][10];
	int	matrix1050[10][50];
	int	aMatrix[15][5];
	int	bMatrix[15][5];
	int	cMatrix[15][5];
	int	dMatrix[15][5];
	int	AMatrix[5][25];
	int	BMatrix[5][25];
	int	CMatrix[5][25];
	int	DMatrix[5][25];
	int	eMatrix[15][25];
	int	fMatrix[15][25];
	int	gMatrix[15][25];
	int	hMatrix[15][25];
	int	EMatrix[15][25];
	int	FMatrix[15][25];
	int	GMatrix[15][25];
	int	HMatrix[15][25];
	int	resultMatrix[30][50];
	int	result11Matrix[15][25];
	int	result12Matrix[15][25];
	int	result21Matrix[15][25];
	int	result22Matrix[15][25];

	generateNMatrix(*matrix3010, 30, 10);
	generateNMatrix(*matrix1050, 10 ,50);
	divideNMatrix(*matrix3010, *aMatrix, *bMatrix, *cMatrix, *dMatrix, 30, 10);
	divideNMatrix(*matrix1050, *AMatrix, *BMatrix, *CMatrix, *DMatrix, 10 ,50);
	multiplyNMatrix(*matrix3010, *matrix1050, 30, 10, 50, *resultMatrix);
	multiplyNMatrix(*aMatrix, *AMatrix, 15, 5, 25, *eMatrix);
	multiplyNMatrix(*bMatrix, *CMatrix, 15, 5, 25, *EMatrix);
	multiplyNMatrix(*aMatrix, *BMatrix, 15, 5, 25, *fMatrix);
	multiplyNMatrix(*bMatrix, *DMatrix, 15, 5, 25, *FMatrix);
	multiplyNMatrix(*cMatrix, *AMatrix, 15, 5, 25, *gMatrix);
	multiplyNMatrix(*dMatrix, *CMatrix, 15, 5, 25, *GMatrix);
	multiplyNMatrix(*cMatrix, *BMatrix, 15, 5, 25, *hMatrix);
	multiplyNMatrix(*dMatrix, *DMatrix, 15, 5, 25, *HMatrix);
	addNMatrix(*eMatrix, *EMatrix, 15, 25, *result11Matrix);
	addNMatrix(*fMatrix, *FMatrix, 15, 25, *result12Matrix);
	addNMatrix(*gMatrix, *GMatrix, 15, 25, *result21Matrix);
	addNMatrix(*hMatrix, *HMatrix, 15, 25, *result22Matrix);
	printNMatrix(*resultMatrix, 30, 50);
	printNMatrix(*result11Matrix, 15, 25);
	printNMatrix(*result12Matrix, 15, 25);
	printNMatrix(*result21Matrix, 15, 25);
	printNMatrix(*result22Matrix, 15, 25);
}
