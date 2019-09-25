#include<iostream>
#include<vector>
#include<algorithm>
#include<ctime>
using namespace std;

void swap(vector<int> & arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void dutchFlag(vector<int> &arr) {
    int low = 0, high = arr.size() - 1;
    for (int i = 0; i <= high;) {
        if (arr[i] == 2) {
            swap(arr, i, high);
            high--;
        } else if (arr[i] == 0) {
            swap(arr,i, low);            
            low++;
        } else {
            i++;
        }
    }
}

int main() {
    int n;
    cin >> n;
    srand(time(NULL));
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 3;
    }
    cout << "Input:";
    for (auto &i: arr)
        cout << i << " ";
    cout << endl<< "Output: ";
    dutchFlag(arr);
    for (auto &i: arr)
        cout << i << " ";
    return 0;
}