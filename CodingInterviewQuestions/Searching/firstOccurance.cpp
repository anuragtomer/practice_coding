/* Search first occurance of `elem` in array (which can have repetitions) in O(log n).
 */ 
#include<iostream>
#include<vector>

using namespace std;

int firstOccurance(vector<int> & arr, int lb, int ub, int elem) {
    if (lb > ub)
        return -1;
    if (arr[lb] == elem)
        return lb;
    int mid = (lb + ub)/2;
    if (arr[mid] >= elem) {
        return firstOccurance(arr, lb, mid, elem);
    }
    return firstOccurance(arr, mid+1, ub, elem);
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
    cout << firstOccurance(arr, 0, n-1, elem);
    return 0;
}