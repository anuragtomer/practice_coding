/*
 *  Kadane's Algorithm:
 *
 *  We need to find max contiguous sum in the array A.
 *  Let B[j] be an array which has the max contiguous sum till jth index.
 *  So B[j] = MAX SUM_OVER_ALL(A[k]), j >= k >= i, for some i >= 1, meaning we are taking contiguous
 *  sum.
 *  This is equivalent of
 *  B[j] = max(B[j-1] + A[j], A[j]) - Either the new element A[j] increased the sum, or it
 *  decreased the sum, we take whichever is max because that is the def of B[j].
 *  And so, we need only constant space, linear time to find out max contiguous sum. We don't need
 *  an array to save the whole B[j]. It gets updated in each iteration.
 */

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int subarrayMaxContiguousSum(vector <int> arr) {
        int sum = arr[0]; /* sum_so_far */
        int sumTillHere = arr[0]; /* curr_max */
        for (unsigned i = 1; i < arr.size(); i++)
        {
            sumTillHere = max(arr[i], sumTillHere + arr[i]);
            sum = max(sum, sumTillHere);
        }
        return sum;
    }
};

int main(){
    Solution sol;
    int T;
    cin >> T;
    while(T) {
        T--;
        int sz;
        cin >> sz;
        vector <int> arr;
        arr.clear();
        while(sz) {
            int val;
            cin >> val;
            arr.push_back(val);
            sz--;
        }
        cout << sol.subarrayMaxContiguousSum(arr) << endl;
    }
    return 0;
}

/*
 *  Input
 *    3
 *    5
 *    1 2 3 -2 5
 *    4
 *    -1 -2 -3 -4
 *    8
 *    -2 -3 4 -1 -2 1 5 -3
 *  Output
 *    9
 *    -1
 *    7
 */
