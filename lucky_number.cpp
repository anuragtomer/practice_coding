#include <iostream>
#include <string>
using namespace std;
int main()
{
    int sum1 = 0, sum2 = 0, number;
    cin >> number;
    cin.ignore();
    int no[6], num;
    num = number;
    for(int i = 0; i < 6; i++) {
        no[i] = number%10;
        number /= 10;
        if (i < 3)
            sum2 += no[i];
        else
            sum1 += no[i];
    }
    if (sum1 == sum2)
        cout << "Lucky Number";
    else {
        cout << (sum1 - sum2) << endl;
        while (sum1 != sum2)
        {
            sum1 - sum2);
        }
    return 0;
}
