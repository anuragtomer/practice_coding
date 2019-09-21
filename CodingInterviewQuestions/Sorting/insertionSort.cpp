#include<iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int> &A) {
    for(int i = 0; i < A.size(); i++) {
        int temp = A[i];
        int j;
        for (j = i-1; j >= 0 && A[j] > temp; j--)
            A[j+1] = A[j];
        A[j+1] = temp;
    }
}

int main() {
    vector<int> input;
    int a;
    while(cin>>a) {
        input.push_back(a);
    }
    insertionSort(input);
    for(auto &i: input) {
        cout << i << " ";
    }
    return 0;
}