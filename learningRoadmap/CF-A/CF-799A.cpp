#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, t, k, d;
  cin >> n >> t >> k >> d;
  int min_time_in_one_oven = (n + k - 1) / k;
  int o1 = 0, o2 = d;  // o2 starts functioning at time d. Before that, only
                       // oven 1 is working.
  for (int i = 0; i < min_time_in_one_oven; ++i) {
    if (o1 < o2)
      o1 += t;  // Oven 2 is not ready yet. Bake in 1st.
    else
      o2 += t;  // Oven 2 is ready.
  }
  if (max(o1, o2) < min_time_in_one_oven * t)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
