#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class solution{
public:
    vector<int> twoSum(vector <int> &nums, int target) {
        sort(nums.begin(), nums.end());
        vector::iterator <int> i = nums.begin();
        vector::iterator <int> j = nums.end();

        return nums;
    }
    void print_vector(vector <int> &nums) {
        for (auto i : nums) {
            cout << i << " ";
        }
        cout << endl;
    }
};
int main()
{
    int i;
    solution sol;
    vector <int> vec = {1, 5, 2, 4, 3};
    sol.print_vector(vec);
    vec = sol.twoSum(vec, 9);
    sol.print_vector(vec);
    return 0;
}
