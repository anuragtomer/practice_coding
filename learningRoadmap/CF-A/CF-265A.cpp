#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s, t;
  cin >> s >> t;
  int i = 0;
  for (int j = 0; j < t.size(); ++j)
    if (t[j] == s[i]) i++;
  cout << i + 1;
  return 0;
}
