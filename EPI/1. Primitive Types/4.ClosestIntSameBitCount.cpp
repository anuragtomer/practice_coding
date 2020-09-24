#include <iostream>
#include <vector>

using namespace std;

const int kNumUnsignedBits = 64;

unsigned long ClosestIntSameBitCount1(unsigned long x) {
    for (int i = 0; i < kNumUnsignedBits - 1; ++i) {
        // Traverse over all bits.
        if (((x >> i) & 1) != ((x >> (i + 1)) & 1)) {
            // ith bit is different from (i+1)th bit.
            x ^= (1UL << i) | (1UL << (i + 1)); // Flip both bits.
            return x;
        }
    }
    throw invalid_argument("All bits are 0 or 1");
    // O(n) time complexity where n is number width in bits, because traversing the whole number in bits.
}

unsigned long ClosestIntSameBitCount(unsigned long x) {
    unsigned long onlyLowestBit = x & ~(x - 1);
    bool invert = false;
    if ((onlyLowestBit >> 1) == 0) {
        invert = true;
        x = ~x;
    }
    onlyLowestBit = x & ~(x - 1);
    unsigned long withLowestClearedBit = x & (x - 1);
    unsigned long closestInt = withLowestClearedBit | (onlyLowestBit >> 1);
    return invert ? ~closestInt : closestInt;
    // O(1) time and space complexity.
}

int main() {
    assert(ClosestIntSameBitCount(6) == 5);
    assert(ClosestIntSameBitCount(8) == 4);
    assert(ClosestIntSameBitCount(7) == 11);
    assert(ClosestIntSameBitCount(1) == 2);
    return 0;
}
