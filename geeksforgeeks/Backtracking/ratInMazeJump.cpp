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
        int jump = board[fromi][fromj];
        for (int i = 1; i <= jump; i++) {
            if (possibleMove(board, fromi + i, fromj, noC, noR)) {
                outputBoard[fromi + i][fromj] = 1;
                if (ratInMazeRecur(board, outputBoard, noR, noC, fromi + i, fromj))
                    return true;
                outputBoard[fromi + i][fromj] = 0;
            }
            if (possibleMove(board, fromi, fromj + i, noC, noR)) {
                outputBoard[fromi][fromj + i] = 1;
                if (ratInMazeRecur(board, outputBoard, noR, noC, fromi, fromj + i))
                    return true;
                outputBoard[fromi][fromj + i] = 0;
            }
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
