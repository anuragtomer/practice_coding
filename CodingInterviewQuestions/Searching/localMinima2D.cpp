#include<iostream>
#include <vector>
#include<algorithm>
#include <iomanip>

using namespace std;

bool checkMinima(vector<vector<int>> arr, int i, int j) {
    if (i == 0) {
        if (j == 0)
            return (arr[i+1][j] > arr[i][j] &&
                    arr[i][j+1] > arr[i][j]);
        else if (j == arr.size() -1)
            return (arr[i+1][j] > arr[i][j] &&
                    arr[i][j-1] > arr[i][j]);
        else 
            return (arr[i+1][j] > arr[i][j] &&
                    arr[i][j-1] > arr[i][j] &&
                    arr[i][j+1] > arr[i][j]);
    } else if (i == arr.size() - 1) {
        if (j == 0)
            return (arr[i-1][j] > arr[i][j] &&
                    arr[i][j+1] > arr[i][j]);
        else if (j == arr.size() - 1)
            return (arr[i-1][j] > arr[i][j] &&
                    arr[i][j-1] > arr[i][j]);
        else 
            return (arr[i-1][j] > arr[i][j] &&
                    arr[i][j-1] > arr[i][j] &&
                    arr[i][j+1] > arr[i][j]);
    } else {
        if (j == 0)
            return (arr[i+1][j] > arr[i][j] &&
                    arr[i-1][j] > arr[i][j] &&
                    arr[i][j+1] > arr[i][j]);
        else if (j == arr.size() - 1)
            return (arr[i-1][j] > arr[i][j] &&
                    arr[i+1][j] > arr[i][j] &&
                    arr[i][j-1] > arr[i][j]);
        else 
            return (arr[i-1][j] > arr[i][j] &&
                    arr[i][j-1] > arr[i][j] &&
                    arr[i][j+1] > arr[i][j] &&
                    arr[i+1][j] > arr[i][j]);
    }
    return false;
}

pair<int, int>
localMinima(vector<vector<int>> arr) {
    int i = 0;
    int j = arr.size()-1;
    while(j > 0 && i < arr.size()-1) {
        if (checkMinima(arr, i, j))
            return make_pair(i, j);
        else if (arr[i][j-1] < arr[i+1][j])
            j--;
        else 
            i++;

    }
    return make_pair(-1, -1);
}

void printMatrix(vector<vector<int>> arr) {
    
    for (auto &row: arr) {
        for (auto &col: row) {
            cout << setw(3) << col;
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n, 0));
    int range = n*n;
    vector<int> elems(n*n, 0);
    for (int i = 0; i < n*n; i++) 
        elems [i] = i;
    random_shuffle(elems.begin(), elems.end());
    for (int i = 0, k = 0; i < n; i++) {
        for (int j = 0; j < n; j++, k++) {
            arr[i][j] = elems[k];
        }
    }
    printMatrix(arr);
    pair<int, int> output = localMinima(arr);
    cout << "Minima at " << output.first << ", " << output.second;
    return 0;
}