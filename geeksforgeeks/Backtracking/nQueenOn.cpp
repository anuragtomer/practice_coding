#include <iostream>
#include <cmath>

using namespace std;

#define INTMAX 10

class Solution {
public:

    void printPlacements(int queenPositions[INTMAX], int totalQueens) {
        cout << "\nPlacement:\n";
        for (int i = 0; i < totalQueens; i++) {
            for (int j = 0; j < totalQueens; j++) {
                if (queenPositions[i] == j) {
                    cout << " Q";
                } else {
                    cout << " -";
                }
            }
            cout << endl;
        }
    }

    bool isSafe(int placedQueens, int position, int queenPositions[INTMAX], int totalQueens) {
        for (int i = 0; i < placedQueens; i++) {
            /*
             * 1. If there already exists a Queen in previous rows in the same column, return false.
             * 2. If there aleady exists a Queen in some diagonal(row distance == column distance),
             * return false.
             */
            if (queenPositions[i] == position ||
                abs(queenPositions[i] - position) == abs(placedQueens - i)) {
                return false;
            }
        }
        return true;
    }

    void nQueen(int placedQueens, int totalQueens, int queenPositions[INTMAX]) {
        for (int i = 0; i < totalQueens; i++) {
            if (isSafe(placedQueens, i, queenPositions, totalQueens)) {
                queenPositions[placedQueens] = i;
                if ((totalQueens - 1) == placedQueens) {
                     /* If we have all the queens placed, print the arrangement. */
                    printPlacements(queenPositions, totalQueens);
                } else {
                     /* Else place more queens. */
                    nQueen(placedQueens + 1, totalQueens, queenPositions);
                }
            }
        }
    }

};
int main() {
    Solution sol;
    int n;
    cin >> n;
    int queenPositions[INTMAX];
    sol.nQueen(0, n, queenPositions);
    return 0;
}
