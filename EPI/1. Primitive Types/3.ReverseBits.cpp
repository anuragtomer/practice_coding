#include <iostream>
#include <vector>
using namespace std;

long ReverseBits(long x);
long ReverseBits1(long x);

void bin(unsigned long n) {
    unsigned long i;
    for (i = 1L << 63; i > 0; i = i / 2) // Printing 64 bit nos.
        (n & i) ? printf("1") : printf("0");
    cout << "\n";
}

vector<long unsigned> ReverseCache; // Global cache that saves reverse.

void setupCache(unsigned int bits) {
    ReverseCache.reserve(1 << bits);
    for (long i = 0; i < (1 << bits); ++i) {
        ReverseCache.push_back(ReverseBits1(i)); // Using the brute force to create cache.
    }
}

int main() {
    setupCache(16); // We save mapping for all 16 bit words to speed up in case of too many queries.
    assert(ReverseBits(0b0000000000000000000000000000000000000000000000000000000000000001) ==
           0b1000000000000000000000000000000000000000000000000000000000000000);
    assert(ReverseBits(0b0000000000000000000000000000000000000000000000001111111000000011) ==
           0b1100000001111111000000000000000000000000000000000000000000000000);
    return 0;
}

long SwapBits(long x, int i, int j) {
    if (((x >> i) & 1) != ((x >> j) & 1)) {
        // This needs bit flipping.
        unsigned long bit_mask = (1L << i) | (1L << j);
        x ^= bit_mask;
    }
    return x;
    // Time complexity is O(1), irrespective of word size.
}

long ReverseBits1(long x) {
    // Brute force
    // Swap the lower half with upper half.
    for (unsigned int i = 0; i < 8; ++i) { // Change 8 to 32 if using just this function.
        x = SwapBits(x, i, 15 - i);        // Change 15 to 63 if using just this function.
    }
    return x;
}

long ReverseBits(long x) {
    const int kWordSize = 16;
    const int kBitMask = 0xFFFF;
    return (ReverseCache[x & kBitMask] << (3 * kWordSize)) |
           (ReverseCache[(x >> kWordSize) & kBitMask] << (2 * kWordSize)) |
           (ReverseCache[(x >> (2 * kWordSize)) & kBitMask] << kWordSize) |
           (ReverseCache[(x >> (3 * kWordSize)) & kBitMask]);
}