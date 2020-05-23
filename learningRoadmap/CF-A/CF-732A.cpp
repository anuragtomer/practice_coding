#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int k, r;
  cin >> k >> r;
  k = k % 10;
  if (k == 0)
    cout << 1;
  else
    for (int i = 1; i <= 10; i++) {
      if (((k * i) % 10 == r) || ((k * i) % 10 == 0)) {
        cout << i;
        break;
      }
    }
  return 0;
}
