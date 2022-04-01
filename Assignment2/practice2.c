#include <stdio.h>

int	cau_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	palindrome(char *s)
{
	int	i;
	int	len;
	int	flag;

	len = cau_strlen(s);
	i = 0;
	flag = 1;
	while (i < len / 2)
	{
		if (s[i] != s[len - 1 - i])
			flag = 0;
		i++;
	}
	if (flag == 1)
		printf("%s is palindrome\n", s);
	else
		printf("%s is not palindrome\n", s);
}

int	main()
{
	palindrome("level");
	palindrome("test");
}
