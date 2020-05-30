#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  if (n == 1) {
    cout << "0 0";
    return 0;
  }
  vector<int> arr(n);
  int i = 0;
  while (n--) {
    cin >> arr[i];
    i++;
  }
  n = arr.size() - 1;
  int mn, mx;
  for (int i = 0; i <= n; ++i) {
    if (i == 0) {
      mn = abs(arr[i] - arr[i + 1]);
      mx = abs(arr[i] - arr[n]);
    } else if (i == n) {
      mn = abs(arr[i - 1] - arr[i]);
      mx = abs(arr[0] - arr[i]);
    } else {
      mn = min(abs(arr[i] - arr[i + 1]), abs(arr[i - 1] - arr[i]));
      mx = max(abs(arr[0] - arr[i]), abs(arr[i] - arr[n]));
    }
    cout << mn << " " << mx << "\n";
  }
  return 0;
}
