#include "read_file.h"

char **read_grid(const char *filename, int *rows, int *cols) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
   
    char **grid = NULL;
    char buffer[1024];
    int row_count = 0;
    
    while (fgets(buffer, sizeof(buffer), file)) {
        buffer[strcspn(buffer, "\n")] = '\0';
        if (row_count == 0) {
            *cols = strlen(buffer);
        }
        grid = realloc(grid, (row_count + 1) * sizeof(char *));
        grid[row_count] = malloc((*cols + 1) * sizeof(char));
        strcpy(grid[row_count], buffer);

        row_count++;
    }

    *rows = row_count;
    fclose(file);

    return grid;
}

int read_arr_grid(const char *filename, char grid[300][300], int *rows, int *cols)
{
    FILE *file = fopen(filename, "r");
    if(!file){
        perror("Error opening file");
        return -1;
    }
    char buffer[MAX_COLS];
    *rows = 0;

    while(fgets(buffer,sizeof(buffer),file) && *rows < MAX_ROWS){
        buffer[strcspn(buffer, "\n")] = '\0';
        strcpy(grid[*rows], buffer);
        (*rows)++;
    }

    *cols = strlen(grid[0]);
    fclose(file);

    return 0;
}

void free_grid(char **grid, int rows) {
    for (int i = 0; i < rows; i++) {
        free(grid[i]);
    }
    free(grid);
}

