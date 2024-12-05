#include "main.h"
#include "read_file.h"

int directions[8][2] = {
    {0,   1}, // RIGHT
    {0,  -1}, // LEFT
    {1,   0}, // DOWN
    {-1,  0}, // UP
    {1,   1}, // DOWN-RIGHT
    {1,  -1}, // DOWN-LEFT
    {-1,  1}, // UP-RIGHT
    {-1, -1}, // UP-LEFT
};


int is_word_at(char **grid, int rows, int cols, int row, int col, int dx, int dy) {
    for (int i = 0; i < WORD_LENGTH; i++) {
        int new_row = row + i * dx;
        int new_col = col + i * dy;

        if (new_row < 0 || new_row >= rows || new_col < 0 || new_col >= cols) {
            return 0;
        }
        if (grid[new_row][new_col] != WORD[i]) {
            return 0;
        }
    }
    return 1;
}

int count_xmas(char **grid, int rows, int cols) {
    int count = 0;

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            for (int d = 0; d < 8; d++) {
                if (is_word_at(grid, rows, cols, row, col, directions[d][0], directions[d][1])) {
                    count++;
                }
            }
        }
    }

    return count;
}

int main() {
    const char *filename = "input.txt";
    int rows, cols;

    char **grid = read_grid(filename, &rows, &cols);

    int result = count_xmas(grid, rows, cols);
    printf("Part 1: %d\n", result);

    free_grid(grid, rows);


    return 0;
}

