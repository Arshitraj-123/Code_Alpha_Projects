#include <iostream>
#include <vector>
using namespace std;

#define N 9

bool isSafe(int grid[N][N], int row, int col, int num) {
    // Check if 'num' is not in the current row, current column, and current 3x3 sub-grid
    for (int x = 0; x < N; x++) {
        if (grid[row][x] == num || grid[x][col] == num || grid[row - row % 3 + x / 3][col - col % 3 + x % 3] == num) {
            return false;
        }
    }
    return true;
}

bool solveSudoku(int grid[N][N], int row, int col) {
    // If we have reached the last cell (9,9), we are done
    if (row == N - 1 && col == N) {
        return true;
    }

    // Move to the next row if we reached the end of the current row
    if (col == N) {
        row++;
        col = 0;
    }

    // Skip already filled cells
    if (grid[row][col] != 0) {
        return solveSudoku(grid, row, col + 1);
    }

    for (int num = 1; num <= 9; num++) {
        // Check if 'num' can be placed in grid[row][col]
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num; // Make tentative assignment

            // Return true if the Sudoku is solved
            if (solveSudoku(grid, row, col + 1)) {
                return true;
            }

            grid[row][col] = 0; // Undo assignment (backtrack)
        }
    }
    return false;
}

void printGrid(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            cout << grid[row][col] << " ";
        }
        cout << endl;
    }
}

int main() {
    int grid[N][N] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    if (solveSudoku(grid, 0, 0)) {
        printGrid(grid);
    } else {
        cout << "No solution exists" << endl;
    }

    return 0;
}
