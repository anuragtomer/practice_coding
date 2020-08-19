#include <iostream>
#include <set>
#include <vector>
using namespace std;
int main() {
    int t, x = 0;
    cin >> t;
    while (t) {
        x++;
        t--;
        vector<set<int>> rows;
        vector<set<int>> cols;
        int bad_rows = 0, bad_cols = 0, trace = 0, n, val;
        cin >> n;
        rows.resize(n);
        cols.resize(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> val;
                if (i == j)
                    trace += val;
                rows[i].insert(val);
                cols[j].insert(val);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (rows[i].size() != n)
                bad_rows++;
            if (cols[i].size() != n)
                bad_cols++;
        }
        cout << "Case #" << x << ": " << trace << " " << bad_rows << " " << bad_cols << endl;
    }
    return 0;
}