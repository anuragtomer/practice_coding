#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i <= m; ++i)
            dp[i][0] = i;
        for (int j = 0; j <= n; ++j)
            dp[0][j] = j;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (word1[i - 1] != word2[j - 1])
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
                else
                    dp[i][j] = dp[i - 1][j - 1];
            }
        }
        return dp[m][n];
    }
};

int main() {
    Solution sol;
    string word1 = "sea", word2 = "eat";
    if (2 != sol.minDistance(word1, word2)) {
        cout << sol.minDistance(word1, word2) << endl;
    }
    word1 = "leetcode", word2 = "etco";
    if (4 != sol.minDistance(word1, word2)) {
        cout << sol.minDistance(word1, word2) << endl;
    }

    return 0;
}

