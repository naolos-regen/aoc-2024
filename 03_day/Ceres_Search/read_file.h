#ifndef READ_FILE_H_
#define READ_FILE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **read_grid(const char *filename, int *rows, int *cols);
void free_grid(char **grid, int rows);



#endif // READ_FILE_H_
