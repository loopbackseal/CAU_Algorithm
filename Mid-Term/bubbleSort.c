void bubbleSort(int *a, int len)
{
	int	t;
	int	i;
	int	j;

	t = -1;
	for(i = 0; i < len; i++)
	{
		for (j = 0;  j < len - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
			}
        }
	}
}

int main() 
{
	return (0);
}
