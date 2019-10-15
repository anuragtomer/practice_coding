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

bool height(Tree *root, int &ht) {
    if (root == nullptr) {
        ht = 0;
        return true;
    }
    int left = 0, right = 0;
    if (height(root->left, left) == false || 
        height(root->right, right) == false) {
        ht = 0;
        return false;
    } else {
        if (abs(left - right) > 1)
            return false;
        ht = max(left, right) + 1;
        return true;
    }
}

bool
isBalanced(Tree * root) {
    if (root == nullptr)
        return true;
    int left = 0, right = 0;
    if (height(root->left, left) == false ||
        height(root->right, right) == false)
        return false;
    if (abs(left - right) > 1)
        return false;
    return true;
}

int main() {
    Tree * root = new Tree(20);
    root->left = new Tree(10);
    root->right = new Tree(30);
    root->left->left = new Tree(5);
    root->left->right = new Tree(15);
    root->right->right = new Tree(38); // Removing this should output 'false';
    root->left->left->left = new Tree(3);
    root->left->left->right = new Tree(7);
    root->left->right->right = new Tree(17);
    cout << boolalpha << isBalanced(root);
    return 0;
}