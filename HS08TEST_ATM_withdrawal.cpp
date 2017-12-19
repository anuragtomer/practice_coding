#include <iostream>

using namespace std;

int main(){
    int amount;
    float balance;
    cin >> amount >> balance;
    if (amount % 5 == 0) {
        if (amount + 0.5 <= balance) {
            balance = balance - amount - 0.5;
        }
    }
    cout << balance;
    return 0;
}
