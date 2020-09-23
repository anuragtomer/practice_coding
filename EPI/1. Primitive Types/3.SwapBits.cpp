#include <iostream>
#include <vector>

using namespace std;

long SwapBits(long x, int i, int j);

int main() {
    assert(SwapBits(0xFE03, 8, 0) == 0xFF02);
    assert(SwapBits(0xFE03, 9, 1) == 0xFE03);
    assert(SwapBits(0xFE03, 12, 4) == 0xEE13);
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