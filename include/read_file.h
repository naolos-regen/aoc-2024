#ifndef READ_FILE_H_
# define READ_FILE_H_

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define MAX_COLS 1000
# define MAX_ROWS 1000

char	**read_grid(const char *filename, int *rows, int *cols);
void	free_grid(char **grid, int rows);
int		read_arr_grid(const char *filename, char grid[MAX_ROWS][MAX_COLS],
			int *rows, int *cols);

#endif // READ_FILE_H_
