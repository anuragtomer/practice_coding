// TODO: Needs rework. Not compilable code.

#include<iostream>

using namespace std;

/* template <typename iter, typename val>
val sum_all(iter first, iter last) {
    val s {0};
    while (first != last) {
        s += *first;
        ++first;
    }
    return s;
}
 */

class Node {
public:
    int data;
    Node * next;
    Node(int n): data(n), next(nullptr) {};
    Node* Node::operator++ () {
        return this->next;
    }
    void Node::operator++ (int) {
        ++(*this);  // or just call operator++()
    }
    int& operator* () {
        return this->data;
    } 
};

Node * end(Node *lst) {
    return nullptr;
}


int sum_all(Node first, Node last) {
    int s {0};
    while (first != last) {
        s = s + *first;
        ++first;
    }
    return s;
}

int main() {
    Node * head = new Node(5);
    head-> next = new Node(15);
    int s = sum_all(&head, end(&head));
    cout << s;
    return 0;
}