#include "read_file.h"

char **read_grid(const char *filename, int *rows, int *cols) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return NULL;
    }

    fscanf(file, "%d %d", rows, cols);
    char **grid = malloc(*rows * sizeof(char *));
    if (!grid) {
        perror("Memory allocation failed");
        fclose(file);
        return NULL;
    }

    for (int i = 0; i < *rows; ++i) {
        grid[i] = malloc((*cols + 1) * sizeof(char));
        if (!grid[i]) {
            perror("Memory allocation failed");
            free_grid(grid, i);
            fclose(file);
            return NULL;
        }
        fscanf(file, "%s", grid[i]);
    }

    fclose(file);
    return grid;
}

// Frees a dynamically allocated grid
void free_grid(char **grid, int rows) {
    for (int i = 0; i < rows; ++i) {
        free(grid[i]);
    }
    free(grid);
}

// Reads a grid into a statically allocated 2D array
int read_arr_grid(const char *filename, char grid[MAX_ROWS][MAX_COLS],
                  int *rows, int *cols) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return -1;
    }

    if (fscanf(file, "%d %d", rows, cols) != 2) {
        fprintf(stderr, "Error reading grid dimensions\n");
        fclose(file);
        return -1;
    }

    for (int i = 0; i < *rows; ++i) {
        if (fscanf(file, "%s", grid[i]) != 1) {
            fprintf(stderr, "Error reading grid row %d\n", i);
            fclose(file);
            return -1;
        }
    }

    fclose(file);
    return 0;
}
