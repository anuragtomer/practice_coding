#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <iomanip>

using namespace std;

bool compar(int i, int j) {
    if (i < j)
        return false;
    else
        return true;
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> min_heap(n);
    min_heap.clear();
    vector<int> max_heap(n);
    max_heap.clear();
    for(int a_i = 0; a_i < n; a_i++) {
        cin >> a[a_i];
        if (a_i == 1){
            // There are two elements. Push higher number to min_heap and
            // smaller number to max_heap
            if (a[0] < a[1]) {
                max_heap.push_back(a[0]); 
                make_heap(max_heap.begin(), max_heap.end());
                push_heap(max_heap.begin(), max_heap.end());
                min_heap.push_back(a[1]); 
                make_heap(min_heap.begin(), min_heap.end(), compar);
                push_heap(min_heap.begin(), min_heap.end(), compar);
            } else {
                min_heap.push_back(a[0]); 
                make_heap(min_heap.begin(), min_heap.end(), compar);
                push_heap(min_heap.begin(), min_heap.end(), compar);
                max_heap.push_back(a[1]);
                make_heap(max_heap.begin(), max_heap.end());
                push_heap(max_heap.begin(), max_heap.end());
            }
            cout << setprecision(1) << fixed << ((float)min_heap.front() + (float)max_heap.front())/2 << endl;
        } else if (a_i > 1) {
            // There are more than 2 elements.
            // If the new incoming guy is smaller than top of max_heap, push it there.
            // If the new incoming guy is bigger than top of max_heap, push it to min_heap.
            // This would cause min disruption in the heap. The top would not change as
            // part of insertion.
            if (a[a_i] < max_heap.front()) {
                max_heap.push_back(a[a_i]);
                push_heap(max_heap.begin(), max_heap.end());
            } else {
                min_heap.push_back(a[a_i]);
                push_heap(min_heap.begin(), min_heap.end(), compar);
            }
            int min_size, max_size;
            min_size = min_heap.size();
            max_size = max_heap.size();
            // If the heap sizes differ by more than 1, make them equal. 
            // pop top from the heap having more elements and push them to the other guy.
            if (min_size - max_size > 1) {
                max_heap.push_back(min_heap.front());
                push_heap(max_heap.begin(), max_heap.end());
                pop_heap(min_heap.begin(), min_heap.end(), compar);
                min_heap.pop_back();
                cout << setprecision(1) << fixed << ((float)min_heap.front() + (float)max_heap.front())/2 << endl;
            } else if (max_size - min_size > 1) {
                min_heap.push_back(max_heap.front());
                push_heap(min_heap.begin(), min_heap.end(), compar);
                pop_heap(max_heap.begin(), max_heap.end());
                max_heap.pop_back();           
                cout << setprecision(1) << fixed << ((float)min_heap.front() + (float)max_heap.front())/2 << endl;
            } else if (min_size > max_size) {
                cout << setprecision(1) << fixed << (float)min_heap.front() << endl;
            } else if (min_size < max_size) {
                cout << setprecision(1) << fixed << (float)max_heap.front() << endl;
            } else if (min_size == max_size) {
                cout << setprecision(1) << fixed << ((float)min_heap.front() + (float)max_heap.front())/2 << endl;
            }
        } else {
            cout << a[a_i];
        }
    }
    return 0;
}
