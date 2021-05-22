#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long int n;
    cin >> n;
    long long expected = n * (n + 1) / 2;
    long long runningSum = 0;
    long long int k;
    while (n > 1) {
        --n;
        cin >> k;
        runningSum += k;
    }
    cout << expected - runningSum;
    return 0;
}
