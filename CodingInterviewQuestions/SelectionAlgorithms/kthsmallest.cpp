#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

void print(vector<int> a) {
    for (auto &i: a)
        cout << i << " ";
    cout << endl;
}

int kthsmallest(vector<int> a, vector<int> b, int k) {
    while(!a.empty() && !b.empty() && k > 0) {
        int m1 = a.size()/2;
        int m2 = b.size()/2;
        if (m1 + m2 + 1 > k) {
            // There are more elements in the two halves. Let get rid of half with bigger values.
            if (a[m1] > b[m2]) {
                // A half is greater.
                a.erase(a.begin() + m1, a.end());
            } else {
                b.erase(b.begin() + m2, b.end());
            }
        } else {
            // kth smallest element should be in second half of either array. Lets get rid of 
            // smaller elements and decrement k appropriately.
            if (a[m1] < b[m2]) {
                a.erase(a.begin(), a.begin() + m1 + 1);
                k -= (m1 + 1);
            } else {
                b.erase(b.begin(), b.begin() + m2 + 1);
                k -= (m2 + 1);
            }
        }
    }
    if (a.empty())
        return b[k];
    else if (b.empty())
        return a[k];
    else 
        return min(a[0], b[0]);
}

int main() {
    int n;
    cin >> n;
    vector<int> a;
    srand(time(NULL));

    for (int i = 0; i < n; i++)
        a.push_back(i);
    
    random_shuffle(a.begin(), a.end());
    int split_point;
    do {
        split_point = rand() % n;
    } while((split_point <= 1) || (split_point >= n-2));

    int i;
    vector<int> a1;
    vector<int> a2;
    for (i = 0; i < split_point; i++)
        a1.push_back(a[i]);
    for (; i < n; i++)
        a2.push_back(a[i]);
    
    sort(a1.begin(), a1.end());
    sort(a2.begin(), a2.end());

    for (int i = 0; i < n; i++){
        if (i != kthsmallest(a1, a2, i)) {
            cout << "Didn't find " << i;
            return 1;
        }
    }

    return 0;
}