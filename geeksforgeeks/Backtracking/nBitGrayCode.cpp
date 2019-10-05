#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void nBitGray(int n, vector <int> &seq, int &num) {
        if (n == 0) {
            seq.push_back(num);
            return;
        }
        nBitGray(n - 1, seq, num);
        num = num ^ (1 << (n - 1));
        nBitGray(n - 1, seq, num);
    }
    vector <int> nBitGrayCode(int n) {
        vector <int> seq;
        seq.clear();
        int num = 0;
        nBitGray(n, seq, num);
        return seq;
    }
};

int main() {
    Solution sol;
    int n;
    cin >> n;
    vector <int> seq;
    seq = sol.nBitGrayCode(n);
    for (int i: seq)
        cout << i << " ";
    return 0;
}
