#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int binarySearch(vector <int> A, int left, int right, int k) {
        if (left > right)
            return -1;
        int mid = (left + right) / 2;
        if (A[mid] == k)
            return mid;
        if (A[mid] < k)
            left = mid + 1;
        else
            right = mid - 1;
        return binarySearch(A, left, right, k);
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
        int fnd;
        cin >> fnd;
        cout << sol.binarySearch(arr, 0, arr.size() - 1, fnd) << endl;
        T--;
    }
    return 0;
}
