#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s;
  getline(cin, s);
  set<char> st;
  for (auto c : s)
    if (c >= 97 && c <= 122) st.insert(c);
  cout << st.size();
  return 0;
}
