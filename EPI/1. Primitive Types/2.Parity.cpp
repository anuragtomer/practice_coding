#include <iostream>
#include <vector>

using namespace std;

short Parity(unsigned long x);

vector<unsigned short> parityCache;

void setupCache(unsigned bits);

int main() {
    setupCache(16); // This is used starting from solution 3.
    assert(Parity(5) == 0);
    assert(Parity(7) == 1);
    assert(Parity(11) == 1);
    assert(Parity(136) == 0);
    return 0;
}

short Parity1(unsigned long x) {
    // Basic
    short parity = 0;
    while (x) {
        parity ^= (x & 1); // XOR with last bit.
        x >>= 1;
    }
    return parity;
    // O(n) time complexity, O(1) space complexity.
}

short Parity2(unsigned long x) {
    // This improves the performance in best and average cases.
    short parity = 0;
    while (x) {
        parity ^= 1;
        x &= (x - 1); // Discard 0's from lsb so that lsb is set.
    }
    return parity;
    // Complexity is O(k), where k is number of set bits. This improves best, average case time but worst case time is
    // still O(n).
}

void setupCache(unsigned bits) {
    for (unsigned i = 0; i < (1 << bits); i++) {
        parityCache.push_back(Parity2(i));
    }
}

short Parity3(unsigned long x) {
    const int kWordSize = 16;
    const int kBitMask = 0xFFFF;
    return parityCache[x >> (3 * kWordSize)] ^ parityCache[(x >> (2 * kWordSize)) & kBitMask] ^
           parityCache[(x >> kWordSize) & kBitMask] ^ parityCache[x & kBitMask];
    // Time Complexity O(n/L), where L is cache bit size. Space complexity O(2^L). We save 2^L elements in cache.
}

short Parity(unsigned long x) {
    x ^= x >> 32;
    x ^= x >> 16;
    x ^= x >> 8;
    x ^= x >> 4;
    x ^= x >> 2;
    x ^= x >> 1;
    return x & 0x1;
    // Time Complexity O(log n). Space complexity O(1).
    // We can also combine approach 3 with this to further reduces the time by using cache once we reach 4 bits.
    // Table based approach is still 4 times faster.
}
