#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  while (n--) {
    string s;
    cin >> s;
    if (s.size() > 10)
      cout << s.front() << to_string(s.size() - 2) << s.back() << "\n";
    else
      cout << s << "\n";
  }
  return 0;
}
