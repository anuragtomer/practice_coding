#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> vec(n);
  int i = 0;
  int sum = 0;
  while (n--) {
    cin >> vec[i++];
    sum += vec[i - 1];
  }
  sort(vec.begin(), vec.end());
  int j = vec.size() - 1;
  int count = 0;
  int curr = 0;
  sum = sum / 2;
  while (sum >= curr) {
    curr += vec[j--];
    count++;
  }
  cout << count;
  return 0;
}
