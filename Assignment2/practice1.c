#include <stdio.h>

void	largest_k(int n)
{
	int	k;
	int	m;

	k = 0;
	m = 2;
	while (m <= n)
	{
		m = m * 2;
		k++;
	}
	printf("%d's the largest positive integer k: %d\n", n, k);
}

int main()
{
	largest_k(10);
	largest_k(50);
	largest_k(1025);
}
