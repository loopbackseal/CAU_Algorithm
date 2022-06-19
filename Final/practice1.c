#include <stdio.h>

int	cut_rod(int price[], int max_price[], int n)
{
	int	max;
	int	tmp;
	int	idx;

	max = -1;
	if (n == 0)
		return (0);
	else if (max_price[n] != -1)
		return (max_price[n]);
	else
	{
		idx = 1;
		while (idx < n + 1)
		{
			tmp = price[idx] + cut_rod(price, max_price, n - idx);
			max = max > tmp ? max : tmp;
			idx++;
		}
		max_price[n] = max;
		return (max);
	}
}

int	main(void)
{
	int	price[11];
	int	max_price[11];
	int	n;

	// 1 4 5 7 9 11 13 13 15 16
	price[0] = 0;
	price[1] = 1;
	price[2] = 4;
	price[3] = 5;
	price[4] = 7;
	price[5] = 9;
	price[6] = 11;
	price[7] = 13;
	price[8] = 13;
	price[9] = 15;
	price[10] = 16;

	n = 0;
	while (n < 11)
	{
		max_price[n] = -1;
		n++;
	}
	n = 1;
	while (n < 11)
	{
		printf("%d\n", cut_rod(price, max_price, n));
		n++;
	}
	return (0);
}
