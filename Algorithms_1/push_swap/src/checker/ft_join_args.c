#include "../../inc/checker/checker.h"

char		*ft_join_args(char **av)
{
	int		cntr;
	char	*str;
	char	*tmp;

	cntr = 2;
	if (!av[1])
		return (NULL);
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