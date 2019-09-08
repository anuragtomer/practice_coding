/*
 * Program to create a complete binary tree from preorder traversal.
 * Input is of type string in format 'ILILL' where 
 *    I denotes Interior node
 *    L denotes Leaf node
 */
#include <iostream>
#include <queue> // Used to print level traversal of the tree.
#include <stack> // Used to print inorder traversal of the tree.

using namespace std;

// Basic Class structure to define a node of our tree.
class node{
public:
    char data;
    node *left;
    node *right;
    node(const char c):data(c), left(nullptr), right(nullptr) {};
};

// Main function to build tree from given preorder traversal.
node * buildTree(string preorder, int &curr) {
    if (curr == preorder.size()) {
        return nullptr;
    }
    node *root = new node(preorder[curr]);
    if (preorder[curr] == 'L') {
        // we are leaf, won't have any children. So return.
        return root;
    }
    // Not a leaf node. Must have 2 children.
    curr++;
    root->left = buildTree(preorder, curr);
    curr++;
    root->right = buildTree(preorder, curr);
    return root;
}

// To print tree in level order traversal and preorder traversal (iteratively).
void printTree(node * root) {
    if (root == nullptr) {
        return;
    }
    /* Algo:
     * 1. Put root in Queue.
     * 2. Do while queue is not empty
     *   a. dequeue from queue.
     *   b. Print the dequeued element.
     *   c. If dequeued element has left/right, enqueue it to queue.
     */
    cout << "\nLevel ordered:";
    queue <node *> Q;
    Q.push(root);
    while(Q.empty() != true) {
        node *temp = Q.front();
        Q.pop();
        cout << temp->data << " ";
        if (temp->left) 
            Q.push(temp->left);
        if (temp->right)
            Q.push(temp->right);
    }
    /* Algo:
     * 1. Put root in stack.
     * 2. do while stack is not empty
     *   a. print top and Pop 
     *   b. if poped has left/right, push it into stack(right first).
     */
    cout << "\nInorder: ";
    stack <node *> S;
    S.push(root);
    while(S.empty() != true) {
        node *temp = S.top();
        S.pop();
        cout << temp->data << " ";
        if (temp->right != nullptr)
            S.push(temp->right);
        if (temp->left != nullptr)
            S.push(temp->left);
    }
}

void deleteTree(node * root) {
    if (root != nullptr) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}
int main() {
    string preorder;
    cin >> preorder;
    int curr = 0;
    node * root = buildTree(preorder, curr);
    printTree(root);
    return 0;
}