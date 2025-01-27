#include "../../philosophers.h"

static int check_d(char *argv)
{
	int	i;

	i = -1;
	while (argv[++i])
	{
		if(ft_isdigit(argv[i]))
			return (1);
	}
	return (0);
}

int lets_parse(int argc, char **argv)
{
	int checker;

	checker = ft_atol(argv[1]);
	if (checker > 200 || checker < 1 || check_d(argv[1]))
		return (perror("need 1 to 200 philos\n"), 1);
	checker = ft_atol(argv[2]);
	if (checker < 0 || check_d(argv[2]))
		return (perror("please check time to die\n"), 1);
	checker = ft_atol(argv[3]);
	if (checker < 0 || check_d(argv[3]))
		return (perror("please check time to eat\n"), 1);
	checker = ft_atol(argv[4]);
	if (checker < 0 || check_d(argv[4]))
		return (perror("please check time to sleep\n"), 1);
	if (argc == 6)
	{
		checker = ft_atol(argv[5]);
		if (checker < 0 || check_d(argv[5]))
			return (perror("please check times to eat\n"), 1);
	}
	return (0);
}