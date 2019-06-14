#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

#define MAXSIZE 10

class Solution {
public:
    void printOutputMaze(int outputBoard[MAXSIZE][MAXSIZE], const int noR, const int noC) {
        for (int i = 0; i < noR; i++) {
            for (int j = 0; j < noC; j++) {
                cout << setw(3);
                cout << outputBoard[i][j];
            }
            cout << endl;
        }
    }

    bool possibleMove(int board[MAXSIZE][MAXSIZE], int i, int j, int noC, int noR) {
        if (i >= noC || j >= noR) {
            return false;
        }
        if (board[i][j] == 0)
            return false;
        return true;
    }
    bool ratInMazeRecur(int board[MAXSIZE][MAXSIZE], int outputBoard[MAXSIZE][MAXSIZE],
                        const int noR, const int noC, int fromi, int fromj) {
        if (fromi == noR - 1 && fromj == noC - 1) {
            printOutputMaze(outputBoard, noR, noC);
            return true;
        }
        if (possibleMove(board, fromi + 1, fromj, noC, noR)) {
            outputBoard[fromi + 1][fromj] = 1;
            if (ratInMazeRecur(board, outputBoard, noR, noC, fromi + 1, fromj))
                return true;
            outputBoard[fromi + 1][fromj] = 0;
        }
        if (possibleMove(board, fromi, fromj + 1, noC, noR)) {
            outputBoard[fromi][fromj + 1] = 1;
            if (ratInMazeRecur(board, outputBoard, noR, noC, fromi, fromj + 1))
                return true;
            outputBoard[fromi][fromj + 1] = 0;
        }
        return false;
    }

    bool ratInMaze(int noR, int noC, int board[MAXSIZE][MAXSIZE]) {
        int outputBoard[MAXSIZE][MAXSIZE];
        for (int i = 0; i < noR; i++) {
            for (int j = 0; j < noC; j++) {
                outputBoard[i][j] = 0;
            }
        }
        outputBoard[0][0] = 1;
        return ratInMazeRecur(board, outputBoard, noR, noC, 0, 0);
    }
};

int main(){
    Solution sol;
    int noR, noC;
    cin >> noR >> noC;
    int board[MAXSIZE][MAXSIZE];
    for (int i = 0; i < noR; i++) {
        for (int j = 0; j < noC; j++) {
            cin >> board[i][j];
        }
    }

    if (!sol.ratInMaze(noR, noC, board))
        cout << "No Solution";
    return 0;
}
