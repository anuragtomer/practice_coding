#include <iostream>
#include <vector>

using namespace std;

int calculate_sum(vector <vector <int>> arr, int i, int j) {
    int sum;
    sum = arr[i][j] +  arr[i][j + 1] +  arr[i][j + 2] +  arr[i + 1][j + 1] +  arr[i + 2][j] +  arr[i + 2][j + 1] +  arr[i + 2][j + 2];
    return sum;
}

int largest_hourglass(vector <vector <int>> arr)
{
    int max = -9 * 8;
    int sum;
    for (uint i = 0; i < 4; i++)
        for (uint j = 0; j < 4; j++) {
            sum = calculate_sum(arr, i, j);
            max = max < sum? sum: max;
        }
    return max;
}
int main()
{
    vector <vector <int>> arr(6, vector <int> (6));
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 6; j++)
            cin >> arr[i][j];
    cout << largest_hourglass(arr);
    return 0;
}
