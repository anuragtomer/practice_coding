#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a;
    int p = 0;
    int crime = 0;
    while (n)
    {
        n--;
        cin >> a;
        if (a > 0)
            p += a;
        else if (p == 0)
            crime++;
        else
            p--;
    }
    cout << crime;
    return 0;
}
