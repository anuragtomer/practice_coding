#include <iostream>
#include <climits>
using namespace std;

class next_greater{
    public:
    int * smallest_arr;
    next_greater(int size){
        smallest_arr = new int[size];
        fill_n(smallest_arr, size, INT_MAX);
    }

    ~next_greater(){
        delete [] smallest_arr;
    }

    int next_greater_element1(int arr[], int n, int index)
    {
        int smallest = INT_MAX;
        for (int i = index + 1; i < n; i ++)
            if (arr[index] < arr[i] && arr[i] < smallest)
                smallest = arr[i];
        return smallest;
    }

    int find_smallest_arr(int arr[], int n, int index){
        return 0;
    }
    int next_greater_element2(int arr[], int n, int index)
    {
        if (smallest_arr[index] != INT_MAX)
            return smallest_arr[index];
        else 
            return find_smallest_arr(arr, n, index);
    }
};
int main()
{
    int size;
    int queries;
    int index;
    cin >> size;
    next_greater ng(size);
    int * arr = new int[size];
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    cin >> queries;
    for (int i = 0; i < queries; i++) {
        cin >> index;
        cout << ng.next_greater_element1(arr, size, index) << endl;
        cout << ng.next_greater_element2(arr, size, index) << endl;
    }
    delete [] arr;
    return 0;
}
