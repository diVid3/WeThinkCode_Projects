#include "libft.h"

char		**ft_alloc_mat_rows(size_t rows)
{
	char		**arr;

	if (!rows)
		return (NULL);
	if ((arr = malloc(sizeof(char *) * rows + 1)) == NULL)
		return (NULL);
	arr[rows] = NULL;
	return (arr);
}
