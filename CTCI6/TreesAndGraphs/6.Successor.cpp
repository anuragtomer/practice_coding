#include <iostream>
#include <vector>
#include <list>
using namespace std;

struct Tree{
    int val;
    Tree * left;
    Tree * parent;
    Tree * right;
    Tree(int x):val{x}, left{nullptr}, right{nullptr}, parent{nullptr} {};
};

Tree *
inorderSuccessor(Tree * node) {
    if(node == nullptr)
        return nullptr;
    if (node->right) {
        node = node->right;
        while(node->left)
            node = node->left;
        return node;
    }
    if (node->parent && node == node->parent->left)
        return node->parent;
    while(node->parent && node == node->parent->right)
        node = node->parent;
    return node->parent;
}

void inorder(Tree * root, vector<Tree *> &inorderTraversal) {
    if (root == nullptr)
        return;
    inorder(root->left, inorderTraversal);
    inorderTraversal.push_back(root);
    inorder(root->right, inorderTraversal);
}

int main() {
    Tree * root = new Tree(20);
    root->left = new Tree(10);
    root->left->parent = root;
    root->right = new Tree(30);
    root->left->parent = root;
    root->left->left = new Tree(5);
    root->left->left->parent = root->left;
    root->left->right = new Tree(15);
    root->left->right->parent = root->left;
    root->right->right = new Tree(38);
    root->right->right->parent = root->right;
    root->left->left->left = new Tree(3);
    root->left->left->left->parent = root->left->left;
    root->left->left->right = new Tree(7);
    root->left->left->right->parent = root->left->left;
    root->left->right->right = new Tree(17);
    root->left->right->right->parent = root->left->right;
    vector<Tree *> inorderTraversal;
    inorder(root, inorderTraversal);
    for (int i = 0; i < inorderTraversal.size()-1; ++i) {
        if (inorderSuccessor(inorderTraversal[i]) != inorderTraversal[i+1]) {
            cout << "Incorrect successor";
            return 0;
        }
    }
    cout << "All successor match.";
    return 0;
}