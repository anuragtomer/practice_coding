#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int n, h;
  cin >> n >> h;
  int w = 0;
  int a;
  while (n)
  {
    n--;
    cin >> a;
    if (a > h)
      w += 2;
    else
      w++;
  }
  cout << w;
  return 0;
}
