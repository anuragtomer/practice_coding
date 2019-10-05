/*
 * Search elem in arr. Arr is unsorted array.
 * Used heaps to sort the array and then use binary search to find if the elem exists in the arr or not.
 * Input:
 *      arr  : Integer array.
 *      n    : Size of array.
 *      elem : Element to search in array.
 * Output:
 *      index : != -1, if element is found in array.
 *            :  = -1, if element is not found in array.
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int binary_search(vector<int> &arr, int begin, int end, int elem);
int search_element(vector<int> &arr, int n, int elem);

int main() {
    int T = 0; // No of test cases.
    cin >> T;
    while (T > 0) {
        int n = 0; // No of elements in the array.
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int elem = 0; // Element to be searched.
        cin >> elem;
        cout << search_element(arr, n, elem) << endl;
        T--;
    }
    return 0;
}

// Searches 'elem' in 'arr' in index range 'begin' to 'end'
int binary_search(vector <int> &arr, int begin, int end, int elem) {
    if (arr[begin] == elem)
        return begin;
    if (begin > end)
        return -1;
    int mid = (begin + end) / 2;
    if (arr[mid] > elem) 
        return binary_search(arr, begin, mid - 1, elem);
    if (arr[mid] < elem)
        return binary_search(arr, mid + 1, end, elem);
}

// Calls heap_sort to sort arr. Then searches using binary_search.
int search_element(vector <int> &arr, int n, int elem) {
    if (n < 0)
        return -1;
    if (n == 1)
        if (arr[0] == elem)
            return 0;
        else 
            return -1;
    
    make_heap(arr.begin(), arr.end());
    sort_heap(arr.begin(), arr.end());
    return binary_search(arr, 0, n - 1, elem);
}
/*
void heap_sort(vector <int> &arr, int n) {
   vector <int> max_heap(n);
   max_heap.clear();
       make_heap(max_heap.begin(), max_heap.end());

   }
}
*/
