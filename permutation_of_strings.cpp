#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_permutations(string S, int beg, int end) {
    if (beg == end) {
    cout << S << endl;
    } else {
        for (int i = beg; i <= end; i++) {
            swap(S[i], S[beg]);
            print_permutations(S, beg + 1, end);
            swap(S[i], S[beg]);
        }
    }
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i ++) {
        string S;
        cin >> S;
        print_permutations(S, 0, S.length() - 1);
    }
    return 0;
}
