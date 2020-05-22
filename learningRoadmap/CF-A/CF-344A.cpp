#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string s, p;
    int group = 0;
    while (n)
    {
        cin >> s;
        if (p.empty() || p != s)
            group++;
        p = s;
        n--;
    }
    cout << group;
    return 0;
}
