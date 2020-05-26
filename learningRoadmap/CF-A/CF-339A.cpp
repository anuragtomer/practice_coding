#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  int one = 0, two = 0, three = 0;
  for (auto c : s) {
    if (c == '1') one++;
    if (c == '2') two++;
    if (c == '3') three++;
  }
  s = "";

  while (one--) {
    cout << 1;
    if (one || two + three > 0) cout << "+";
  }
  while (two--) {
    cout << 2;
    if (two || three > 0) cout << "+";
  }
  while (three--) {
    cout << 3;
    if (three) cout << "+";
  }
  return 0;
}
