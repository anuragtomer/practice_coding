#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int missingNoInArray(vector <int> arr) {
    int sum = 0;
    for (int i: arr) {
        sum += i;
    }
    int array_size = arr.size() + 1;
    return ((array_size * (array_size + 1)) / 2) - sum;
}
};

int main(){
    Solution sol;
    int T, num, val;
cin >> T;
vector <int> arr;
while(T) {
    T--;
    cin >> num;
    arr.clear();
    while(num - 1) {
        cin >> val;
        arr.push_back(val);
        num--;
    }
    cout << sol.missingNoInArray(arr) << endl;
}
return 0;int T, num, val;
cin >> T;
vector <int> arr;
while(T) {
    T--;
    cin >> num;
    arr.clear();
    while(num - 1) {
        cin >> val;
        arr.push_back(val);
        num--;
    }
    cout << sol.missingNoInArray(arr) << endl;
}
return 0;
}
