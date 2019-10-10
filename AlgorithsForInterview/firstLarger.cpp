/* Program to return index of first element larger than 'k' in SORTED 'arr'. */

#include<iostream>
#include <vector>

using namespace std;

int firstLarger(vector<int> arr, int k) {
    int lb = 0;
    int ub = arr.size()-1;
    int mid = -1;
    while(lb+1 < ub) {
        mid = lb + (ub - lb) / 2;
        if (arr[mid] <= k) {
            lb = mid + 1;
        } else {
            ub = mid;
        }
    }
    // There should be only 2 elements left by now. Preference given to lb (first larger element)
    if (arr[lb] > k) {
        return lb;
    } else if (arr[ub] > k) {
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

    int index = -1;
    // Checking base case seperately.
    if (index != firstLarger(arr, arr[arr.size() - 1])) {
        cout << "Not working correctly for last element.";
        return 1;
    }
    index = arr.size() - 1;
    for (int i = arr.size() - 2; i >= 0; --i) {
        if (arr[i] < arr[index - 1])
            index = i + 1;
        if (index != firstLarger(arr, arr[i])) {
            cout << "Not working correctly for " << i;
            return 1;
        }
    }
    cout << "Found all correctly.";
    return 0;
}