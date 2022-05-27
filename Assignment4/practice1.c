#include <stdio.h>

int	fibonacci(int n)
{
	int	fibo[n + 2];
	int	i;

	i = 2;
	fibo[0] = 0;
	fibo[1] = 1;
	while (i <= n)
	{
		fibo[i] = fibo[i - 1] + fibo[i - 2];
		i++;
	}
	return fibo[n];
}

int	main()
{
	printf("n = 5 : %d\n", fibonacci(5));
	printf("n = 10 : %d\n", fibonacci(10));
	return (0);
}
