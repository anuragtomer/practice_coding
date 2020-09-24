#include <iostream>
#include <vector>

using namespace std;

unsigned Divide(unsigned x, unsigned y) {
    unsigned result = 0;
    int power = 32;
    unsigned long long y_power = static_cast<unsigned long long>(y) << power;
    while (x >= y) {
        while (y_power > x) {
            y_power >>= 1;
            --power;
        }
        result += 1U << power;
        x -= y_power;
    }
    return result;
}
int main() {
    assert(Divide(20, 3) == 20 / 3);
    assert(Divide(13, 2) == 13 / 2);
    assert(Divide(260, 17) == 260 / 17);
    return 0;
}
