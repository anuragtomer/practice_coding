#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool ransom_note(vector<string> magazine, vector<string> ransom) {

    unordered_map<string, int> mag;
    unordered_map<string, int>::iterator got;
    for (int mag_j = 0; mag_j != magazine.size(); mag_j++) {
        got = mag.find(magazine[mag_j]);
        if (got == mag.end())
            mag.insert({magazine[mag_j], 1});
        else
            got->second++;
    }
    for (int ran_i = 0; ran_i != ransom.size(); ran_i++) {
        got = mag.find(ransom[ran_i]);
        if (got != mag.end()) {
            got->second--;
            if (got->second == 0) {
                mag.erase(got->first);
            }
        } else {
            return false;
        }
    }
    return true;
}
int main(){
    int m;
    int n;
    cin >> m >> n;
    vector<string> magazine(m);
    for(int magazine_i = 0;magazine_i < m;magazine_i++){
        cin >> magazine[magazine_i];
    }
    vector<string> ransom(n);
    for(int ransom_i = 0;ransom_i < n;ransom_i++){
        cin >> ransom[ransom_i];
    }

    if(ransom_note(magazine, ransom))
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}

