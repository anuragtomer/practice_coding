#include <iostream>
#include <vector>

using namespace std;

int noOfTrailingZeros(int n) {
    int count = 0;
    for (int i = 5; 
         n/i > 0; 
         count += n/i, i*=5);
    return count;
}

int main() {
    int n;
    cin >> n;
    cout << noOfTrailingZeros(n);
    return 0;
}