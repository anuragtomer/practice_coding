#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s1, s2;
  cin >> s1;
  cin >> s2;
  if (s1.compare(s2) == 0)
    cout << -1;
  else if (s1.size() < s2.size())
    cout << s2.size();
  else
    cout << s1.size();
  return 0;
}
