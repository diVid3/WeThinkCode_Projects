#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

static int			ft_read_buffer(int const fd, char **line)
{
	char	*buff;
	int		ret;
	char	*tmp;

	if (!(buff = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	ret = read(fd, buff, BUFF_SIZE);
	if (ret > 0)
	{
		buff[ret] = 0;
		if (!(tmp = ft_strjoin(*line, buff)))
			return (-1);
		free(*line);
		*line = tmp;
		//printf("%s\n", *line);
		free(buff);
	}
	if (ret == 0)
		free(buff);
	return (ret);
}

int					get_next_line(int const fd, char **line)
{
	static char		*str;
	char			*strn;
	int				ret;

	if ((!str && (!(str = (char*)malloc(sizeof(char) * BUFF_SIZE + 1))))
			|| fd < 0 || BUFF_SIZE <= 0)
		return (-1);
	strn = ft_strchr(str, '\n');
	while (!strn)
	{
		ret = ft_read_buffer(fd, &str);
		if (ret == 0 && !ft_strlen(str))
			return (0);
		if (ret == 0)
			ft_strcat(str, "\n");
		if (ret < 0)
			return (-1);
		else
			strn = ft_strchr(str, '\n');
	}
	if (!(*line = ft_strsub(str, 0, ft_strlen(str) - ft_strlen(strn))))
	{
		//printf("%s\n", *line);
		return (-1);
	}
	ft_strcpy(str, strn + 1);
	return (1);
}

void			print_test(char *line)
{
	if (!line)
		printf("*line is NULL\n");
	else if (*line == '\0')
		printf("(empty-string)\n", NULL);
	else
		printf("%s\n", line);
}

int		main(int ac, char **av)
{
	int			fd;
	int			fd2;
	int			fd3;
	int			ans;
	char		*line;

	(void)ac;
	fd = open(av[1], O_RDONLY);
	fd2 = open(av[2], O_RDONLY);
	fd3 = open(av[3], O_RDONLY);

	ans = get_next_line(fd, &line);
	printf("\n");
	printf("---------------------------------------------------------------\n");
	printf("1st File, 1st read\n");
	print_test(line);
	printf("---------------------------------------------------------------\n");

	ans = get_next_line(fd2, &line);
	printf("\n");
	printf("---------------------------------------------------------------\n");
	printf("2nd File, 1st read\n");
	print_test(line);
	printf("---------------------------------------------------------------\n");

	ans = get_next_line(fd3, &line);
	printf("\n");
	printf("---------------------------------------------------------------\n");
	printf("3rd File, 1st read\n");
	print_test(line);
	printf("---------------------------------------------------------------\n");

	ans = get_next_line(fd, &line);
	printf("\n");
	printf("---------------------------------------------------------------\n");
	printf("1st File, 2nd read\n");
	print_test(line);
	printf("---------------------------------------------------------------\n");

	ans = get_next_line(fd2, &line);
	printf("\n");
	printf("---------------------------------------------------------------\n");
	printf("2nd File, 2nd read\n");
	print_test(line);
	printf("---------------------------------------------------------------\n");

	ans = get_next_line(fd, &line);
	printf("\n");
	printf("---------------------------------------------------------------\n");
	printf("1st File, 3rd read\n");
	print_test(line);
	printf("---------------------------------------------------------------\n");

	ans = get_next_line(fd, &line);
	printf("\n");
	printf("---------------------------------------------------------------\n");
	printf("1st File, 4th read\n");
	print_test(line);
	printf("---------------------------------------------------------------\n");

	printf("\n");
	return (0);
}
