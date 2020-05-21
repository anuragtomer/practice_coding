/**
 * @file errichto-subarray-divisibility.cpp
 * @author Anurag
 *
 * @version 0.1
 * @date 2020-05-21
 *
 * @copyright Copyright (c) 2020
 *
 * Problem statement:
 *
 * Given a string, find how many numbers formed by substrings of this given
 * string are divisible by 2019.
 *
 * For example, for a given s = "1817181712114", 3 substrings are divisible by
 * 2019, wiz. 18171, 18171, 12114.
 *
 * Another example, s = "14282668646", 2 substrings are divisible by 2019.
 *
 */
#include <iostream>
#include <vector>

using namespace std;
const int MOD = 2019;
class Solution {
 public:
  long long multipleof2019(string s) {
    int sz = s.size() - 1;
    vector<int> cnt_suf(MOD);
    cnt_suf[0]++;
    int suf = 0;
    int power_of_ten = 1;
    long long answer = 0;
    for (int i = sz; i >= 0; --i) {
      int digit = s[i] - '0';
      suf = (suf + digit * power_of_ten) % MOD;
      power_of_ten = 10 * power_of_ten % MOD;
      answer += cnt_suf[suf];
      cnt_suf[suf]++;
    }
    return answer;
  }
};

int main() {
  Solution sol;
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  assert(3 == sol.multipleof2019("1817181712114"));
  assert(2 == sol.multipleof2019("14282668646"));
  assert(0 == sol.multipleof2019("2119"));
  return 0;
}
