#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node * next;
};

bool traverse_reverse(Node * head, Node **ptr1) {
    if (head) {
        bool palin = traverse_reverse(head->next, ptr1);
        if (palin == false)
            return false;
        if (head->data == (*ptr1)->data) {
            *ptr1 = (*ptr1)->next;
            return true;
        } else {
            return false;
        }
    } else {
        return true;
    }
}

string isPalindrom(Node * head) {
    Node * ptr1 = head;
    if (head->next) {
        if (traverse_reverse(head, &ptr1))
            return "Palindrom";
        else
            return "Not palindrom";
    }
    return "Palindrom";
}

int main() {
    Node * head =  new Node();
    head->data = 2;
    head->next = new Node();

    Node * palindrom = head;

    palindrom = palindrom->next;
    palindrom->data = 1;
    palindrom->next = new Node();
    palindrom = palindrom->next;

    palindrom->data = 2;
    palindrom->next = new Node();
    palindrom = palindrom->next;

    palindrom->data = 1;
    palindrom->next = new Node();
    palindrom = palindrom->next;
    
    palindrom->data = 2;
    palindrom->next = NULL;

    for (Node *a = head; a!= NULL; a = a->next) {
        cout << a->data << " ";
    }

    cout << isPalindrom(head);

    return 0;
}
