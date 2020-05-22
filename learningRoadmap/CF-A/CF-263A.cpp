#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a;
    int result = 0;
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            cin >> a;
            if (a == 1)
            {
                result = abs(2 - i) + abs(2 - j);
            }
        }
    }
    cout << result;
    return 0;
}
