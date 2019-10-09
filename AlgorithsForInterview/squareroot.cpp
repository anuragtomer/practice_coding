#include<iostream>

using namespace std;

int squareroot(int n) {
    int lb = 1;
    int ub = 65536; // Setting this to INT_MAX would cause overflowing in mid*mid step.
    int mid = -1;
    while(lb + 1 < ub) {
        mid = lb + (ub - lb) / 2;
        int sq = mid * mid;
        if (sq == n)
            return mid;
        else if (sq < n) {
            lb = mid;
        } else {
            ub = mid;
        }
    }
    return lb;
}

int main() {
    int n;
    cin >> n;
    cout << squareroot(n) << endl;
    return 0;
}