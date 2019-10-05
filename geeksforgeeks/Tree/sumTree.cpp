#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int val;
    Node * left;
    Node * right;
    Node(int x) : val(x), left(NULL), right(NULL){
    };
};
class Solution {
public:
    /*
     * isSumTree : true, if left subtree sum + right subtree sum == root->val;
     *             false, otherwise.
     */
    bool isSumTreeRecursive(Node * root, int& sum) {
        if (root == NULL)
            return true;
        if (root->left == NULL && root->right == NULL) {
            sum = root->val;
            return true;
        }
        int sumL = 0, sumR = 0;
        if (isSumTreeRecursive(root->left, sumL) && isSumTreeRecursive(root->right, sumR)) {
            if (root->val == sumL + sumR) {
                sum = root->val + sumL + sumR;
                return true;
            }
            return false;
        }
        cout << "root->val: " << root->val << " Left sum and Right sum didn't match " << sumL << " " << sumR << endl;;
        return false;
    }
    bool isSumTree(Node * root) {
        int sum = 0;
        return isSumTreeRecursive(root, sum);
    }
};

int main() {
    Solution sol;
    Node *root  = new Node(10);
    root->left         = new  Node(20);
    root->right        = new Node(30);
    root->left->left   = new Node(40);
    root->left->right  = new Node(60);
    if(sol.isSumTree(root))
        printf("The given tree is a SumTree ");
    else
        printf("The given tree is not a SumTree ");
    return 0;
}
