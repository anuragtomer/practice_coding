#include <iostream>
#include <vector>

using namespace std;
int firstMissingPositive(vector<int> nums) {
    auto sz = nums.size();
    nums.resize(sz + 1);
    sz++;
    for (int i = 0; i < sz; ++i) {
        if (nums[i] <= 0 || nums[i] >= sz || nums[i] == i - 1)
            continue;
        if (nums[i] != nums[nums[i]]) {
            swap(nums[i], nums[nums[i]]);
            i--;
        }
    }
    for (int i = 1; i < sz; ++i) {
        if (i != nums[i])
            return i;
    }
    return sz;
}
int main() {
    assert(firstMissingPositive(vector<int>({1, 2, 0})) == 3);
    assert(firstMissingPositive(vector<int>({3, 4, -1, 1})) == 2);
    assert(firstMissingPositive(vector<int>({})) == 1);
    assert(firstMissingPositive(vector<int>({7, 8, 9, 11, 12})) == 1);
    assert(firstMissingPositive(vector<int>({1})) == 2);
    return 0;
}
