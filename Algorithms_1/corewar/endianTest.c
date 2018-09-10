#include <stdio.h>
#include <unistd.h>

void	write_us_rev(unsigned short n)
{
	char	*ptr;

	ptr = (char *)&n;
	write(1, ptr + 1, 1);
	write(1, ptr + 0, 1);
}

void	write_ui_rev(unsigned int n)
{
	char	*ptr;

	ptr = (char *)&n;
	write(1, ptr + 3, 1);
	write(1, ptr + 2, 1);
	write(1, ptr + 1, 1);
	write(1, ptr + 0, 1);
}

/*
** Playing with the endianness of the system.
*/

int		main(void)
{
	unsigned int x = 0xea83f3;
	char *ptr = (char *)&x;

	write(1, ptr + 0, 1);
	write(1, ptr + 1, 1);
	write(1, ptr + 2, 1);
	write(1, ptr + 3, 1);
	write_rev_ui(x);
	return (0);
}