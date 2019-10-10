#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<vector<string>>
findAnagrams(vector<string> dictionary) {
    unordered_map<string, vector<string>> hash;

    for (int i = 0; i < dictionary.size(); ++i) {
        unordered_map<string, vector<string>>::iterator it;
        string temp = dictionary[i];
        sort(temp.begin(), temp.end());
        it = hash.find(temp);
        if (it == hash.end()) {
            vector<string> abc;
            abc.push_back(dictionary[i]);
            hash.insert(make_pair(temp, abc));
        } else {
            it->second.push_back(dictionary[i]);
        }
    }
    vector<vector<string>> output;
    for (auto &i: hash) {
        output.push_back(i.second);
    }
    return output;
}

int main(void) {
    int n;
    cin >> n;
    vector<string> dictionary(n);
    string words;
    for (int i = 0; i < n; i++) {
        cin >> words;
        dictionary[i] = words;
    }
    vector<vector<string>> anagrams = findAnagrams(dictionary);
    for (auto i: anagrams) {
        cout <<"\nAnagrams: ";
        for (auto j: i) {
            cout << j << " ";
        }
    }
    return 0;
}