#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

#define MAX 20
class Solution {
public:
    void printarrangement(char arrangement[MAX][MAX], int M, int N) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cout << setw(2) << arrangement[i][j];
            }
            cout << endl;
        }
    }

    bool isConditionUnmet(char arrangement[MAX][MAX], int top[MAX], int bottom[MAX], int left[MAX],
                          int right[MAX], int M, int N, int &row, int &col) {
        col = -1;
        row = -1;
        for (int j = 0; j < M && col == -1; j++) {
            if (top[j] != -1) {
                int count = 0;
                for (int i = 0; i < N; i++) {
                    if (arrangement[i][j] == '+')
                        count++;
                }
                if (count != top[j]) {
                    col = j;
                }
            }
        }
        for (int i = 0; i < N && row == -1; i++) {
            if (left[i] != -1) {
                int count = 0;
                for (int j = 0; j < M; j++) {
                    if (arrangement[i][j] == '+')
                        count++;
                }
                if (count != left[i]) {
                    row = i;
                }
            }
        }
        if (col != -1 && row != -1) {
            return true;
        }
        if (col == -1) {
            for (int j = 0; j < M; j++) {
                if (bottom[j] != -1) {
                    int count = 0;
                    for (int i = 0; i < N; i++) {
                        if (arrangement[i][j] == '-')
                            count++;
                    }
                    if (count != bottom[j]) {
                        col = j;
                    }
                }
            }
        }
        if (col != -1 && row != -1) {
            return true;
        }
        if (row == -1) {
            for (int i = 0; i < N; i++) {
                if (right[i] != -1) {
                    int count = 0;
                    for (int j = 0; j < M; j++) {
                        if (arrangement[i][j] == '-')
                            count++;
                    }
                    if (count != right[i]) {
                        row = i;
                    }
                }
            }
        }
        if (col != -1 && row != -1) {
            return true;
        }
        return false;
    }

    bool sanitytest(char arrangement[MAX][MAX], int row, int col, char possibleComplement, int M, int N) {
        if (row == 0) {
            if (col == 0) {
                if (((arrangement[row][col + 1] != possibleComplement) && (arrangement[row][col + 1] != 'X')) ||
                    ((arrangement[row + 1][col] != possibleComplement) && (arrangement[row + 1][col] != 'X'))) {
                    goto out;
                }
            } else if (col == M - 1) {
                if (((arrangement[row][col - 1] != possibleComplement) && (arrangement[row][col - 1] != 'X')) ||
                    ((arrangement[row + 1][col] != possibleComplement) && (arrangement[row + 1][col] != 'X'))) {
                    goto out;
                }
            } else {
                if (((arrangement[row][col + 1] != possibleComplement) && (arrangement[row][col + 1] != 'X')) ||
                    ((arrangement[row][col - 1] != possibleComplement) && (arrangement[row][col - 1] != 'X')) ||
                    ((arrangement[row + 1][col] != possibleComplement) && (arrangement[row + 1][col] != 'X'))) {
                    goto out;
                }
            }
        } else if (row == N - 1) {
            if (col == 0) {
                if (((arrangement[row][col + 1] != possibleComplement) && (arrangement[row][col + 1] != 'X')) ||
                    ((arrangement[row - 1][col] != possibleComplement) && (arrangement[row - 1][col] != 'X'))) {
                    goto out;
                }
            } else if (col == M - 1) {
                if (((arrangement[row][col - 1] != possibleComplement) && (arrangement[row][col - 1] != 'X')) ||
                    ((arrangement[row - 1][col] != possibleComplement) && (arrangement[row - 1][col] != 'X'))) {
                    goto out;
                }
            } else {
                if (((arrangement[row][col + 1] != possibleComplement) && (arrangement[row][col + 1] != 'X')) ||
                    ((arrangement[row][col - 1] != possibleComplement) && (arrangement[row][col - 1] != 'X')) ||
                    ((arrangement[row - 1][col] != possibleComplement) && (arrangement[row - 1][col] != 'X'))) {
                    goto out;
                }
            }
        } else {
            if (col == 0) {
                if (((arrangement[row][col + 1] != possibleComplement) && (arrangement[row][col + 1] != 'X')) ||
                    ((arrangement[row - 1][col] != possibleComplement) && (arrangement[row - 1][col] != 'X')) ||
                    ((arrangement[row + 1][col] != possibleComplement) && (arrangement[row + 1][col] != 'X'))) {
                    goto out;
                }
            } else if (col == M - 1) {
                if (((arrangement[row][col - 1] != possibleComplement) && (arrangement[row][col - 1] != 'X')) ||
                    ((arrangement[row - 1][col] != possibleComplement) && (arrangement[row - 1][col] != 'X')) ||
                    ((arrangement[row + 1][col] != possibleComplement) && (arrangement[row + 1][col] != 'X'))) {
                    goto out;
                }
            } else {
                if (((arrangement[row][col + 1] != possibleComplement) && (arrangement[row][col + 1] != 'X')) ||
                    ((arrangement[row][col - 1] != possibleComplement) && (arrangement[row][col - 1] != 'X')) ||
                    ((arrangement[row - 1][col] != possibleComplement) && (arrangement[row - 1][col] != 'X')) ||
                    ((arrangement[row + 1][col] != possibleComplement) && (arrangement[row + 1][col] != 'X'))) {
                    goto out;
                }
            }
        }
        return true;
out:
        return false;
    }
    bool isSafe(char possible, int row, int col, char rules[MAX][MAX], char arrangement[MAX][MAX],
                int top[MAX], int bottom[MAX], int left[MAX], int right[MAX], int M, int N) {
        if (arrangement[row][col] != 'X')
            return false;
        char possibleComplement = 'X';
        if (possible == '+')
            possibleComplement = '-';
        else if (possible == '-')
            possibleComplement = '+';
        int rowpair = row, colpair = col;
        if (rules[row][col] == 'L')
            colpair = col + 1;
        else if (rules[row][col] == 'R')
            colpair = col - 1;
        else if (rules[row][col] == 'T')
            rowpair = row + 1;
        else if (rules[row][col] == 'B')
            rowpair = row - 1;
        if (arrangement[rowpair][colpair] != 'X')
            return false;
        arrangement[row][col] = possible;
        arrangement[rowpair][colpair] = possibleComplement;
        if (top[col] != -1) {
            int count = 0;
            for (int j = 0; j < N; j++) {
                if (arrangement[j][col] == '+')
                    count++;
            }
            if (count > top[col]) {
                goto out;
            }
        }
        if (top[colpair] != -1) {
            int count = 0;
            for (int j = 0; j < N; j++) {
                if (arrangement[j][colpair] == '+')
                    count++;
            }
            if (count > top[colpair]) {
                goto out;
            }
        }
        if (bottom[col] != -1) {
            int count = 0;
            for (int j = 0; j < N; j++) {
                if (arrangement[j][col] == '-')
                    count++;
            }
            if (count > bottom[col]) {
                goto out;
            }
        }
        if (bottom[colpair] != -1) {
            int count = 0;
            for (int j = 0; j < N; j++) {
                if (arrangement[j][colpair] == '-')
                    count++;
            }
            if (count > bottom[colpair]) {
                goto out;
            }
        }
        if (left[row] != -1) {
            int count = 0;
            for (int j = 0; j < M; j++) {
                if (arrangement[row][j] == '+')
                    count++;
            }
            if (count > left[row]) {
                goto out;
            }
        }
        if (left[rowpair] != -1) {
            int count = 0;
            for (int j = 0; j < M; j++) {
                if (arrangement[rowpair][j] == '+')
                    count++;
            }
            if (count > left[rowpair]) {
                goto out;
            }
        }
        if (right[row] != -1) {
            int count = 0;
            for (int j = 0; j < M; j++) {
                if (arrangement[row][j] == '-')
                    count++;
            }
            if (count > right[row]) {
                goto out;
            }
        }
        if (right[rowpair] != -1) {
            int count = 0;
            for (int j = 0; j < M; j++) {
                if (arrangement[rowpair][j] == '-')
                    count++;
            }
            if (count > right[rowpair]) {
                goto out;
            }
        }
        if (sanitytest(arrangement, row, col, possibleComplement, M, N) && sanitytest(arrangement, rowpair, colpair, possible, M, N)) {
            goto out;
        }
        arrangement[row][col] = 'X';
        arrangement[rowpair][colpair] = 'X';
        return true;
out:
        arrangement[row][col] = 'X';
        arrangement[rowpair][colpair] = 'X';
        return false;
    }

    void placeatpair(char arrangement[MAX][MAX], int row, int col, char rules[MAX][MAX], char possible) {
        char rule = rules[row][col];
        switch(rule) {
        case 'L':
            if (possible == '+') {
                arrangement[row][col + 1] = '-';
            } else if (possible == '-') {
                arrangement[row][col + 1] = '+';
            } else {
                arrangement[row][col + 1] = 'X';
            }
            break;
        case 'R':
            if (possible == '+') {
                arrangement[row][col - 1] = '-';
            } else if (possible == '-') {
                arrangement[row][col - 1] = '+';
            } else {
                arrangement[row][col - 1] = 'X';
            }
            break;
        case 'T':
            if (possible == '+') {
                arrangement[row + 1][col] = '-';
            } else if (possible == '-') {
                arrangement[row + 1][col] = '+';
            } else {
                arrangement[row + 1][col] = 'X';
            }
            break;
        case 'B':
            if (possible == '+') {
                arrangement[row - 1][col] = '-';
            } else if (possible == '-') {
                arrangement[row - 1][col] = '+';
            } else {
                arrangement[row - 1][col] = 'X';
            }
            break;
        default:
            break;
        }
    }

    bool magnet(int top[MAX], int bottom[MAX], int left[MAX], int right[MAX], char rules[MAX][MAX],
                char arrangement[MAX][MAX], int M, int N, char possibles[3]) {
         /* BASE Condition. */
        int row, col;
        if (!isConditionUnmet(arrangement, top, bottom, left, right, M, N, row, col)) {
            cout << "Solution Exists\n";
            printarrangement(arrangement, M, N);
            return true;
        }
        for (int i = 0; i < 3; i++) {
            if (isSafe(possibles[i], row, col, rules, arrangement, top, bottom, left, right, M, N)) {
                arrangement[row][col] = possibles[i];
                placeatpair(arrangement, row, col, rules, possibles[i]);
                 /* cout << "After choosing (" << row << ", " << col << ") for placing " << possibles[i]; */
                printarrangement(arrangement, M, N);
                if (magnet(top, bottom, left, right, rules, arrangement, M, N, possibles))
                    return true;
                arrangement[row][col] = 'X';
                placeatpair(arrangement, row, col, rules, 'X');
                 /* cout << "After resetting (" << row << ", " << col << ") " << possibles[i]; */
                printarrangement(arrangement, M, N);
            }
        }
        return false;
    }
};

int main(){
    Solution sol;
    int N, M;
    cin >> N >> M;
    int top[MAX], bottom[MAX], left[MAX], right[MAX];
    char rules[MAX][MAX];
    char arrangement[MAX][MAX];
    for (int i = 0; i < M; i++)
        cin >> top[i];
    for (int i = 0; i < M; i++)
        cin >> bottom[i];
    for (int i = 0; i < N; i++)
        cin >> left[i];
    for (int i = 0; i < N; i++)
        cin >> right[i];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> rules[i][j];
        }
    }
    char possibles[3] = {'+', '-', 'X'};
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            arrangement[i][j] = 'X';
        }
    }
    if (!sol.magnet(top, bottom, left, right, rules, arrangement, M, N, possibles))
        cout << "No solution Exists.";
    return 0;
}
