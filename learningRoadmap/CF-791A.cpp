#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int ans = 0;
    while (a <= b)
    {
        ans++;
        a *= 3;
        b *= 2;
    }
    cout << ans;
    return 0;
}