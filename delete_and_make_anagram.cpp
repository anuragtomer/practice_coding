#include <iostream>
#include <vector>

using namespace std;

int number_needed(string a, string b) {
    size_t found;
    int count = 0, matches = 0, size_astring = a.size();

    for (int i = 0; i < b.size(); i++) {
        found = a.find(b[i]);
        if (found == string::npos)
            count++;
        else {
            matches++;
            a.erase(a.begin() + found);
        }
    }
    return count + size_astring - matches;

}
int main() {
    string a;
    cin >> a;
    string b;
    cin >> b;
    cout << number_needed(a, b) << endl;
    return 0;
}
