#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int a, b, mx;
  cin >> a >> b;
  mx = max(a, b); /*
   switch (mx) {
     case 1:
       cout << "1/1";
       break;
     case 2:
       cout << "5/6";
       break;
     case 3:
       cout << "2/3";
       break;
     case 4:
       cout << "1/2";
       break;
     case 5:
       cout << "1/3";
       break;
     case 6:
       cout << "1/6";
       break;
   } */
  int ans = 7 - max(a, b);
  if (6 % ans == 0) {
    cout << 1 << '/' << 6 / ans
         << endl;  // This covers cases 1/1, 1/3, 1/2, 1/6.
  } else if (ans == 4) {
    cout << 2 << '/' << 3 << endl;  // This covers case 2/3.
  } else {
    cout << ans << '/' << 6 << endl;  // This covers case 5/6.
  }
  return 0;
}
