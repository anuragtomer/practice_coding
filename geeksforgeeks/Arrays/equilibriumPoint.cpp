#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int equilibriumPoint(vector <int> arr) {
        int sum = 0;
        for (int i: arr)
            sum += i;
        int maxSum = sum / 2;
        int currSum = 0;
        for (unsigned i = 0; i < arr.size() && currSum <= maxSum; i++) {
            if (currSum == sum - arr[i] - currSum)
                return (i + 1);
            currSum += arr[i];
        }
        return -1;
    }
};

int main() {
    Solution sol;
    int T;
    cin >> T;
    while(T) {
        int num;
        cin >> num;
        vector <int> arr;
        arr.clear();
        while(num) {
            int val;
            cin >> val;
            arr.push_back(val);
            num--;
        }
        cout << sol.equilibriumPoint(arr) << endl;
        T--;
    }
    return 0;
}
/*
 *  Example:
 *  Input:
 *    4
 *    1
 *    1
 *    5
 *    1 3 5 2 2
 *    17
 *    27 4 25 6 6 1 27 22 19 29 6 9 36 24 6 15 5
 *    8
 *    43 34 2 8 17 5 11 8
 *  Output:
 *    1
 *    3
 *   -1
 *   -1
 */
