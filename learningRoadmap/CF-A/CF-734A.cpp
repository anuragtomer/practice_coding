#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int A = 0;

    while (n)
    {
        n--;
        char c;
        cin >> c;
        if (c == 'A')
            A++;
        else
            A--;
    }
    if (A == 0)
        cout << "Friendship";
    else if (A > 0)
        cout << "Anton";
    else
        cout << "Danik";
    return 0;
}