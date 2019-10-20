#include <iostream>
#include <vector>

using namespace std;

void swap(int &i, int &j) {
    int temp = i;
    i = j;
    j = temp;
}

void
mergeSorted(vector<int> &one, vector<int> &two) {
    int onsz = one.size();
    int twsz = two.size();
    int totalSize = onsz + twsz;
    int gap = (totalSize + 1)/ 2;
    
    while(gap > 0) {
        int i, j;
        for (i = 0, j = gap; j < onsz; i++, j++)
            if (one[i] > one[j])
                swap(one[i], one[j]);

        j = (gap > onsz)? gap-onsz: 0;
        for (; i < onsz && j < twsz; i++, j++)
            if (one[i] > two[j])
                swap(one[i], two[j]);

        for (i = 0; j < twsz; i++, j++) 
            if (two[i] > two[j])
                swap(two[i], two[j]);
        
        gap = (gap > 1)? (gap+1)/2: 0;
    }
}

int
main() {
    int T;
    cin >> T;
    while(T--) {
        int n, m;
        cin >> n >> m;
        vector<int> one(n);
        for (int i = 0; i < n; ++i)
            cin >> one[i];
        vector<int> two(m);
        for (int i = 0; i < m; ++i)
            cin >> two[i];
        mergeSorted(one, two);
        for (int i: one)
            cout << i << " ";
        for (int i: two)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}