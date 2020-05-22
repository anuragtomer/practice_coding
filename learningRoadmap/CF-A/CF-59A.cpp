#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int smaller = 0;
    for (auto c : s)
        if (c >= 97)
            smaller++;
        else
        {
            smaller--;
        }
    if (smaller >= 0)
    {
        for (auto &c : s)
        {
            if (c < 97)
                c = tolower(c);
        }
    }
    else
    {
        for (auto &c : s)
            if (c >= 97)
                c = toupper(c);
    }
    cout << s;
    return 0;
}
