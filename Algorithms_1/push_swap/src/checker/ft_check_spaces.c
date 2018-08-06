#include "../../inc/checker/checker.h"
//#include <stdio.h>

int				ft_check_spaces(const char *str)
{
	int		cntr;

	cntr = 0;
	while (str[cntr])
	{
		if (cntr == 0 && (str[cntr] == '+' || str[cntr] == '-'))
			++cntr;
		if (str[cntr] == '+' || str[cntr] == '-')
			if (!(str[cntr - 1] >= 9 && str[cntr - 1] <= 13) &&
				!(str[cntr - 1] == 32))
				return (-1);
		++cntr;
	}
	return (0);
}

/*
int		main(void)
{
	char arr[] = "-5 -4 -5 -3 +2 0 +2 +1 -4";
	//char arr2[] = "+";
	printf("ret for arr is %d\n", ft_check_spaces(arr));
	return (0);
}
*/