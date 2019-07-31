#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
#include <cassert>
#include <climits>

using namespace std;

struct TreeNode {
    int data;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int x) : data(x), left(NULL), right(NULL) {
    };
};
void printTree(TreeNode * head) {
    TreeNode * temp = head;
    stack <TreeNode *> st;
    st.push(head);
    while (!st.empty()) {
        temp = st.top();
        st.pop();
        cout << "\nNode: " << temp->data;
        cout << " Left: ";
        if (temp->left)
            cout << temp->left->data;
        else
            cout << "NULL";
        cout << " Right: ";
        if (temp->right)
            cout << temp->right->data;
        else
            cout << "NULL";
        if (temp->right) st.push(temp->right);
        if (temp->left) st.push(temp->left);
    }
    cout << endl;
}

TreeNode * createTree() {
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
    for (unsigned int i = 1, x = 1; x < listOfNodes.size(); i++) {
        node->left = listOfNodes[x];
        if (x + 1 < listOfNodes.size())
            node->right = listOfNodes[x + 1];
        node = listOfNodes[i];
        while(!node) {
            node = listOfNodes[++i];
        }
        x = x + 2;
    }
    return root;
}

class Solution {
public:
    /*
     *  bool rootLeafSum(TreeNode * &root, int sum) {
     *   if (root == NULL)
     *       return (sum == 0);
     *   int remain = sum - root->data;
     *   if (remain == 0)
     *       if (root->left == NULL && root->right == NULL) {
     *           cout << "setting " << root->data << " to NULL\n";
     *           root->data = INT_MIN;
     *           return true;
     *       }
     *       else
     *           return false;
     *   if (remain < 0)
     *       return false;
     *   if (remain > 0) {
     *       bool child = false;
     *       if (root->left)
     *           child = rootLeafSum(root->left, remain);
     *       if (child) {
     *           if (root->left && root->left->data != INT_MIN) {
     *               assert(root->left->left == NULL || root->left->right == NULL);
     *               if (!root->left->right) {
     *                   cout << "setting " << root->left->data << "->right to " << root->right->data << endl;
     *                   root->left->right = root->right;
     *               }
     *               else if (!root->left->left) {
     *                   cout << "setting " << root->left->data << "->left to " << root->right->data << endl;
     *                   root->left->left = root->right;
     *               }
     *               cout << "setting " << root->data << " to " << root->left->data << endl;
     *               root = root->left;
     *               return true;
     *           }
     *           else if (root->right && root->right->data != INT_MIN) {
     *               cout << "setting " << root->data << " to " << root->right->data << endl;
     *               root = root->right;
     *               return true;
     *           } else {
     *               cout << "setting " << root->data << " to NULL\n";
     *               root = NULL;
     *               return true;
     *           }
     *       }
     *       if (root->right)
     *           child = rootLeafSum(root->right, remain);
     *       if (child) {
     *           if (root->right && root->right->data != INT_MIN) {
     *               assert(root->right->left == NULL || root->right->right == NULL);
     *               if (!root->right->right) {
     *                   cout << "setting " << root->right->data << "->right to " << root->left->data << endl;
     *                   root->right->right = root->left;
     *               }
     *               else if (!root->right->left) {
     *                   cout << "setting " << root->right->data << "->left to " << root->left->data << endl;
     *                   root->right->left = root->left;
     *               }
     *               assert(root->right->left == NULL || root->right->right == NULL);
     *               cout << "setting " << root->data << " to " << root->right->data << endl;
     *               root = root->right;
     *               return true;
     *           }
     *           else if (root->left && root->left->data != INT_MIN) {
     *               cout << "setting " << root->data << " to " << root->left->data << endl;
     *               root = root->left;
     *               return true;
     *           } else {
     *               root = NULL;
     *               cout << "setting " << root->data << " to NULL\n";
     *               return true;
     *           }
     *       }
     *   }
     *   return false;
     *  }
     */
    bool rootLeafSum(TreeNode * root, int sum) {
        if (root == NULL)
            return (sum == 0);
        int remain = sum - root->data;
        if (remain == 0)
            if (root->left == NULL && root->right == NULL) {
                return true;
            }
            else
                return false;
        if (remain < 0)
            return false;
        if (remain > 0)
            return rootLeafSum(root->left, remain) || rootLeafSum(root->right, remain);
        return false;
    }
};

int main() {
    Solution sol;
    TreeNode * root = createTree();
    printTree(root);
    int sum;
    cin >> sum;
    if (sol.rootLeafSum(root, sum)) {
        cout << "TRUE\n";
        printTree(root);
    }
    else {
        cout << "FALSE\n";
        printTree(root);
    }
    return 0;
}
