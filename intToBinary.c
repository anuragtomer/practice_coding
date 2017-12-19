#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

string binary(int num);
int consec(string s);
int main() {
    int num;
    cin >> num;
    string s = binary(num);
    cout << s << endl;
    int consecutiveOne;
    consecutiveOne = consec(s);
    cout << consecutiveOne << endl;
    return 0;
}

string binary(int num) {
    string s;
    do {
        s.push_back('0' + (num & 1));
    } while (num >>= 1);
    reverse(s.begin(), s.end());
    return s;
}

int consec(string s) {
    int count = 0, max = 0;
    for (auto it = s.cbegin(); it != s.cend(); it++) {
        if (*it == '1'){
            if (count >= 1) {
                count++;
            } else {
                count = 1;
            }
            max = max < count ? count : max;
        } else {
            count = 0;
        }
    }
    return max;
}
