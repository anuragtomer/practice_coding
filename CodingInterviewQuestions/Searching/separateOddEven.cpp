#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void swap(vector<int> &arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void separateOddEven(vector<int> &arr) {
    int high = arr.size();
    for (int i = 0; i < arr.size();) {
        if (arr[i]%2 == 1) {
            high--;
            swap(arr, i, high);
        } else {
            i++;
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i= 0; i< n; i++) 
        arr[i] = i;
    for (auto &i: arr)
        cout << i << " ";
    cout << endl;
    random_shuffle(arr.begin(), arr.end());
    separateOddEven(arr);
    for (auto &i: arr)
        cout << i << " ";
    return 0;
}