#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

#define MAXSIZE 10
class Solution {
public:
    void printBoard(int board[MAXSIZE][MAXSIZE], int n) {
        for(int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << setw(2);
                cout << board[i][j];
            }
            cout << endl;
        }
    }

    bool canPlaceQueen(int n, int board[MAXSIZE][MAXSIZE], int i, int j) {
        for (int row = 0; row < n; row++) {
             /* Check for queen in current column. */
            if (board[row][j] == 1)
                return false;
             /* Check for queen in current row. */
            if (board[i][row] == 1)
                return false;
        }
        for (int row = (n * (-1)) + 1; row < 2 * n; row++) {
            int compi = i + row;
            int compj = j + row;
            if (compi >= 0 && compi < n && compj >= 0 && compj < n) {
                if (board[compi][compj] == 1)
                    return false;
            }
            compi = i - row;
            compj = j + row;
            if (compi >= 0 && compi < n && compj >= 0 && compj < n) {
                if (board[compi][compj] == 1)
                    return false;
            }
        }
        return true;
    }

    bool nQueenRecur(int n, int board[MAXSIZE][MAXSIZE], int count) {
        if (count == n) {
            printBoard(board, n);
            return true;
        }
        for (int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if (canPlaceQueen(n, board, i, j)) {
                    board[i][j] = 1;
                     /* cout << "placing at (" << i << "," << j << ") \n"; */
                    if (nQueenRecur(n, board, count + 1))
                        return true;
                    board[i][j] = 0;
                    /* cout << "removing from (" << i << "," << j << ") \n"; */
                }
            }
        }
        return false;
    }

    bool nQueen(int n) {
        int board[MAXSIZE][MAXSIZE];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] = 0;
            }
        }
        return nQueenRecur(n, board, 0);
    }
};

int main(){
    Solution sol;
    int n;
    cin >> n;
    if (!sol.nQueen(n))
        cout << "No solution exists.";
    return 0;
}
