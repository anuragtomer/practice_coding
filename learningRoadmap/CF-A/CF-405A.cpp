#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> vec;
    int a;
    while (n)
    {
        cin >> a;
        vec.push_back(a);
        n--;
    }
    sort(vec.begin(), vec.end());
    for (auto v : vec)
        cout << v << " ";

    return 0;
}
