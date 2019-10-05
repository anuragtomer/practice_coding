#include<iostream>
#include <vector>

using namespace std;

void shell(vector<int> &A) {
    for(int gap = A.size() / 2; gap > 0; gap /= 2) {
        for(int i = gap; i < A.size(); i++) {
            int temp = A[i];
            int j;
            for (j = i; j >= gap && A[j-gap] > temp; j -= gap)
                A[j] = A[j-gap];
            A[j] = temp;
        }
    }
}

int main() {
    vector<int> input;
    int a;
    while(cin>>a) {
        input.push_back(a);
    }
    shell(input);
    for(auto &i: input) {
        cout << i << " ";
    }
    return 0;
}