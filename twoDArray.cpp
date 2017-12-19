#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int sum(int i, int j, int max_i, int max_j, vector< vector<int> > &A) {
    if ((i > max_i - 2) || (j > max_j - 2)) {
        return 0;
    } 
    return A[i][j] + A[i][j + 1] + A[i][j + 2] + A[i + 1][j + 1] + A[i + 2][j] + A[i + 2][j + 1] + A[i + 2][j + 2]; 
}

int main(){
    vector< vector<int> > arr(6,vector<int>(6));
    int max_sum = INT_MIN, cur_sum = 0;
    for (int arr_i = 0;arr_i < 6;arr_i++){
        for (int arr_j = 0;arr_j < 6;arr_j++){
            cin >> arr[arr_i][arr_j];
        }
    }
    cout << max_sum << endl;
    for (int arr_i = 0;arr_i < 6;arr_i++){
        for (int arr_j = 0;arr_j < 6;arr_j++){
            cur_sum = sum(arr_i, arr_j, 5, 5, arr);
            max_sum = max_sum < cur_sum ? cur_sum : max_sum;
            cout << max_sum << " " << cur_sum << endl;
        }
    }
    cout << max_sum;
    return 0;
}
