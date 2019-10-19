#include<iostream>

using namespace std;

struct Node{
    int val;
    Node * left;
    Node * right;
    Node(int x) : val{x}, left{nullptr}, right{nullptr} {};
};

bool completeMatch(Node * root1, Node *root2) {
    if (root1 == nullptr && root2 == nullptr)
        return true;
    else if ((root1 == nullptr && root2 != nullptr) ||
             (root2 == nullptr && root1 != nullptr))
        return false;
    else if (root1->val != root2->val)
        return false;
    else 
        return completeMatch(root1->left, root2->left) && 
               completeMatch(root1->right, root2->right);
}

bool isSubtree(Node *root1, Node *root2) {
    if (root2 == nullptr)
        return true;
    else if (root1 == nullptr && root2 != nullptr)             
        return false;
    if (root1->val == root2->val)
        return completeMatch(root1, root2);
    else 
        return isSubtree(root1->left, root2) || isSubtree(root1->right, root2);
}

int main() {
    Node * root1 = new Node(20);
    root1->left = new Node(10);
    root1->right = new Node(30);
    root1->left->left = new Node(5);
    root1->left->right = new Node(15);
    root1->left->left->left = new Node(3);
    root1->left->left->right = new Node(7);
    root1->left->right->right = new Node(17);

    Node * root2 = new Node(15);
    root2->right = new Node(20);

    cout << boolalpha << isSubtree(root1, root2);
    return 0;
}