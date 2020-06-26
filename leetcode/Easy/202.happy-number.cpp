/**
 * A happy number is a number defined by the following process: Starting with any positive integer, replace the number
 * by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or
 * it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy
 * numbers.
 */
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
   public:
    bool isHappy(int n) {
        unordered_map<int, int> mp;
        while (n > 1) {
            int sum = 0;
            while (n > 0) {
                int rem = n % 10;
                sum += (rem * rem);
                n /= 10;
            }
            if (mp.find(sum) == mp.end())
                mp[sum] = 1;
            else
                return false;
            n = sum;
        }
        return n == 1;
    }
};

int main() {
    Solution sol;
    cout << boolalpha << sol.isHappy(15);
    return 0;
}