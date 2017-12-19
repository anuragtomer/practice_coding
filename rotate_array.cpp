#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n, rot, new_index;
    cin >> n >> rot;
    vector <int> vec(n);
    vector <int> new_vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }     
    for (int i = 0; i < n; i++) {
        new_index = (n + i - rot) % n;
        new_vec[new_index] = vec[i];
    }
    for (int i = 0; i < n; i++) {
        cout << new_vec[i] << " ";
    }
    return 0;
}
