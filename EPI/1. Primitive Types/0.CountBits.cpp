#include <iostream>
using namespace std;

int CountBits(int x);

int main() {
    int x;
    cin >> x;
    cout << CountBits2(x);
    return 0;
}

int CountBits1(int x) {
    int count = 0;
    while (x) {
        if (x % 2 == 1)
            count++;
        x /= 2;
    }
    return count;
}

short CountBits2(unsigned int x) {
    short num_bits = 0;
    while (x) {
        num_bits += x & 1;
        x >>= 1;
    }
    return num_bits;
}