#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> one, two, three;
  int idx = 1;
  while (n--) {
    int i;
    cin >> i;
    if (i == 1) {
      one.push_back(idx);
    }
    if (i == 2) {
      two.push_back(idx);
    }
    if (i == 3) {
      three.push_back(idx);
    }
    idx++;
  }
  cout << min({one.size(), two.size(), three.size()}) << "\n";
  while (one.size() != 0 && two.size() != 0 && three.size() != 0) {
    cout << one.back() << " " << two.back() << " " << three.back() << "\n";
    one.pop_back();
    two.pop_back();
    three.pop_back();
  }
  return 0;
}
