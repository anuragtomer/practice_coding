/* Aim is to find the max (j - i), for all j > i such that A[j] > A[i].
 * Algorithm:
 * 1. Construct a LMin array such that LMin[i] = min(A[i], smallest A[k]), k < i
 * 2. Construct a RMax array such that RMax[j] = max(A[j], greatest A[k]), k > j
 * 3. For all i < arr size() and j < arr size() do:
 *    a. If LMin[i] < RMax[j], we have found one pair of interest. Update maxDiff. Move j ahead.
 *    b. Else, this is not interesting pair, move ahead i.
 * 4. Return maxDiff
 */
#include<iostream>
#include<vector>
#include<ctime>

using namespace std;

int maxi_j(vector<int> arr) {
    vector<int> LMin(arr.size());
    vector<int> RMax(arr.size());
    LMin[0] = arr[0];
    for (int i = 1, sz = arr.size(); i < sz; i++) {
        LMin[i] = min(arr[i], LMin[i-1]);
    }
    RMax[arr.size() - 1] = arr[arr.size() - 1];
    for (int j = arr.size() - 2; j >= 0; j--) 
        RMax[j] = max(arr[j], RMax[j+1]);
    int i = 0, j = 0, maxDiff = -1, sz = arr.size();
    while(i < sz && j < sz) {
        if (LMin[i] < RMax[j]) {
            maxDiff = max(maxDiff, j - i);
            j++;
        } else 
            i++;
    }
    return maxDiff;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr;
    srand(time(NULL));
    for (int i = 0; i < n; i++) {        
        arr.push_back(rand()%n);
    }
    cout << "Input Array: ";
    for (auto &i: arr)
        cout << i << " ";
    cout << "\nMax difference: " << maxi_j(arr);
    return 0;
}