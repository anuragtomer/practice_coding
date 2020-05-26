#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  cin >> n >> k;
  string s;
  char c = 'a';
  n = n - k;
  while (k--) {
    s.push_back(c);
    c++;
  }
  while (n--) {
    char newc = s[s.size() - 2];
    s.push_back(newc);
  }
  cout << s;
  return 0;
}
