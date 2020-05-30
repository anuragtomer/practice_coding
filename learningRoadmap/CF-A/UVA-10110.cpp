#include <math.h>

#include <iostream>
using namespace std;
int main() {
  unsigned int n;
  cin >> n;
  while (n != 0) {
    unsigned int sq = (int)sqrt(n);
    cout << (sq * sq == n ? "yes\n" : "no\n");
    cin >> n;
  }
  return 0;
}