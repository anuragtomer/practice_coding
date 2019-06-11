#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void findPaths(vector <vector <int> > arr,
                   vector < vector <int> > & output,
                   vector <int> path,
                   int i,
                   int j) {
        path.push_back(arr[i][j]);
        if (i < arr.size() - 1 && j < arr[0].size() - 1) {
            findPaths(arr, output, path, i + 1, j);
            findPaths(arr, output, path, i, j + 1);
        } else if (i == arr.size() - 1 && j < arr[0].size() - 1) {
            findPaths(arr, output, path, i, j + 1);
        } else if (i < arr.size() - 1 && j == arr[0].size() - 1) {
            findPaths(arr, output, path, i + 1, j);
        } else {
            output.push_back(path);
        }
    }
};

int main(){
    Solution sol;
    int T;
    cin >> T;
    while(T) {
        int n, m;
        cin >> n >> m;
        vector <vector <int> > arr;
        arr.clear();
        for (int i = 0; i < n; i++) {
            vector <int> row;
            row.clear();
            for (int j = 0; j < m; j++) {
                int val;
                cin >> val;
                row.push_back(val);
            }
            arr.push_back(row);
        }
        vector <vector <int> > output;
        output.clear();
        vector <int>  path;
        path.clear();
        sol.findPaths(arr, output, path, 0, 0);
        for (vector <int> paths: output) {
            cout << "Path:" << endl;
            for (int i: paths) {
                cout << i << " ";
            }
            cout << endl;
        }
        T--;
    }
    return 0;
}
