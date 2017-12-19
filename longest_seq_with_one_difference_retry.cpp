#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>

using namespace std;

int find_longest_one_diff_seq(vector <int> arr) {
    unordered_map<int, int> hash_map;
    unordered_map<int, int>::iterator it;
    int max = INT_MIN, len;
    for (int i = 0; i < arr.size(); i ++) {
        len = 0;

        it = hash_map.find(arr[i] - 1);
        if (it != hash_map.end() && it->second > len)
            len = it->second;

        it = hash_map.find(arr[i] + 1);
        if (it != hash_map.end() && it->second > len)
            len = it->second;

        it = hash_map.find(arr[i]);
        if (it != hash_map.end() && it->second < len + 1)
            it->second = len + 1;
        else if (it == hash_map.end())
            hash_map.insert({arr[i], len + 1});

        if (max < len + 1)
            max = len + 1;
    }
    return max;
}

int main() {
    int T, N, value;
    cin >> T;
    while(T--){
        cin >> N;
        vector<int> arr;
        while(N--) {
            cin >> value;
            arr.push_back(value);
        }
        cout << find_longest_one_diff_seq(arr) << endl;
    }
    return 0;
}
