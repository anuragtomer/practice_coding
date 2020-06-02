#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  if (n < 26) {
    cout << "NO";
    return 0;
  } else {
    vector<int> vec(26, 0);
    for (auto c : s) {
      if (c >= 97)
        vec[c - 'a']++;
      else
        vec[c - 'A']++;
    }
    for (auto v : vec) {
      if (v == 0) {
        cout << "NO";
        return 0;
      }
    }
  }
  cout << "YES";
  return 0;
}
