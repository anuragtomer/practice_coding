/* Program to return any index 'i' such that arr[i] = i in a SORTED distinct 'arr'. */

#include<iostream>
#include <vector>

using namespace std;

int iAi(vector<int> arr) {
    int lb = 0;
    int ub = arr.size()-1;
    int mid = -1;
    while (lb <= ub) {
        mid = lb + (ub - lb) / 2;
        if (arr[mid] == mid) {
            return mid;
        } else if (arr[mid] > mid) {
            ub = mid - 1;
        } else {
            lb = mid + 1;
        }
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
    cout << iAi(arr);
    return 0;
}