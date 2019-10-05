#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void floodFillRecursive(vector <vector <int> > &matrix, unsigned i, unsigned j, int newColor) {
        if (matrix[i][j] == newColor)
            return;
        int oldColor = matrix[i][j];
        matrix[i][j] = newColor;
        if ((i > 0) && (matrix[i - 1][j] == oldColor))
            floodFillRecursive(matrix, i - 1, j, newColor);
        if ((i < matrix.size() - 1) && (matrix[i + 1][j] == oldColor))
            floodFillRecursive(matrix, i + 1, j, newColor);
        if ((j > 0) && (matrix[i][j - 1] == oldColor))
            floodFillRecursive(matrix, i, j - 1, newColor);
        if ((j < matrix[i].size() - 1) && (matrix[i][j + 1] == oldColor))
            floodFillRecursive(matrix, i, j + 1, newColor);
    }
    vector <vector <int> >  floodFill(vector <vector <int> > &matrix, unsigned i, unsigned j, int newColor) {
        floodFillRecursive(matrix, i, j, newColor);
        return matrix;
    }
};

int main(){
    Solution sol;
    int T;
    cin >> T;
    while(T) {
        int x, y;
        cin >> x >> y;
        vector <vector <int> > matrix;
        matrix.clear();
        while(x) {
            int i = 0;
            vector <int> row;
            while (i < y) {
                int val;
                cin >> val;
                row.push_back(val);
                i++;
            }
            matrix.push_back(row);
             /* cout << "Row inputted." << endl; */
            x--;
        }
         /* cout << "Matrix inputted." << endl; */
        int newColor;
        cin >> x >> y >> newColor;
        matrix = sol.floodFill(matrix, x, y, newColor);
        for (vector <int> row: matrix) {
            for (int elem: row)
                cout << elem << " ";
            /* cout << endl; */
        }
        T--;
    }
    return 0;
}
