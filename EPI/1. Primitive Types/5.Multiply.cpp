#include <iostream>
#include <vector>

using namespace std;

unsigned Add(unsigned a, unsigned b) {
    unsigned sum = 0, temp_a = a, temp_b = b, carryin = 0, k = 1;
    // k is to get kth bit of a and b.
    while (temp_a || temp_b) {
        unsigned ak = a & k, bk = b & k;                                 // Get the kth bit of both a and b.
        unsigned carryout = (ak & bk) | (ak & carryin) | (bk & carryin); // Normal carry operation.
        sum |= (ak ^ bk ^ carryin);                                      // Normal sum operation.
        carryin = carryout << 1;                                         // Moving this carry to next bit.
        k <<= 1;                                                         // Moving extraction bit mask to next bit.
        temp_a >>= 1;                                                    // We have processed this bit. Discard it.
        temp_b >>= 1;                                                    // Same here.
    }
    return sum | carryin; // carryin would have moved to next bit by now.
    // O(n) operation.
}

unsigned Multiply(unsigned x, unsigned y) {
    unsigned sum = 0;
    while (x) {
        if (x & 1) {
            sum = Add(sum, y);
        }
        x >>= 1; // Move over to next x bit.
        y <<= 1;
    }
    return sum;
    // Total time complexity O(n^2)
}
int main() {
    assert(Multiply(5, 7) == 35);
    assert(Multiply(21, 45) == 21 * 45);
    return 0;
}
