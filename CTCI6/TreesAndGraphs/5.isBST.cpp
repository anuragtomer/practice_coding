#include <iostream>
#include <vector>
#include <list>
using namespace std;

struct Tree{
    int val;
    Tree * left;
    Tree * right;
    Tree(int x):val{x}, left{nullptr}, right{nullptr} {};
};

bool
isBSTUtil(Tree *root, int min, int max) {
    if (root == nullptr)
        return true;
    if (root->val < max && root->val > min) {
        return isBSTUtil(root->left, min, root->val) &&
               isBSTUtil(root->right, root->val, max);
    }
    return false;
}

bool
isBST(Tree * root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

int main() {
    Tree * root = new Tree(20);
    root->left = new Tree(10);
    root->right = new Tree(30);
    root->left->left = new Tree(5);
    root->left->right = new Tree(15);
    root->right->right = new Tree(38);
    root->left->left->left = new Tree(3);
    root->left->left->right = new Tree(7);
    root->left->right->right = new Tree(27);
    cout << boolalpha << isBST(root);
    return 0;
}