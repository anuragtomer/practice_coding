#include <iostream>
#include <vector>

using namespace std;

int canDecode(string s) {
    if (s[0] == '0')
        return 0;
    int num = stoi(s);
    if (num >= 0 && num <= 26)
        return 1;
    return 0;
}
int countWays(string s) {
    size_t sz = s.size();
    switch (sz) {
        case 1:
            return canDecode(s);
        case 2:
            if (s[0] != '0')
                return canDecode(s) + 1;
            return canDecode(s);
        default:
            return canDecode(string(s.begin(), s.begin() + 1)) * countWays(string(s.begin() + 1, s.end())) +
                   canDecode(string(s.begin(), s.begin() + 2)) * countWays(string(s.begin() + 2, s.end()));
    }
}

int main() {
    string input = "111";
    assert(3 == countWays(input));
    input = "777";
    assert(1 == countWays(input));
    return 0;
}
