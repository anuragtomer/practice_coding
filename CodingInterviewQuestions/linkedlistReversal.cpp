#include <iostream>

using namespace std;

struct list {
    int data;
    list *next;
    list(int n): data(n), next(nullptr) {};
};

list *reverse(list *head) {
    list *temp = head, *temp2 = head;
    while(head != nullptr && head->next != nullptr) {
        temp = head->next;
        head->next = temp->next;
        temp->next = temp2;
        temp2 = temp;
    }
    head = temp2;
    return head;
}

void printList(list *head) {
    list *temp = head;
    while(temp) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "nullptr\n";
}

void deleteList(list *head) {
    list *temp;
    while(head) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    list *head  = new list(1);
    list *temp = head;
    for (int i = 2; i < 7; i++) {
        temp->next = new list(i);
        temp = temp->next;
    }
    printList(head);
    head = reverse(head);
    printList(head);
    deleteList(head);
    return 0;
}