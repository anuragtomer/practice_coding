#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /* one - print 'A'
     * two - ctrl-A + ctrl-C
     * three - ctrl-V
     * Find max 'A' you can print with N keystrokes.
     */
    int specialKeyboard(int screen, int buffer, int N) {
        if (N <= 0)
            return screen;
        int one = 0, two = 0, three = 0;
        one = specialKeyboard(screen + 1, buffer, N - 1);
        if (screen > 0)
            two = specialKeyboard(screen, screen, N - 2);
        three = specialKeyboard(screen + buffer, buffer, N - 1);
        return max(one, max(two, three));
    }
    int specialKeyboard(int N) {
        if (N > 75)
            return -1;
        return specialKeyboard(0, 0, N);
    }
};

int main(){
    Solution sol;
    int T;
    cin >> T;
    while(T) {
        int val;
        cin >> val;
        cout << sol.specialKeyboard(val) << endl;
        T--;
    }
    return 0;
}
