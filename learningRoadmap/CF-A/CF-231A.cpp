#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int count = 0;
    while (n)
    {
        n--;
        int a, b, c;
        cin >> a >> b >> c;
        if (a + b + c > 1)
            count++;
    }
    cout << count;
    return 0;
}
