#include<iostream>
#include<string>
using namespace std;

int main()
{
    string str, str1;
    cin >> str;
    for (auto &s: str) {
        char a;
        if (islower(s))
            a = s - 32;
        else
            a = s + 32;
        str1.append(1, a);
    }
    cout << str1;
    return 0;
}
