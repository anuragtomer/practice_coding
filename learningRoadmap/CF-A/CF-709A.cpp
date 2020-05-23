#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, b, d;
  cin >> n >> b >> d;
  vector<int> vec(n);
  int i = 0;
  int ans = 0;
  int curr = 0;
  while (n--) {
    cin >> vec[i++];
    if (vec[i - 1] <= b) curr += vec[i - 1];
    if (curr > d) {
      ans++;
      curr = 0;
    }
  }
  cout << ans;
  return 0;
}
