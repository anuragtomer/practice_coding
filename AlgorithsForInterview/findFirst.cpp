/* Program to return index of first occurance of 'k' in SORTED 'arr'. */

#include<iostream>
#include <vector>

using namespace std;

int findk(vector<int> arr, int k) {
    int lb = 0;
    int ub = arr.size()-1;
    int mid = -1;
    while(lb+1<ub) {
        mid = lb + (ub - lb) / 2;
        if (arr[mid] >= k) {
            ub = mid;
        } else {
            lb = mid + 1;
        }
    }
    // There should be only 2 elements left by now. Preference given to lb.
    if (arr[lb] == k) {
        return lb;
    } else if (arr[ub] == k) {
        return ub;
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int index = 0;
    // Checking base case seperately.
    if (0 != findk(arr, arr[0])) {
        cout << "Not working correctly for 0";
        return 1;
    }
    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i] != arr[index]) 
            index = i;
        if (index != findk(arr, arr[i])) {
            cout << "Not working correctly for " << i;
            return 1;
        }
    }
    cout << "Found all correctly.";
    return 0;
}