#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    char p = '\0';
    int count = 0;
    for (auto c : s)
    {
        if (p != '\0')
        {
            if (c == p)
                count++;
        }
        p = c;
    }
    cout << count;
    return 0;
}
