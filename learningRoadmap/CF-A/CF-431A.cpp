#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int> hash(4);
    for (int i = 0; i < 4; ++i)
        cin >> hash[i];
    string s;
    cin >> s;
    int res = 0;
    for (auto c : s)
        res += hash[c - '1'];
    cout << res;
    return 0;
}
