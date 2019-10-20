#include <iostream>
#include <vector>

using namespace std;

pair<int, int> 
findSum(vector<int> vec, int sum) {
    int start = 0, i, currSum = vec[0];
    for (i = 1; i <= vec.size(); ++i) {
        while(currSum > sum && start <= i) {
            currSum -= vec[start];
            start++;
        }
        if (currSum == sum) {
            return {start+1, i};
        }
        if (i < vec.size())
            currSum += vec[i];
    }
    return {-1, -1};
}

int main()
{
    int T;
    cin >> T;
    while(T--) {
        int n, S;
        cin >> n >> S;
        vector<int> vec(n);
        for (int i = 0; i < n; i++) 
            cin >> vec[i];
        pair<int, int> indices = findSum(vec, S);
        if (indices.first != -1)
            cout << indices.first << " " << indices.second << '\n';
        else
            cout << "-1\n";
    }
	return 0;
}