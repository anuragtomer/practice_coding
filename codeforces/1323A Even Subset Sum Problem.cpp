#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  while (n > 0) {
    n--;
    int currsize;
    cin >> currsize;
    vector<int> vec;
    int output = -1;
    for (int i = 0; i < currsize; i++) {
      int a;
      cin >> a;
      if (a % 2 == 0) output = i + 1;
      vec.push_back(a);
    }
    if (output != -1)
      cout << "1\n" << output << "\n";
    else if (vec.size() > 1)
      cout << "2\n1 2\n";
    else
      cout << "-1\n";
  }
  return 0;
}