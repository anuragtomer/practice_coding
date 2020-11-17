#include <iostream>
#include <unordered_set>
#include <vector>
using std::boolalpha;
using std::cout;
using std::unordered_set;
using std::vector;

bool sum_to_k(vector<int> &nums, int k) {
    unordered_set<int> st;
    for (auto num : nums) {
        if (st.count(k - num) == 0) {
            st.emplace(num);
        } else
            return true;
    }
    return false;
}

int main() {
    vector<int> nums = {10, 15, 3, 7};
    int k = 17;
    cout << boolalpha << sum_to_k(nums, k);
    return 0;
}
