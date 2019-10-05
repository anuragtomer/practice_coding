#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
     /* Find element which is not in pair (all pairs are adjacently placed.) */
    int findOne(vector <int> arr) {
        for (int i = 0; i < arr.size(); i++) {
            if (i + 1 < arr.size() && arr[i] == arr[i + 1]) {
                i++;
            } else {
                return arr[i];
            }
        }
        return 0;
    }
};

int main(){
    Solution sol;
    int T;
    cin >> T;
    while(T) {
        int num;
        cin >> num;
        vector <int> arr;
        arr.clear();
        while(num) {
            int val;
            cin >> val;
            arr.push_back(val);
            num--;
        }
        cout << sol.findOne(arr) << endl;
        T--;
    }
    return 0;
}
