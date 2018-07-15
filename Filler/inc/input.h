#ifndef INPUT_H
# define INPUT_H

typedef struct	s_input
{
	_Bool		read_1st;
	int			player_num;
	int			map_rows;
	int			map_cols;
	char		**map;
	int			piece_rows;
	int			piece_cols;
	char		**piece;
}				t_input;

#endif
