#include <iostream>
#include <vector>

using namespace std;

long long answer(long long x, long long y, long long a, long long b) {
    // If cost of moving them together is more that twice the cost of moving them one by one,
    // then move them one by one. Otherwise, move them together as long as one reaches 0, and
    // then move the other.
    return b > 2 * a ? (y + x) * a : x * b + (y - x) * a;
}

int main() {
    long long n;
    cin >> n;
    while (n > 0) {
        n--;
        long long a, b, x, y;
        cin >> x >> y >> a >> b;
        x > y ? swap(x, y) : void(0); // Lets keep the smaller at x so that we don't have to
                                      // take absolute while computing.
        cout << answer(x, y, a, b) << endl;
    }
    return 0;
}
