#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int pathRecursive(int M, int N, int i, int j) {
        int right = 0, bottom = 0;
        if (i == M - 1 && j == N - 1)
            return 1;
        if (i < M)
            right = pathRecursive(M, N, i + 1, j);
        if (j < N)
            bottom = pathRecursive(M, N, i, j + 1);
        return right + bottom;
    }
    int pathLeftTopToBottomRight(int M, int N) {
        return pathRecursive(M, N, 0, 0);
    }
};

int main(){
    Solution sol;
    int T;
    cin >> T;
    while(T) {
        int x, y;
        cin >> x >> y;
        cout << sol.pathLeftTopToBottomRight(x, y) << endl;
        T--;
    }
    return 0;
}
