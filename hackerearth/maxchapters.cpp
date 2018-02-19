#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
int sos(vector <int> tm1, int index, int timeLeft) {
    if (timeLeft <= 0 || tm1.size() <= index)
        return 0;
    int sum1 = 0, sum2 = 0;
    sum1 = sos(tm1, index+1, timeLeft);
    if (timeLeft >= tm1[index])
        sum2 = 1 + sos(tm1, index+1, timeLeft - tm1[index]);
    return (sum1 > sum2 ? sum1 : sum2);
}
int examRush(vector <int> tm, int t) {
    if (t <=0 || tm.size() == 0)
        return 0;
    int sum1 = sos(tm, 1, t);
    
    int sum2 = 0;
    if (t >= tm[0])
        sum2 = 1 + sos(tm, 1, t-tm[0]);
    return (sum1 > sum2? sum1:sum2);
}
*/
int examRush(vector <int> tm, int t) {
    sort(tm.begin(), tm.end());
    for(int tm_i = 0; tm_i < tm.size(); tm_i++){
       cout << tm[tm_i];
    }
    int i = 0;
    for (i = 0; i < tm.size(); i++)
        if (t < tm[i])
            t = t - tm[i];
        else
            break;
    return i;
}

int main() {
    int n;
    int t;
    cin >> n >> t;
    vector<int> tm(n);
    for(int tm_i = 0; tm_i < n; tm_i++){
       cin >> tm[tm_i];
    }
    int result = examRush(tm, t);
    cout << result << endl;
    return 0;
}
