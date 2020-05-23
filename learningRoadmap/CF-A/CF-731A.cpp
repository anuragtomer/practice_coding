#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  int start = 0;
  int moves = 0;
  for (auto c : s) {
    int index = c - 97;
    int walk = abs(start - index);
    if (walk > 13)
      moves += 26 - walk;
    else
      moves += walk;
    start = index;
  }
  cout << moves;
  return 0;
}
