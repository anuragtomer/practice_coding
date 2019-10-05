#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:
        void merge(vector<int> &nums, int lb1, int ub1, int lb2, int ub2) {
            vector<int> _nums(nums.size());
            int i = lb1;
            int lb = lb1;
            while (lb1 <= ub1 && lb2 <= ub2) {
                if (nums[lb1] > nums[lb2]) {
                    _nums[i] = nums[lb2];
                    i++;
                    lb2++;
                } else {
                    _nums[i] = nums[lb1];
                    i++;
                    lb1++;
                }
            }
            while (lb1 <= ub1) {
                _nums[i] = nums[lb1];
                i++;
                lb1++;
            }
            while (lb2 <= ub2) {
                _nums[i] = nums[lb2];
                i++;
                lb2++;
            }
            for (int i = lb; i <= ub2; i++)
                nums[i] = _nums[i];
        }
        void mergeSort(vector <int> &nums, int lb, int ub) {
            if (lb == ub) {
                return;
            } else{
                int mid = (lb + ub)/2;
                mergeSort(nums, lb, mid);
                mergeSort(nums, mid + 1, ub);
                merge(nums, lb, mid, mid+1, ub);
            }
        }

        int sumAsso(vector<int> nums) {
            long long int sum = 0;
            for (int i = 0; i < nums.size(); i = i+2) {
                sum += nums[i];
            } 
            return sum;
        }
};
int main() {
    Solution sol;
    int asso;
    int num;
    cin >> asso;
    vector <int> nums(2*asso);
    nums.clear();
    for (int i = 0; i < 2*asso; i++) {
        cin >> num;
        nums.push_back(num);
    }
    sol.mergeSort(nums, 0, nums.size() - 1);
    cout << sol.sumAsso(nums);
    return 0;
}


