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

vector<list<Tree *>>
ListOfDepth(Tree * root) {
    list<Tree *> list1;
    list<Tree *> list2;
    if (root == nullptr)
        return {{}};
    list1.push_back(root);
    vector<list<Tree *>> output;
    output.push_back(list1);
    while(list1.empty() != true) {
        Tree * current = list1.front();
        list1.pop_front();
        if (current->left != nullptr)
            list2.push_back(current->left);
        if (current->right != nullptr)
            list2.push_back(current->right);
        if (list1.empty() == true) {
            output.push_back(list2);
            list1 = list2;
            list2.clear();
        }
    }
    return output;
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
    root->left->right->right = new Tree(17);
    vector<list<Tree *>> output = ListOfDepth(root);
    for (auto &lst: output) {
        cout << "\nList: ";
        for (auto &t: lst)
            cout << t->val << " -> ";
    }

    return 0;
}