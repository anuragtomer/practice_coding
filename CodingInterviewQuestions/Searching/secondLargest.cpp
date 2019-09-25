#include <iostream>
#include <vector>

using namespace std;

int secondLargest(vector<int> arr) {
    int first = INT_MIN, second = INT_MIN;
    int isFirstSet = false, isSecondSet = false;
    for (int i = 0, sz = arr.size(); i < sz; ++i) {
        if (isFirstSet == false) {
            first = arr[i];
            isFirstSet = true;
            continue;
        }
        if (isSecondSet == false) {
            if (first < arr[i]) {
                second = first;
                first = arr[i];
            } else {
                second = arr[i];
            }
            isSecondSet = true;
            continue;
        }
        if (isFirstSet == true && isSecondSet == true) {
            if (first < arr[i]) {
                second = first;
                first = arr[i];
            } else if (second < arr[i]) {
                second = arr[i];
            }
        }
    }
    if (isFirstSet == false || isSecondSet == false) {
        cout << "Not enough elements.";
        return second;
    }
    return second;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr;
    int elem;
    for (int i = 0; i < n; i++) {
        cin >> elem;
        arr.push_back(elem);
    }
    cout << secondLargest(arr);
    return 0;
}