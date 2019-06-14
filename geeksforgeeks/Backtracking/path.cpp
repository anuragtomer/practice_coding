/*
 * Chess path. Change movePossible() to move according to some other piece. Currently set to move
 * according to rules of Knight.
 */
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class Solution {
public:
    void printChessboard(int chessboard[8][8]) {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                cout << setw(3);
                cout << chessboard[i][j];
            }
            cout << endl;
        }
    }
    bool movePossible(int toi, int toj, int chessboard[8][8], int fromi, int fromj) {
        if (chessboard[toi][toj] != -1)
            return false;
        if (toi - fromi == 2 && toj - fromj == 1)
            return true;
        if (toi - fromi == 1 && toj - fromj == 2)
            return true;
        if (toi - fromi == 2 && toj - fromj == -1)
            return true;
        if (toi - fromi == 1 && toj - fromj == -2)
            return true;
        if (toi - fromi == -2 && toj - fromj == 1)
            return true;
        if (toi - fromi == -1 && toj - fromj == 2)
            return true;
        if (toi - fromi == -2 && toj - fromj == -1)
            return true;
        if (toi - fromi == -1 && toj - fromj == -2)
            return true;
        return false;
    }
    bool findSolution(int chessboard[8][8], int fromi, int fromj, int val) {
        if (val == 64) {
            printChessboard(chessboard);
            return true;
        }
        for (int toi = 0; toi < 8; toi++) {
            for (int toj = 0; toj < 8; toj++) {
                if (movePossible(toi, toj, chessboard, fromi, fromj)) {
                    chessboard[toi][toj] = val + 1;
                    if (findSolution(chessboard, toi, toj, val + 1)) {
                        return true;
                    }
                    chessboard[toi][toj] = -1;
                }
            }
        }
        return false;
    }
    bool knightpath(int n) {
        int chessboard[8][8];
        for(int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                chessboard[i][j] = -1;
            }
        }
        chessboard[0][0] = 1;
        return findSolution(chessboard, 0, 0, 1);
    }
};

int main(){
    Solution sol;
    int n;
    cin >> n;
    if (!sol.knightpath(n))
        cout << "No solution exists.";
    return 0;
}
