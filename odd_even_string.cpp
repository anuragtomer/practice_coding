#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int T, i;
    string str, streven, strodd;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    cin >> T;
    while (T > 0) {        
        cin >> str;
        i = 1;
        for (auto it=str.cbegin(); it!=str.cend(); ++it) {            
            if (i % 2 == 0) {
                streven.push_back(*it);
            } else {
                strodd.push_back(*it);
            }
            i++;
        }
        cout << strodd << " " << streven << endl;
        strodd.clear();
        streven.clear();
        T--;
    }
    return 0;
}

