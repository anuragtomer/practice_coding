#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
   public:
    int maxDepth(TreeNode *root) {
        if (!root)
            return 0;
        if (!root->left && !root->right)
            return 1;
        if (root->left && !root->right)
            return 1 + maxDepth(root->left);
        if (!root->left && root->right)
            return 1 + maxDepth(root->right);
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};
int main() {
    Solution sol;

    return 0;
}

