#include<iostream>

using namespace std;

int findinSortedRotated(int *arr, int low, int high, int elem) {
    int mid;
    while(low <= high) {
        //cout << "Searching between "<< low << " and " << high << endl;
        mid = (low + high) / 2;
        if (arr[mid] == elem) {
            return mid;
        }
        if (arr[mid] >= arr[low]) {
            if (arr[mid] >= elem &&
                arr[low] <= elem) { // element lies in first half.
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } else { // Second half is sorted
            if (arr[mid] <= elem &&
                arr[high] >= elem) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }
    return -1;
}


int main() {
    int n;
    cin >> n;
    int arr[50];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int elem;
    cin >> elem;
    int found = findinSortedRotated(arr, 0, n-1, elem);
    if (found == -1) {
        cout << "Not found";
    } else {
        cout << "Found at " << found;
    }
    return 0;
}