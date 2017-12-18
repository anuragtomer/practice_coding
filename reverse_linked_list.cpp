#include <iostream>

using namespace std;
struct Node {
    int data;
    Node * next;
}

Node * create_linkedlist(int data)
{
    Node * head = new Node;
    head->data = data;
    head->next = NULL;
    return head;
}

void delete_linkedlist(Node * head) {
    while (head->next) {
        Node * temp = head;
        head = head->next;
        free(temp);
    }
    if (head)
        free(head);
}



int main()
{
    int data;
    Node * head;
    cin >> data;
    head = create_linkedlist(data);
    cout << head->data << " " << head->next << endl;
    delete_linkedlist(head);
    return 0;
}
