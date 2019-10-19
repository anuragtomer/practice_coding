#include<iostream>

using namespace std;

struct Node{
    int val;
    Node * left;
    Node * right;
    Node(int x) : val{x}, left{nullptr}, right{nullptr} {};
};

bool find(Node * root, int val) {
    if (!root) 
        return false;
    if (root->val == val || (find(root->left, val) || find(root->right, val)))
        return true;
    return false;
}

Node * ancestorUtil(Node * root, int p, int q, bool &pf, bool &qf) {
    if (root == nullptr)
        return nullptr;
    if (root->val == p) {
        pf = true;
        return root;
    }
    if (root->val == q) {
        qf = true;
        return root;
    }
    Node * left = ancestorUtil(root->left, p, q, pf, qf);
    Node * right = ancestorUtil(root->right, p, q, pf, qf);
    if (left && right) 
        return root;
    else if (left)
        return left;
    else 
        return right;
}

Node * ancestor(Node *root, int p, int q) {
    bool pf = false, qf = false;
    Node * temp = ancestorUtil(root, p, q, pf, qf);
    if ((pf && qf) || (pf && find(root, q)) || (qf && find(root, p)))
        return temp;
    else 
        return nullptr;
}

int main() {
    Node * root = new Node(20);
    root->left = new Node(10);
    root->right = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(15);
    root->left->left->left = new Node(3);
    root->left->left->right = new Node(7);
    root->left->right->right = new Node(17);
    Node * common = ancestor(root, 30, 10);
    if (common != nullptr)
        cout << common->val;
    else 
        cout << "Not found";


    return 0;
}