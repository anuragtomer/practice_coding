#include <iostream>
#include <vector>
#include <climits>
#include <map>
#include <sstream>
using namespace std;

/* A binary tree node has data, pointer to left child
 *  and a pointer to right child */
struct TreeNode
{
    int val;
    struct TreeNode * left;
    struct TreeNode * right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
    bool isBSTUtil(TreeNode * root, int min, int max) {
        if (!root)
            return true;
        if ((min != NULL && root->val <= min) || (max != NULL && root->val >= max))
            return false;
        TreeNode * left = NULL, * right = NULL;
        if (root->left) left = root->left;
        if (root->right) right = root->right;
        bool leftreturn = true,  rightreturn = true;
        if (right) {
            if (root->val > right->val)
                rightreturn = isBSTUtil(root->right, root->val, max);
            else rightreturn = false;

        }
        if (left) {
            if (root->val > left->val)
                leftreturn = isBSTUtil(root->left, min, root->val);
            else leftreturn = false;
        }
        return rightreturn && leftreturn;

    }
    bool isValidBST(TreeNode * root) {
        if (!root)
            return true;
        return isBSTUtil(root, NULL, NULL);
    }
};

/* Returns true if the given tree is a binary search tree
 *  (efficient version). */

int main() {
    Solution sol;

    string input;
    getline(cin, input);
    stringstream s(input);
    string word;
    vector <TreeNode *> listOfNodes;
    listOfNodes.clear();
    while(s >> word) {
        if (word.compare("null") == 0) {
            listOfNodes.push_back(NULL);
        } else {
            int val = stoi(word);
            TreeNode * node = new TreeNode(val);
            listOfNodes.push_back(node);
        }
    }
    TreeNode * root = listOfNodes[0];
    TreeNode * node = root;
    for (unsigned i = 1, x = 1; x < listOfNodes.size(); i++) {
        node->left = listOfNodes[x];
        node->right = listOfNodes[x + 1];
        node = listOfNodes[i];
        while(!node) {
            node = listOfNodes[++i];
        }
        x = x + 2;
    }
    if (sol.isBST(root)) cout << "true";
    else cout << "false";
    return 0;
}
/*
 * int isBSTUtil(struct Node * node, int min, int max);
 *
 * / * Driver program to test size function* /
 * int main()
 * {
 *     int t;
 *     Solution sol;
 *     struct Node *child;
 *     scanf("%d", &t);
 *     while (t--)
 *     {
 *         map <int, Node *> m;
 *         int n;
 *         scanf("%d",&n);
 *         struct Node *root = NULL;
 *         while (n--)
 *         {
 *             Node *parent;
 *             char lr;
 *             int n1, n2;
 *             scanf("%d %d %c", &n1, &n2, &lr);
 *              / *  cout << n1 << " " << n2 << " " << (char)lr << endl; * /
 *             if (m.find(n1) == m.end())
 *             {
 *                 parent = new Node(n1);
 *                 m[n1] = parent;
 *                 if (root == NULL)
 *                     root = parent;
 *             }
 *             else
 *                 parent = m[n1];
 *             child = new Node(n2);
 *             if (lr == 'L')
 *                 parent->left = child;
 *             else
 *                 parent->right = child;
 *             m[n2]  = child;
 *         }
 *         if (sol.isBST(root)) cout << "true" << endl;
 *         else cout << "false" << endl;
 *     }
 *     return 0;
 * }
 */
