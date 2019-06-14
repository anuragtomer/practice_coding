#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

#define MAXSIZE 10

class Solution {
public:
    void printSubset(int selected[MAXSIZE], int arr[MAXSIZE], int n) {
        for (int i = 0; i < n; i++) {
            if (selected[i] == 1)
                cout << arr[i] << " ";
        }
        cout << endl;
    }
    bool sumOfSubset(int n, int arr[MAXSIZE], int sum, int curr, int selected[MAXSIZE]) {
        if (sum == 0) {
            printSubset(selected, arr, n);
            return true;
        }
        cout << "\n Current sum: " << sum << endl;
        for (int i = curr; i < n; i++) {
            if ((sum - arr[i]) >= 0) {
                cout << "Selecting " << arr[i];
                selected[i] = 1;
                if (sumOfSubset(n, arr, sum - arr[i], i + 1, selected))
                    return true;
                cout << "\n Deselecting " << arr[i] << endl;;
                selected[i] = 0;
            }
        }
        return false;
    }
};

int main(){
    Solution sol;
    int n;
    cin >> n;
    int arr[MAXSIZE];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int sum;
    cin >> sum;
    int selected[MAXSIZE];
    for (int i = 0; i < n; i++)
        selected[i] = 0;
    if (!sol.sumOfSubset(n, arr, sum, 0, selected))
        cout << "No Solution Exists.";

    return 0;
}
