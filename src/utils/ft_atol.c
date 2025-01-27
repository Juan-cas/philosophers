#include "../../philosophers.h"

long	ft_atol(const char *str)
{
	int		i;
	int		sig;
	long	result;
	char	*str1;

	str1 = (char *) str;
	i = 0;
	sig = 1;
	result = 0;
	while ((str1[i] >= 9 && str1[i] <= 13) || (str1[i] == ' '))
		i++;
	if (str1[i] == '-' || str1[i] == '+')
	{
		if (str1[i] == '-')
			sig = -1;
		i++;
	}
	while (str1[i] >= '0' && str1[i] <= '9')
	{
		result = result * 10 + str1[i] - '0';
		i++;
	}
	if (result > INT_MAX)
		return (-1);
	return (result * sig);
}