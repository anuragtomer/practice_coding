#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> vec(n + 1);
  for (int i = 1; i <= n; ++i) cin >> vec[i];
  int shots;
  cin >> shots;
  while (shots--) {
    int a, b;
    cin >> a >> b;
    if (a != 1) vec[a - 1] += b - 1;
    if (a != n) vec[a + 1] += vec[a] - b;
    vec[a] = 0;
  }
  for (int i = 1; i <= n; ++i) cout << vec[i] << endl;
  return 0;
}
