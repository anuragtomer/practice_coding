#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void subsetsRecur(vector <int> arr, int index, vector <int> selected) {
        if (index == arr.size()) {
            for (int a : selected)
                cout << a << " ";
            cout << endl;
            return;
        }
        subsetsRecur(arr, index + 1, selected);
        selected.push_back(arr[index]);
        subsetsRecur(arr, index + 1, selected);
    }
    void subsets(vector <int> arr) {
        vector <int> selected;
        selected.clear();
        subsetsRecur(arr, 0, selected);
    }
};

int main(){
    Solution sol;
    int n;
    cin >> n;
    vector <int> arr(n);
    while(n) {
        cin >> arr[--n];
    }
    sol.subsets(arr);
    return 0;
}
