#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  int mn = INT_MAX, mx = INT_MIN;
  int orig = n;
  vector<int> vec;
  int i = 0;
  while (n--) {
    int a;
    cin >> a;
    vec.push_back(a);
    if (a < mn) mn = a;
    if (a > mx) mx = a;
  }
  if (mn == mx)
    cout << 0;
  else {
    for (int i = 0; i < vec.size(); ++i)
      if (vec[i] == mn || vec[i] == mx) orig--;
    cout << orig;
  }
  return 0;
}
