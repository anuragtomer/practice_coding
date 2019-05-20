#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int kthElement(vector <int> arr1,
                   vector <int> arr2,
                   int index) {
        int len1 = arr1.size();
        int len2 = arr2.size();
        if (len1 > len2) /* Let us keep always size(arr1) < size(arr2) */
            return kthElement(arr2, arr1, index);
        if (len1 == 0) /* No elements in arr1. */
            return arr2[index];
        if (index == 0) /* Need to return first element. Return the minimum */
            return min(arr1[0], arr2[0]);
        int mid1 = (len1 - 1) / 2;
        int mid2 = (len2 - 1) / 2;
        if (mid1 + mid2 < index) {
            if (arr1[mid1] < arr2[mid2]) {
                arr1.erase(arr1.begin(), arr1.begin() + mid1 + 1);
                return kthElement(arr1, arr2, index - mid1 - 1);
            } else {
                arr2.erase(arr2.begin(), arr2.begin() + mid2 + 1);
                return kthElement(arr1, arr2, index - mid2 - 1);
            }
        } else {
            if (arr1[mid1] > arr2[mid2]) {
                arr1.erase(arr1.begin() + mid1, arr1.end());
                return kthElement(arr1, arr2, index);
            } else {
                arr2.erase(arr2.begin() + mid2, arr2.end());
                return kthElement(arr1, arr2, index);
            }
        }
        return 0;
    }
};

int main(){
    Solution sol;
    int T;
    cin >> T;
    while(T) {
        int sz1, sz2, index;
        cin >> sz1 >> sz2 >> index;
        vector <int> arr1, arr2;
        arr1.clear();
        arr2.clear();
        while(sz1) {
            int val;
            cin >> val;
            arr1.push_back(val);
            sz1--;
        }
        while(sz2) {
            int val;
            cin >> val;
            arr2.push_back(val);
            sz2--;
        }
        cout << sol.kthElement(arr1, arr2, index - 1);
        cout << endl;
        T--;
    }
    return 0;
}
