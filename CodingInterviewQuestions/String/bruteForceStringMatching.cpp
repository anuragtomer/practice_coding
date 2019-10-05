#include <iostream>
#include <string>

using namespace std;
int bruteForce(string str, string pattern) {
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == pattern[0]) {
            bool match = true;
            int j = 0;
            for (j = 0; (j < pattern.size()) && ((i + j) < str.size()); j++) {
                if (str[i+j] != pattern[j]) {
                    match = false;
                }
            }
            if (j == pattern.size() && match == true) {
                return i;
            }
        }
    }
    return -1;
}

int main() {
    string str;
    string pattern;
    cin >> str >> pattern;
    int index = bruteForce(str, pattern);
    if (index == -1)
        cout << "Pattern not found!!";
    else
        cout << "Pattern found starting at " << index;
    return 0;
}