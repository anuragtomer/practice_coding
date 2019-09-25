#include <iostream>
#include <vector>

using namespace std;

int maxDiff(vector<int> arr) {
    int currmin = INT_MAX;
    int maxdiff = INT_MIN;
    for (auto &i: arr) {
        if (i < currmin)
            currmin = i;
        if ((i - currmin) > maxdiff)
            maxdiff = i - currmin;
    }
    return maxdiff;
}

int main() {
    vector<int> arr;
    arr.push_back(7);
    arr.push_back(9);
    arr.push_back(5);
    arr.push_back(6);
    arr.push_back(3);
    arr.push_back(2);
    cout << maxDiff(arr);
    
    return 0;
}