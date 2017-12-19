#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int N, Q;
    string str;
    cin >> N;
    unordered_map<string, int> dict;
    for (int i = 0; i < N; i++) {
        cin >> str;
        unordered_map<string, int>::iterator got = dict.find(str);
        if (got == dict.end())
            dict.insert({str, 1});
        else
            got->second++;
    }
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        cin >> str;
        unordered_map<string, int>::iterator got = dict.find(str);
        if (got == dict.end())
            cout << 0 << endl;
        else
            cout << got->second << endl;
    }
    return 0;
}
