#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    struct node {
        char c;
        int val;
    };
    bool check(node iCMap[], int unique, string s1, string s2, string s3) {
        int i1 = 0, i2 = 0, i3 = 0, m = 1;
        for (int i = s1.size() - 1; i >= 0; i--) {
            for (int j = 0; j < unique; j++) {
                if (iCMap[j].c == s1[i]) {
                    i1 += (m * iCMap[j].val);
                    m *= 10;
                    break;
                }
            }
        }
        m = 1;
        for (int i = s2.size() - 1; i >= 0; i--) {
            for (int j = 0; j < unique; j++) {
                if (iCMap[j].c == s2[i]) {
                    i2 += (m * iCMap[j].val);
                    m *= 10;
                    break;
                }
            }
        }
        m = 1;
        for (int i = s3.size() - 1; i >= 0; i--) {
            for (int j = 0; j < unique; j++) {
                if (iCMap[j].c == s3[i]) {
                    i3 += (m * iCMap[j].val);
                    m *= 10;
                    break;
                }
            }
        }
        if ((i1 + i2) == i3)
            return true;
        return false;
    }
    void printCompleteArray(node iCMap[], int unique, string s1, string s2, string s3) {
        cout << endl;
        for (int i = 0; i < s1.size(); i++) {
            for (int j = 0; j < unique; j++) {
                if (iCMap[j].c == s1[i])
                    cout << iCMap[j].val;
            }
        }
        cout << " + ";
        for (int i = 0; i < s2.size(); i++) {
            for (int j = 0; j < unique; j++) {
                if (iCMap[j].c == s2[i])
                    cout << iCMap[j].val;
            }
        }
        cout << " = ";
        for (int i = 0; i < s3.size(); i++) {
            for (int j = 0; j < unique; j++) {
                if (iCMap[j].c == s3[i])
                    cout << iCMap[j].val;
            }
        }
    }
    bool permute(node iCMap[], int unique, int curr, string s1, string s2, string s3, vector <bool> inuse) {
         /* BASE CASE */
        if (unique == curr + 1) {
            for (int i = 0; i < 10; i++) {
                if (inuse[i] == false) {
                    iCMap[curr].val = i;
                    if (check(iCMap, unique, s1, s2, s3)) {
                        cout << "Solution exists";
                        printCompleteArray(iCMap, unique, s1, s2, s3);
                        return true;
                    }
                }
            }

            return false;
        }
        for (int i = 0; i < 10; i++) {
            if (inuse[i] == false) {
                iCMap[curr].val = i;
                inuse[i] = true;
                if (permute(iCMap, unique, curr + 1, s1, s2, s3, inuse)) {
                    return true;
                }
                inuse[i] = false;
            }
        }
        return false;
    }
     /* REST CASE */
    bool crypt(string s1, string s2, string s3) {
        vector <bool> inuse(10, false);
        vector <int> alpha(26, 0);
        int i, unique = 0;
        for (i = 0; i < s1.size(); i++) {
            alpha[s1[i] - 'A']++;
        }
        for (i = 0; i < s2.size(); i++) {
            alpha[s2[i] - 'A']++;
        }
        for (i = 0; i < s3.size(); i++) {
            alpha[s3[i] - 'A']++;
        }
        for (i = 0; i < 26; i++) {
            if (alpha[i] != 0)
                unique++;
        }
        if (unique > 10)
            return false;
        node iCMap[unique];
        int j = 0;
        for (i = 0; i < 26; i++) {
            if (alpha[i] != 0)
                iCMap[j++].c = 'A' + i;
        }
        return permute(iCMap, unique, 0, s1, s2, s3, inuse);
    }
};

int main(){
    Solution sol;
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    sol.crypt(s1, s2, s3);
    return 0;
}
