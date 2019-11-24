#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {

    void PrintResult(vector<char> result, int size) {
        for (int i= 0; i <= size; i++)
            cout << result[i];
        cout << "\n";
    }

    /*
     * result - will accumulate chars and print based on level.
     * chars - array of unique chars in given input string.
     * count - arrays of count of unique chars in given input string.
     * level - length of valid chars in result.
     * size - size of given input string.
     */
    
    void lexicographicalString(vector<char> result, 
                               vector<char> chars, 
                               vector<int> count, 
                               int level, 
                               int size) {
        if (level == size) // We have added all the elements in result. Nothing to do here. Return.
            return;
        for(int i = 0; i < chars.size(); i++) {
            if (count[i] == 0) // We don't have any more of this char. 
                continue;
            result[level] = chars[i];
            count[i]--; // Reduce the count as we just added this char in result.
            PrintResult(result, level); // lets print this level before adding more chars in result.
            lexicographicalString(result, chars, count, level+1, size); // Go to next level.
            count[i]++; // We have printed strings using this count. Add it back to our bag of words.
        }
    }
public:
    void Combinations(string str) {
        sort(str.begin(), str.end());
        map<char, int> mp; // Map to save unique char and its count.
        for (auto word: str) {
            if (mp.find(word) != mp.end())
                mp[word]++;
            else
                mp[word] = 1;
        }
        vector<char> chars(mp.size()); // Keeps track of unique chars in input string.
        vector<int> count(mp.size());  // Keeps track of count of each unique char in input string.
        int i = 0;
        for (map<char,int>::iterator it = mp.begin();
            it != mp.end();
            it++, i++) {
            chars[i] = it->first;
            count[i] = it->second;
        }
        vector<char> result(mp.size()); // Will capture string chars in this as we go along.
        lexicographicalString(result, chars, count, 0, str.size());
    }
};

int main() {
    Solution sol;
    string str;
    cin >> str;
    sol.Combinations(str);
    return 0;
}