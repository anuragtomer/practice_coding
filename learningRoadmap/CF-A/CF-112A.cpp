#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s1, s2;
    cin >> s1;
    cin >> s2;
    /* 
     * Either convert char by reducing 32 for small chars or use string::toupper.
    for (int i = 0; i < s1.size(); ++i)
    {
        if (s1[i] >= 97)
            s1[i] -= 32;
        if (s2[i] >= 97)
            s2[i] -= 32;
    } */
    for (auto &c : s1)
        c = toupper(c);
    for (auto &c : s2)
        c = toupper(c);
    int n = s1.compare(s2);
    if (n == 0)
        cout << 0;
    else
        cout << ((n < 0) ? -1 : 1);
    return 0;
}
