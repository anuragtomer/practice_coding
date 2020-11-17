#include <iostream>
#include <vector>

using namespace std;
vector<int> productExceptSelf(vector<int> &nums) {
    vector<int> result;
    size_t sz = nums.size();
    result.push_back(1);
    for (int i = 1; i < sz; ++i) {
        result.push_back(result.back() * nums[i - 1]);
    }
    int R = 1;
    for (int i = sz - 1; i > 0; --i) {
        R *= nums[i];
        result[i - 1] = R * result[i - 1];
    }
    return result;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    vector<int> result = productExceptSelf(nums);
    for (auto num : result) {
        cout << num << " ";
    }
    return 0;
}
