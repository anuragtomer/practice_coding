#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumSumIncreasingSubsquence(vector <int> arr) {
        vector <int> max;
        max.clear();
        for (int i: arr) {
            max.push_back(i);
        }
        for (int i = 1; i < arr.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (arr[i] > arr[j] && (max[i] < max[j] + arr[i])) {
                    max[i] = max[j] + arr[i];
                }
            }
        }
        int msis = -1;
        for (int i: max) {
            if (msis < i)
                msis = i;
        }
        return msis;
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
        cout << sol.maximumSumIncreasingSubsquence(arr) << endl;
        T--;
    }
    return 0;
}
