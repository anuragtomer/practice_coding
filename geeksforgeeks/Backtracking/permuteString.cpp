#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void permute(vector <char> Output, int curr, string input) {
        if (curr == input.size()) {
            for (char a : Output)
                cout << a;
            cout << endl;
            return;
        }
        for (int i = 0; i < input.size(); i++) {
            if (Output[i] == '1') {
                Output[i] = input[curr];
                permute(Output, curr + 1, input);
                Output[i] = '1';
            }
        }
    }
};

int main(){
    Solution sol;
    int T;
    cin >> T;
    while(T) {
        string num;
        cin >> num;
        vector <char> Output (num.size(), '1');
        sol.permute(Output, 0, num);
        T--;
    }
    return 0;
}
