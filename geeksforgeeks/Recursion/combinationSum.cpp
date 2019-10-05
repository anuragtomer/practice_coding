/* Return set of all the subsets which sum up to a given no in the array.
 *
 *  Ex: Input - 10 1 2 7 6 1 5, sum = 8.
 *  Output - (1 2 5) (1 7) (1 1 6) (2 6)
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
    void combinationSumRecursive(vector <int> arr, int idx, int remainingSum, vector <int> currVec, set <vector <int> > &result) {
        if (remainingSum == 0) {
            result.insert(currVec);
            return;
        }
        if (idx >= arr.size() || remainingSum < 0)
            return;
         /* Including (idx)th element. */
        currVec.push_back(arr[idx]);
         /* See if adding this element makes the sum. */
        combinationSumRecursive(arr, idx + 1, remainingSum - arr[idx], currVec, result);
         /* Excluding (idx)th element. */
        currVec.pop_back();
         /* See if removing makes the sum. */
        combinationSumRecursive(arr, idx + 1, remainingSum, currVec, result);
    }
    set <vector <int> > combinationSum(vector <int> arr, int sum) {
        set <vector <int> > result;
        result.clear();
        vector <int> currVec;
        currVec.clear();
        sort(arr.begin(), arr.end());
         /* Including 0th element. */
        currVec.push_back(arr[0]);
        combinationSumRecursive(arr,  1, sum - arr[0], currVec, result);
         /* Excluding 0th element. */
        currVec.pop_back();
        combinationSumRecursive(arr,  1, sum, currVec, result);
        return result;
    }
};

int main(){
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
        int sum;
        cin >> sum;
        set <vector <int> > result;
        result = sol.combinationSum(arr, sum);
        if (result.size() != 0) {
            for (vector <int> ans: result) {
                cout << "(";
                for (int i = 0; i < ans.size(); i++) {
                    cout << ans[i];
                    if (i != ans.size() - 1)
                        cout << " ";
                }
                cout << ")";
            }
            cout << endl;
        } else {
            cout << "Empty" << endl;
        }
        T--;
    }
    return 0;
}
