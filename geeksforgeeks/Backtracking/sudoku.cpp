#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class Solution {
public:
    void printGrid(int grid[9][9]) {
        cout << endl;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << setw(2) << grid[i][j];
            }
            cout << endl;
        }
    }

     /* Finds and returns any empty place if any. Returns false if no empty place found. */
    bool anyEmptyPlace(int grid[9][9], int &row, int &col) {
        for (row = 0; row < 9; row++) {
            for (col = 0; col < 9; col++) {
                if (grid[row][col] == 0) {
                    return true;
                }
            }
        }
        return false;
    }

     /* Returns true if it is safe to place val in (row, col) in grid. */
    bool isSafe(int grid[9][9], int row, int col, int val) {
         /* If same element is somewhere in the same row or col. */
        for (int i = 0; i < 9; i++) {
            if (grid[row][i] == val || grid[i][col] == val) {
                return false;
            }
        }
        int left = row / 3;
        int top = col / 3;
        for (int i = left * 3; i < (3 * left) + 3; i++) {
            for (int j = top * 3; j < (top * 3) + 3; j++) {
                if (grid[i][j] == val) {
                    return false;
                }
            }
        }
        return true;
    }

    bool sudoku(int grid[9][9]) {
        int row = 0, col = 0;
        if (!anyEmptyPlace(grid, row, col)) {
            cout << "Solution exists.\n";
            printGrid(grid);
            return true;
        }
        for (int i = 1; i <= 9; i++) {
            if (isSafe(grid, row, col, i)) {
                grid[row][col] = i;
                if (sudoku(grid)) {
                    return true;
                }
                grid[row][col] = 0;
            }
        }
        return false;
    }
};

int main(){
    Solution sol;
    int grid[9][9];
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> grid[i][j];
        }
    }
    if (!sol.sudoku(grid)) {
        cout << "No solution exists.";
    }
    return 0;
}
