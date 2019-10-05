#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void swap(vector <int> &arr, int from, int to) {
        int temp = arr[from];
        arr[from] = arr[to];
        arr[to] = temp;
    }
    int partition(vector <int> &arr, int lb, int ub) {
        int pivot = arr[ub];
        int i = lb - 1;
        for (int j = lb; j < ub; j++) {
            if (pivot > arr[j]) {
                i++;
                swap(arr, i, j);
            }
        }
        i++;
        swap(arr, i, ub);
        return i;
    }
    void quick(vector <int> &arr, int lb, int ub) {
        if (lb >= ub)
            return;
        int i = partition(arr, lb, ub);
        quick(arr, lb, i - 1);
        quick(arr, i + 1, ub);
    }
    void quickSort(vector <int> &arr) {
        quick(arr, 0, arr.size() - 1);
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
        sol.quickSort(arr);
        for(int a: arr)
            cout << a << " ";
        cout << endl;
        T--;
    }
    return 0;
}
