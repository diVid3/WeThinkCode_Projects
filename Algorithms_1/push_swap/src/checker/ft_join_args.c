#include "../../inc/checker/checker.h"

char		*ft_join_args(int ac, char **av)
{
	int		cntr;
	char	*str;
	char	*tmp;

	cntr = 2;
	str = ft_strdup(av[1]);
	while (av[cntr])
	{
		tmp = ft_strjoin(str, " ");
		ft_memdel((void **)(&str));
		str = ft_strjoin(tmp, av[cntr]);
		ft_memdel((void **)(&tmp));
		++cntr;
	}
	return (str);
}

int		main(void)
{
	return (0);
}