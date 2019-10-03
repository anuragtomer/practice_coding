/* Can match characters in lower case only.. Have used lowercase macro to define chars starting 
 * from 'a' (97).
 * Need to change that according to our input char set.
 */

#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

#define CHARSETBASE 97 // ASCII of 'a'
#define BIGPRIMENO 15'485'863
#define CHARSETSIZE 26  /* For 26 small chars. 
                         * Change this if you need to include more chars in input pattern.
                         */

bool matchPattern(string pattern, string str, int start) {
    for (int i = 0; (i < pattern.size()) && (i + start < str.size()); i++) {
        if (pattern[i] != str[start + i])
            return false;
    }
    return true;
}

int rabinKarp(string str, string pattern, int radix, int prime) {
    int n = str.size();
    int m = pattern.size();
    int h = 1;
    int p = 0;
    vector<int> t(n-m, 0);
    t[0] = 0;
    for (int i=0; i < m-1; i++) {
        h = (radix * h) % prime;
    }
    for (int i = 0; i < m; i++) {        
        p = (radix*p + pattern[i] - CHARSETBASE) % prime;
        t[0] = (radix*t[0] + str[i] - CHARSETBASE) % prime;
    }   

    // Matching
    for (int s = 0; s <= n - m; s++) {
        if (p == t[s]) {
            // To be sure, match pattern explicitly char by char, so as to eliminate 
            if (matchPattern(pattern, str, s)) {
                return s;
            }
        } else {
            t[s+1] = (radix * (t[s] - (str[s]-CHARSETBASE) * h) + (str[s+m]-CHARSETBASE)) % prime;
        }
    }
    return -1;
}

int main() {
    string str;
    string pattern;
    cin >> str >> pattern;
    int index = rabinKarp(str, pattern, CHARSETSIZE, BIGPRIMENO); // Very big prime no.
    if (index == -1)
        cout << "Pattern not found!!";
    else
        cout << "Pattern found starting at " << index;
    return 0;
}