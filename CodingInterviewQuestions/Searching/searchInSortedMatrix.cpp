#include<iostream>
#include<vector>

using namespace std;

void printMatrix(vector<vector<int>> arr) {
    for (int i = 0, sz = arr.size(); i < sz; i++) {
        for (int j = 0, sz2 = arr[0].size(); j < sz2; j++) {
            cout << arr[i][j] << "  ";
        }
        cout << endl;
    }
}

pair<int, int>
findInMatrix(vector<vector<int>> arr, int elem) {
    /*
     * Algorithm: O(n)
     * Go to last element of first row.
     * 1. If this is the element, return this.
     * 2. If current element is greater than element-to-be-searched, search in previous column.
     * 3. If current element is less than element-to-be-searched, search in next row.
     * 4. Do 1-3 until all rows have been exhausted.
     */
    int i = 0;
    int j = arr[0].size() - 1;
    while(j >= 0) {
        if (arr[i][j] == elem) 
            return make_pair(i, j);
        if (arr[i][j] > elem)
            j--;
        else
            i++;
    }
    return make_pair(-1, -1);
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int> (n, 0));
    for (int i = 0, elem = 0; i < n; i++) {
        for (int j = 0; j < n; j++, elem++) {
            arr[i][j] = elem;
        }
    }

    printMatrix(arr);
    for (int i = 0, sz = arr.size(); i < sz; i++) {
        for (int j = 0, sz2 = arr[i].size(); j < sz2; j++) {
            pair<int, int> output = findInMatrix(arr, arr[i][j]);
            if (output.first != i || output.second != j) {
                cout << i << " " << j << " did not match.";
                return 1;
            }
        }
    }
    cout << "Found everything in first matrix. Trying second..\n";
    for (int i = 0, elem = 0; i < n; i++) {
        for (int j = 0; j < n; j++, elem++) {
            arr[j][i] = elem;
        }
    }

    printMatrix(arr);
    for (int i = 0, sz = arr.size(); i < sz; i++) {
        for (int j = 0, sz2 = arr[i].size(); j < sz2; j++) {
            pair<int, int> output = findInMatrix(arr, arr[i][j]);
            if (output.first != i || output.second != j) {
                cout << i << " " << j << " did not match.";
                return 1;
            }
        }
    }
    
    cout << "Found everything in second matrix. Trying special..\n";

    vector<vector<int>> arr2(4, vector<int> (4, 0));
    arr2[0][0] = 1;
    arr2[0][1] = 2;
    arr2[0][2] = 4;
    arr2[0][3] = 7;
    arr2[1][3] = 11;
    arr2[2][3] = 14;
    arr2[3][3] = 16;
    
    for (int i = 1; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            arr2[i][j] = arr2[i-1][j+1] + 1;
        }
    }

    printMatrix(arr2);
    for (int i = 0, sz = 4; i < sz; i++) {
        for (int j = 0, sz2 = 4; j < sz2; j++) {
            pair<int, int> output = findInMatrix(arr2, arr2[i][j]);
            if (output.first != i || output.second != j) {
                cout << i << " " << j << " did not match.";
                return 1;
            }
        }
    }

    cout << "Found all elements successfully";
    return 0;
}