#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    return (a.second < b.second);
}

vector<pair<int, int>> intervalScheduling(vector<pair<int, int>> input) {
    sort(input.begin(), input.end(), cmp);
    vector<pair<int, int>> output;
    output.push_back(input[0]);
    for (int i = 1, k = 0; i < input.size(); i++) {
        if (output[k].second < input[i].first) {
            output.push_back(input[i]);
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
    vector<pair<int, int>> output;
    output = intervalScheduling(input);

    for (auto &i: output) {
        cout << "start: " << i.first << ", end: " << i.second << endl;
    }
    return 0;
}