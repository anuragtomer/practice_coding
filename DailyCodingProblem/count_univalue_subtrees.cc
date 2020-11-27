#include <iostream>
#include <vector>

using namespace std;
struct BinaryTreeNode {
    int value;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
    BinaryTreeNode(int data) : value(data), left(nullptr), right(nullptr){};
};

struct countStruct {
    int count;
    int value;
    bool is_univalue;
};

countStruct *countUnivalueSubtreesHelper(BinaryTreeNode *root, int root_value) {
    countStruct *cs = new countStruct{0, 0, true};
    if (!root)
        return cs;
    if (root->left == nullptr && root->right == nullptr) {
        cs->count = 1;
        cs->value = root->value;
        cs->is_univalue = true;
        return cs;
    }
    countStruct *left = countUnivalueSubtreesHelper(root->left, root->value);
    countStruct *right = countUnivalueSubtreesHelper(root->right, root->value);
    cs->is_univalue = left->is_univalue && right->is_univalue;
    if (root->left)
        cs->is_univalue = cs->is_univalue && (root->value == left->value);
    if (root->right)
        cs->is_univalue = cs->is_univalue && (root->value == right->value);
    cs->count = left->count + right->count;
    if (cs->is_univalue)
        ++cs->count;
    cs->value = root->value;
    delete left;
    delete right;
    return cs;
}

int countUnivalueSubtrees(BinaryTreeNode *root) {
    if (root == nullptr)
        return 0;
    countStruct *result = countUnivalueSubtreesHelper(root, root->value);
    int count = result->count;
    delete result;
    return count;
}

void deleteTree(BinaryTreeNode *root) {
    if (!root)
        return;
    if (root->left == nullptr || root->right == nullptr) {
        delete root;
        return;
    }
    if (root->left)
        deleteTree(root->left);
    if (root->right)
        deleteTree(root->right);
    delete root;
}

int main() {
    BinaryTreeNode *root = new BinaryTreeNode(1);
    root->left = new BinaryTreeNode(0);
    root->right = new BinaryTreeNode(1);
    root->right->left = new BinaryTreeNode(0);
    root->right->right = new BinaryTreeNode(2);
    root->right->right->left = new BinaryTreeNode(1);
    root->right->right->right = new BinaryTreeNode(1);
    cout << boolalpha << (countUnivalueSubtrees(root) == 4);
    deleteTree(root);
    root = new BinaryTreeNode(1);
    root->left = new BinaryTreeNode(1);
    root->right = new BinaryTreeNode(1);
    root->right->left = new BinaryTreeNode(1);
    root->right->right = new BinaryTreeNode(1);
    root->right->right->right = new BinaryTreeNode(2);
    cout << boolalpha << (countUnivalueSubtrees(root) == 3);
    deleteTree(root);
    root = new BinaryTreeNode(1);
    root->left = new BinaryTreeNode(3);
    root->right = new BinaryTreeNode(2);
    root->right->left = new BinaryTreeNode(2);
    root->right->right = new BinaryTreeNode(2);
    root->right->right->right = new BinaryTreeNode(2);
    cout << boolalpha << (countUnivalueSubtrees(root) == 5);
    deleteTree(root);
    return 0;
}
