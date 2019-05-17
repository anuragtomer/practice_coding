#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector <int> &arr, int lb1, int ub1, int lb2, int ub2) {
        vector <int> arr2(ub2 - lb1 + 1);
        arr2.clear();
        int i = lb1;
        int j = lb2;
        int k = 0;
        while(i <= ub1 && j <= ub2) {
            if (arr[i] < arr[j]) {
                arr2[k] = arr[i];
                i++;
                k++;
            } else {
                arr2[k] = arr[j];
                j++;
                k++;
            }
        }
        while(i <= ub1) {
            arr2[k] = arr[i];
            i++;
            k++;
        }
        while(j <= ub2) {
            arr2[k] = arr[j];
            j++;
            k++;
        }
        for (int i = lb1, j = 0; i <= ub2; i++, j++) {
            arr[i] = arr2[j];
        }
    }
    void mergeSort(vector <int> &arr, int lb, int ub) {
        if (lb >= ub)
            return;
        int mid = (lb + ub) / 2;
        mergeSort(arr, lb, mid);
        mergeSort(arr, mid + 1, ub);
        merge(arr, lb, mid, mid + 1, ub);
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
        sol.mergeSort(arr, 0, arr.size() - 1);
        for (int a : arr)
            cout << a << " ";
        cout << endl;
        T--;
    }
    return 0;
}
