#include <iostream>
#include <vector>

using namespace std;

int main() {
    int tests;
    cin >> tests;
    while (tests) {
        tests--;
        int n, m;
        cin >> n >> m;
        vector<int> marks;
        int otherMarks = 0;
        int myMarks = 0;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            if (i != 0)
                otherMarks += a;
            else
                myMarks = a;
        }
        int needMarks = m - myMarks;
        if (needMarks > otherMarks)
            cout << otherMarks + myMarks << "\n";
        else
            cout << m << "\n";
    }
    return 0;
}
