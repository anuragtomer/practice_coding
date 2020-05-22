#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int> hash(26, 0);
    string s;
    cin >> s;
    int unique = 0;
    for (auto &c : s)
    {
        hash[c - 'a']++;
    }
    for (int i = 0; i < 26; ++i)
    {
        if (hash[i] > 0)
            unique++;
    }
    if (unique % 2 == 1)
        cout << "IGNORE HIM!";
    else
        cout << "CHAT WITH HER!";
    return 0;
}
