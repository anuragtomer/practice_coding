#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> gifts(n + 1);
  int i = 1;
  while (n--) {
    int a;
    cin >> a;
    gifts[a] = i;
    i++;
  }
  for (int a = 1; a < gifts.size(); ++a) {
    cout << gifts[a] << " ";
  }
  return 0;
}
