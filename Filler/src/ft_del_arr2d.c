#include "../inc/filler.h"
#include <stdio.h>

void		ft_del_arr2d(char **arr, size_t row_count)
{
	size_t		cntr;

	if (!row_count || !arr)
		return ;
	cntr = 0;
	while (cntr < row_count && arr[cntr])
	{
		free(arr[cntr]);
		arr[cntr] = NULL;
		++cntr;
	}
	free(arr);
	arr = NULL;
	return ;
}

size_t		ft_count_wrds(char *s, char c)
{
	size_t		cntr;
	size_t		wrd_count;
	_Bool		swtch;
	t_uchar		ch;

	cntr = 0;
	wrd_count = 0;
	swtch = 0;
	ch = (t_uchar)c;
	while (s[cntr])
	{
		if (s[cntr] != ch && swtch == 0)
			++wrd_count;
		if (s[cntr] != ch)
			swtch = 1;
		if (s[cntr] == ch)
			swtch = 0;
		++cntr;
	}
	return (wrd_count);
}

void		print_arr2d(char **arr, size_t row_count)
{
	size_t		cntr;

	if (!row_count || !arr)
		return ;
	cntr = 0;
	while (cntr < row_count && arr[cntr])
	{
		printf("%s\n", arr[cntr]);
		++cntr;
	}
	return ;
}

int			main(int ac, char **av)
{
	size_t	wrd_count;
	char	**arr;

	(void)ac;
	wrd_count = ft_count_wrds(av[1], ' ');
	arr = ft_strsplit(av[1], ' ');
	printf("The word count for av[1] is %zu\n", wrd_count);
	print_arr2d(arr, 6);
	ft_del_arr2d(arr, 6);
	//sleep(60);
	return (0);
}
