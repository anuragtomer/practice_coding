#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector <int> subarraySum(vector <int> input, int sum) {
        int currentSum = 0;
        unsigned i = 0, j = 0;
        while (i < input.size() || j < input.size()) {
            if (currentSum == sum) {
                return {i + 1, j};
            }
            while (currentSum > sum && i < input.size()) {
                currentSum -= input[i];
                i++;
            } while(currentSum < sum && j < input.size()) {
                currentSum += input[j];
                j++;
            }
        }
        return {-1};
    }
};

int main(){
    Solution sol;
    int T = 0;
    cin >> T;
    while(T) {
        int N = 0, S = 0;
        vector <int> input;
        input.clear();
        cin >> N >> S;
        int val = 0;
        while(N) {
            cin >> val;
            if (sum < S) {
                sum += val;
            }
            N--;
        }
        vector <int> res = sol.subarraySum(input, S);
        if (res.size() == 2) cout << res[0] << " " << res[1] << endl;
        else cout << res[0] << endl;
        T--;
    }
    return 0;
}

/*
 *  1
 *  42 468
 *  135 101 170 125 79 159 163 65 106 146 82 28 162 92 196 143 28 37 192 5 103 154 93 183 22 117 119 96 48 127 172 139 70 113 68 100 36 95 104 12 123 134
 *
 *  2
 *  5 12
 *  1 2 3 7 5
 *  10 15
 *  1 2 3 4 5 6 7 8 9 10
 */
