#include <iostream>
#include <vector>

using namespace std;

long Reverse(int x);
int main() {
    assert(Reverse(248) == 842);
    assert(Reverse(-318) == -813);
    return 0;
}

long Reverse(int x) {
    bool negative = (x < 0);
    if (negative)
        x = x * -1;
    int reverse = 0;
    while (x) {
        reverse = reverse * 10 + x % 10;
        x = x / 10;
    }
    return negative ? -reverse : reverse;
    // Time complexity O(n), n is no of digits in input.
}