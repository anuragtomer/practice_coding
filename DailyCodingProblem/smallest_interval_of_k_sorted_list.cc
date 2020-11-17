#include <iostream>
#include <vector>

using namespace std;

pair<int, int> smallest_interval_of_k_sorted_list(const vector<vector<int>> &nums) {
    pair<int, int> result{INT_MIN, INT_MAX};
    int sz = nums.size();
    vector<int> pointers(sz, 0); //, sz);
    while (true) {
        int local_max = INT_MIN, local_min = INT_MAX, local_min_index = -1;
        bool reached_end = false;
        for (int i = 0; i < sz; ++i) {
            if (pointers[i] >= nums[i].size()) {
                reached_end = true;
                break;
            }
            if (nums[i][pointers[i]] > local_max)
                local_max = nums[i][pointers[i]];
            if (nums[i][pointers[i]] < local_min) {
                local_min = nums[i][pointers[i]];
                local_min_index = i;
            }
        }
        if (reached_end)
            break;
        if ((local_max - local_min) < (result.second - result.first))
            result = {local_min, local_max};
        pointers[local_min_index] = pointers[local_min_index] + 1;
    }
    return result;
}

int main() {
    vector<vector<int>> sorted_lists{{0, 1, 4, 17, 20, 25, 31}, {5, 6, 10}, {0, 3, 7, 8, 12}};
    pair<int, int> result = smallest_interval_of_k_sorted_list(sorted_lists);
    cout << result.first << " " << result.second;
    return 0;
}
