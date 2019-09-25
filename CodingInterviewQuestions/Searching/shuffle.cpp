/* Aim is to shuffle the given array a1 a2 a3 a4 .. an b1 b2 b3 b4 .. bn into
 * a1 b1 a2 b2 a3 b3 a4 b4 ... an bn.
 * Algo:
 * Swap around middle and recursively continue for each half.
 * Input: 
 *          [ a1 a2 a3 a4 | b1 b2 b3 b4 ]
 * Swap around middle:
 *          [ a1 a2 b1 b2 | a3 a4 b3 b4 ]
 * Continue:
 *          [ [a1 a2 || b1 b2 ] | [ a3 a4 || b3 b4 ] ]
 * Swap:
 *          [ [a1 b1 || a2 b2 ] | [ a3 b3 || a4 b4 ] ]
 * Stop when subarray has only 2 elements.
 */
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

void swapElements(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void swap(vector<int> &arr, int lb1, int ub1, int lb2, int ub2) {
    for (int i = lb1, j = lb2; i <= ub1 && j <= ub2; i++, j++) {
        swapElements(arr[i], arr[j]);
    }
}

void shuffle(vector<int> &arr, int lb, int ub, int sw) {
    if (sw > 0) {        
        int mid = (lb + ub)/2;
        swap(arr, mid - sw + 1, mid, mid + 1, mid + sw);
        shuffle(arr, lb, mid, sw/2);
        shuffle(arr, mid+1, ub, sw/2);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr;
    srand(time(NULL));
    for (int i = 0; i < n; i++)
        arr.push_back(rand() % n);
    cout << "Before: ";
    for (auto &i: arr)
        cout << i << " ";
    shuffle(arr, 0, arr.size()-1, arr.size() / 4);
    cout << "\nAfter: ";
    for (auto &i: arr)
        cout << i << " ";
    return 0;
}