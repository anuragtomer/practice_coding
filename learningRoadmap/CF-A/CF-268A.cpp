#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  map<int, int> host;
  map<int, int> guest;
  int n;
  cin >> n;
  while (n--) {
    int a, b;
    cin >> a >> b;
    host[a]++;
    guest[b]++;
  }
  int res = 0;
  for (auto a : host) {
    res += (guest[a.first] * a.second);
  }
  cout << res;
  return 0;
}
