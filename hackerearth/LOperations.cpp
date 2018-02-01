#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int safe_unsafe(int x) {
    switch(x) {
        case 1: return 1;
        case 2: return -1;
        case 3: return -1;
        case 4: return -1;
        case 5: return -1;
        case 6: return 1;
        case 7: return -1;
        case 8: return -1;
        case 9: return 1;
        case 10: return 1;
    }
    return -1;
}
int main() {
    int N, L;
    cin >> N;
    cin >> L;
    vector <int> input;
    int a;
    input.clear();
    while(N) {
        cin >> a;
        input.push_back(a);
        N--;
    }

    sort(input.begin(), input.end());
    for (int i = 1; i <= L; i++) {
        int safe = safe_unsafe(i);
        if (safe == 1) {
            input.at(input.size() - 1) = input[input.size() - 1] * 2;
        } else {
            input.at(0) = input[0] / 2;
            if (input[0] == 0) {
                input.erase(input.begin());
            }
        }
    }
    cout << input.size();
    for (int i = 0; i < input.size(); i ++)
        cout << input[i] << " ";
}
