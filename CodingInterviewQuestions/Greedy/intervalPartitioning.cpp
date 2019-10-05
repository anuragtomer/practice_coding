#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    return a.first < b.first;
}

vector<vector<pair<int, int>>> platformFinder(vector<pair<int, int>> input) {
    sort(input.begin(), input.end(), cmp);
    vector<vector<pair<int, int>>> output;
    output.push_back({input[0]});
    for (int i = 1, k = 0; i < input.size(); i++) {
        bool inserted = false;
        for (int j = 0; j <= k && inserted == false; j++) {            
            if (output[j][output[j].size()-1].second < input[i].first) {
                output[j].push_back(input[i]);
                inserted = true;                
            }
        }
        if (inserted == false) {
            output.push_back({input[i]});
            k++;
        }
    }

    return output;
}

int main() {
    int n;
    cin >>n;
    vector<pair<int, int>> input;
    for (int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;
        input.push_back(make_pair(start, end));
    }
    vector<vector<pair<int, int>>> output;
    output = platformFinder(input);

    for (auto &i: output) {
        cout << "\nPlatform: ";
        for (auto &j: i)
            cout << "\tstart: " << j.first << ", end: " << j.second << endl;
    }
    return 0;
}