#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compar(int a, int b) {
    if (a < b)
        return true;
    else 
        return false;
}
int main() {
    int T, N, k;
    cin >> T;
    for (int i = 0; i < T; i ++) {
        cin >> N >> k;
        vector <int> max_heap(N);
        for (int j = 0; j < N; j++) {
            cin >> max_heap[j];
        }
        make_heap(max_heap.begin(), max_heap.end(), compar);
        push_heap(max_heap.begin(), max_heap.end(), compar);
        for (int j = 0; j < k; j++) {
            cout << max_heap.front();
            pop_heap(max_heap.begin(), max_heap.end(), compar);
            max_heap.pop_back();
        }
    }
    return 0;
}
