#include <iostream>
#include <vector>

using namespace std;

bool IsPalindromeNumber(int x);

int main() {
    assert(IsPalindromeNumber(5) == true);
    assert(IsPalindromeNumber(4598954) == true);
    assert(IsPalindromeNumber(87658) == false);
    return 0;
}

bool IsPalindromeNumber(int x) {
    if (x < 0)
        return false;
    // Count the no of digits in given number.
    const int num_digits = static_cast<int>(floor(log10(x))) + 1;
    // num_digits = [log10(x)] + 1
    // Create a mask based on number of digits.
    int msd_mask = static_cast<int>(pow(10, num_digits - 1));
    // mask = 10 ^ (num_digits - 1)
    for (int i = 0; i < (num_digits / 2); ++i) {
        if (x / msd_mask != x % 10)
            // First and last digit are different
            return false;
        x %= msd_mask;   // Ignore the msb.
        x /= 10;         // Ignore the lsb.
        msd_mask /= 100; // We have ignored 2 digits, reduce mask by 2 digits
    }
    return true;
    // Time complexity O(n), n is the no of digits, O(1) space complexity.
}