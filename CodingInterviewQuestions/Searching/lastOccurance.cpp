/* Search last occurance of `elem` in array (which can have repetitions) in O(log n).
 */ 
#include<iostream>
#include<vector>

using namespace std;

int lastOccurance(vector<int> & arr, int lb, int ub, int elem) {
    if (lb > ub)
        return -1;
    if (arr[ub] == elem)
        return lb;
    int mid = (lb + ub)/2;
    if (arr[mid] <= elem) {
        return lastOccurance(arr, mid, ub, elem);
    }
    return lastOccurance(arr, lb, mid-1, elem);
}

int main() {
    int n; 
    cin >> n;
    vector<int> arr;
    int elem;
    for(int i = 0; i < n; i++) { 
        cin >> elem;
        arr.push_back(elem);    
    }
    cin >> elem;
    cout << lastOccurance(arr, 0, n-1, elem);
    return 0;
}