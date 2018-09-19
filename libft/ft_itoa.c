#include "libft.h"

static void	itoa_isnegative(int *n, int *neg)
{
	if (*n < 0)
	{
		*n *= -1;
		*neg = 1;
	}
}

char	*ft_itoa(int n)
{
	int		tmp;
	int		len;
	int		neg;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	tmp = n;
	len = 2;
	neg = 0;
	itoa_isnegative(&n, &neg);
	while (tmp /= 10)
		len++;
	len += neg;
	if ((str = (char*)malloc(sizeof(char) * len)) == NULL)
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	if (neg)
		str[0] = '-';
	return (str);
}
