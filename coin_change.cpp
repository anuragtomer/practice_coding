#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

long long find_ways (vector< vector<long long>> &S, vector<int> coins, int money, int index) {
    if (money < 0)
        return 0;
    if (money == 0)
        return 1;
    if (index < 0)
        return 0;
    if (S[money][index] != -1)
        return S[money][index];
    long long a = find_ways(S, coins, money, index - 1);
    long long b = find_ways(S, coins, money - coins[index], index);
    S.at(money).at(index) = a + b;
    return S[money][index];
}

int make_change(vector<int> coins, int money) {
    int index = coins.size();
    vector<vector <long long>> S (money + 1, vector<long long> (index));
    for (int i = 0; i <= money; i++)
        for (int j = 0; j < index; j++)
            S.at(i).at(j) = -1;
    return find_ways(S, coins, money, index - 1);
}

int main(){
    int n;
    int m;
    cin >> n >> m;
    vector<int> coins(m);
    for(int coins_i = 0;coins_i < m;coins_i++){
        cin >> coins[coins_i];
    }
    cout << make_change(coins, n) << endl;
    return 0;
}
