#include "../../inc/checker/checker.h"
//#include <stdio.h>

int				ft_count_nums(char *str)
{
	int		cntr;
	int		num_cnt;
	_Bool	swtch;

	cntr = 0;
	num_cnt = 0;
	swtch = 0;
	while (str[cntr])
	{
		if ((str[cntr] == '+' || str[cntr] == '-' || (str[cntr] >= '0' &&
			str[cntr] <= '9')) && !swtch)
		{
			++num_cnt;
			swtch = 1;
		}
		if ((str[cntr] >= 9 && str[cntr] <= 13) || str[cntr] == 32)
			swtch = 0;
		++cntr;
	}
	return (num_cnt);
}

/*
int		main(void)
{
	char	arr1[] = "1 2 3 4 5";
	char	arr2[] = "+3 -4 +8 0 99";
	char	arr3[] = "		748 	+74347	 	-38509 0";

	printf("arr1 num_cnt is %d\n", ft_count_nums(arr1));
	printf("arr2 num_cnt is %d\n", ft_count_nums(arr2));
	printf("arr3 num_cnt is %d\n", ft_count_nums(arr3));
	
	return (0);
}
*/