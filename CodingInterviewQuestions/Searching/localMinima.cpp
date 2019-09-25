#include<iostream>
#include<vector>

using namespace std;

int localMinima(vector<int> arr, int lb, int ub, int n) {
    if (lb > ub)
        return -1;
    int mid = (lb + ub)/2 ;
    if (mid == n-1 && arr[mid] < arr[mid - 1]) {
        return mid;
    }
    if (mid == 0 && arr[mid] < arr[mid + 1])
        return mid;
    if (arr[mid] < arr[mid - 1] && arr[mid] < arr[mid + 1])
        return mid;
    else if (arr[mid - 1] < arr[mid + 1])
        return localMinima(arr, lb, mid-1, n);
    else
        return localMinima(arr, mid+1, ub, n);
}

int main() {
    int n;
    vector<int> arr;
    cin >> n;
    int elem;
    for (int i = 0; i < n; i++) {
        cin >> elem;
        arr.push_back(elem);
    }
    cout << localMinima(arr, 0, n-1, n);
    return 0;
}