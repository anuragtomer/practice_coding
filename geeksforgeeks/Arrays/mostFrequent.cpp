#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
public:
    string mostFrequent(vector <string> arr) {
        unordered_map <string, int> hash;
        string word = arr[0];
        unordered_map <string, int>::iterator it;
        int max = INT_MIN;
        for(string str: arr) {
            it = hash.find(str);
            if (it == hash.end()) {
                hash.insert({str, 1});
                if (max <= 1) {
                    word = str;
                    max = 1;
                }
            } else {
                it->second++;
                if (it->second >= max) {
                    word = it->first;
                    max = it->second;
                }
            }
        }
        return word;
    }
};

int main(){
    Solution sol;
    int T;
    cin >> T;
    while(T) {
        int num;
        cin >> num;
        vector <string> arr;
        arr.clear();
        while(num) {
            string str;
            cin >> str;
            arr.push_back(str);
            num--;
        }
        cout << sol.mostFrequent(arr) << endl;
        T--;
    }
    return 0;
}
