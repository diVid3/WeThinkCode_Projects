#include <unistd.h>
#include <stdlib.h>

int		main(int ac, char **av)
{
	static unsigned char	arr[4096];
	unsigned int			cntr = 0;
	unsigned char			*ptr = arr;

	if (ac != 2)
		return (0);
	while (av[1][cntr])
	{
		if (av[1][cntr] == '>')
			++ptr;
		if (av[1][cntr] == '<')
			--ptr;
		if (av[1][cntr] == '+')
			++(*ptr);
		if (av[1][cntr] == '-')
			--(*ptr);
		if (av[1][cntr] == '.')
			write(1, ptr, 1);
		if (av[1][cntr] == '[' && !*ptr)

		++cntr;
	}
	return (0);
}