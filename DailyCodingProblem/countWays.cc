#include <iostream>
#include <vector>

using namespace std;

// void createStrings(string input, vector<string> &result, string running) {
//     if (input.empty()) {
//         if (!running.empty())
//             result.push_back(running);
//         return;
//     }
//     running.push_back(97 + (input[0] - '0'));
//     createStrings(input, result, running);
//     running.pop_back();
//     if (input[0] == '1' || (input[0] == '2' && input[1] <= '6'))
//         int num = atoi(input.substr(0, 2).to_str());
// }
// int countWays(string input) {
//     vector<string> result;
//     string running;
//     createStrings(input, result, running);
//     return result.size();
// }

// returns 1 if possible to decode string.
int canDecode(string s) {
    if (s[0] == '0') {
        return 0;
    }
    int num = stoi(s);
    if (num >= 0 && num <= 26) {
        return 1;
    }
    return 0;
}
int solution(string s) {
    bool firstZero = s[0] == '0';
    size_t sz = s.size();
    switch (sz) {
        case 1:
            return canDecode(s);
        case 2:
            if (firstZero)
                return canDecode(s);
            return canDecode(s) + 1;
        default:
            return canDecode(string(s.begin(), s.begin() + 1)) * solution(string(s.begin() + 1, s.end())) +
                   canDecode(string(s.begin(), s.begin() + 2)) * solution(string(s.begin() + 2, s.end()));
    }
}
int main() {
    string input = "111";
    cout << solution(input) << endl;
    assert(3 == solution(input));
    input = "777";
    assert(1 == solution(input));
    return 0;
}
