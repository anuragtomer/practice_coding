#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, x;
  cin >> n >> x;
  long long count = 0;
  while (n--) {
    char c;
    long long num;
    cin >> c;
    cin >> num;
    if (c == '+') {
      x += num;
    } else if (x >= num)
      x -= num;
    else
      count++;
  }
  cout << x << " " << count;
  return 0;
}
