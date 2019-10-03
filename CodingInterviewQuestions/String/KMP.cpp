#include <iostream>
#include <string>
#include <vector>

using namespace std;


/*
    Alternate prefixTable:-
    =====================

void 
prefixTable(vector<int> &F, const string pattern) {
    int m = pattern.size();
    F.push_back(0);
    int i = 1;
    int j = 0;
    while(i < m) {
        if (pattern[i] == pattern[j]) {
            F[i] = j+1;
            i++;
            j++;
        } else if (j > 0) {
            j = F[j-1];
        } else {
            F[i] = 0;
            i++;
        }
    }
}
*/
vector<int>  
prefixTable(const string pattern) {
    int m = pattern.size();
    vector<int> F(m, 0);
    int matched = 0;
    for (int q = 1; q < m; q++) {
        if (pattern[matched] == pattern[q]) {
            matched++;
            F[q] = matched;
        } else {
            if (matched != 0) {
                matched = F[matched - 1];
                q--;
            } else
                F[q] = 0;
        }
    }
    return F;
}


int
KMP(string str, string pattern) {
    vector<int> F;
    F = prefixTable(pattern);
    int i = 0, j = 0;
    int m = pattern.size();
    int n = str.size();    
    while (i < n) {
        if (str[i] == pattern[j]) {
            i++;
            j++;
        }
        if (j == m)
            return i-j;
        else if (i < n && pattern[j] != str[i]) {
            if (j != 0) 
                j = F[j-1];
            else
                i++;
        }
    }

/*  Alternate loop:
    ==============
    for (i = 0; i < n; i++) {
        while (j > 0 && pattern[j] != str[i]) {
            j = F[j-1];
        }
        if (str[i] == pattern[q]) {
            j++;
        }
        if (q == m) {
            return i-m;
        }
    } */
    return -1;
}
int main() {
    string str;
    string pattern;
    cin >> str >> pattern;
    int index = KMP(str, pattern);
    if (index == -1)
        cout << "Pattern not found!!";
    else
        cout << "Pattern found starting at " << index;
    return 0;
}