#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int a;
  set<int> hash;
  for (int i = 0; i < 4; i++) {
    cin >> a;
    hash.insert(a);
  }
  cout << 4 - hash.size();
  return 0;
}
