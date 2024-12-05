#include <stdio.h>
#include <string.h>
#include "read_file.h"

#define MAX_ROWS 300
#define MAX_COLS 300


int is_xmas(char grid[MAX_ROWS][MAX_COLS], int rows, int cols, int row, int col) {

    if (row - 1 >= 0 && row + 1 < rows && col - 1 >= 0 && col + 1 < cols) {

        if (((grid[row - 1][col - 1] == 'M' && grid[row + 1][col + 1] == 'S') ||
             (grid[row - 1][col - 1] == 'S' && grid[row + 1][col + 1] == 'M')) &&
            grid[row][col] == 'A') {


            if ((grid[row - 1][col + 1] == 'M' && grid[row + 1][col - 1] == 'S') ||
                (grid[row - 1][col + 1] == 'S' && grid[row + 1][col - 1] == 'M')) {
                return 1;
            }
        }
    }
    return 0;
}


int count_xmas_patterns(char grid[MAX_ROWS][MAX_COLS], int rows, int cols) {
    int count = 0;

    for (int row = 1; row < rows - 1; row++) {
        for (int col = 1; col < cols - 1; col++) {
            if (grid[row][col] == 'A' && is_xmas(grid, rows, cols, row, col)) {
                count++;
            }
        }
    }

    return count;
}


int main() {
    char grid[MAX_ROWS][MAX_COLS];
    int rows, cols;

    if (read_arr_grid("input.txt", grid, &rows, &cols) != 0) {
        return 1;
    }

    int result = count_xmas_patterns(grid, rows, cols);

    printf("Number of X-MAS patterns: %d\n", result);

    return 0;
}
