#include <iostream>
#include <vector>

using namespace std;

class 
Node {
    public:
        int data;
        Node * next;
};

Node *
create_linked_list(int n) {
    Node *head = NULL,  *temp = NULL;
    for (int i = 0; i < n; i++) {
        temp = new Node();
        temp->data = i;
        temp->next = head;
        head = temp;
    }
    return head;
}

Node *
create_linked_list(vector <int> arr) {
    Node *head = NULL,  *temp = NULL;
    for (int i = 0; i < arr.size(); i++) {
        temp = new Node();
        temp->data = arr[i];
        temp->next = head;
        head = temp;
    }
    return head;
}
void
print_linked_list(Node * head) {
    while(head) {
        cout << head->data << " " ;
        head = head->next;
    }
    cout << endl;
}

void
create_odd_even_linked_list(Node * head, Node ** head_odd, Node ** head_even) {
    Node * temp_odd = NULL, *temp_even = NULL;
    Node * temp = head;
    while (temp) {
        if (temp->data % 2 == 0) {
            if (*head_even == NULL) {
                *head_even = temp;
                temp = temp->next;
                (*head_even)->next = NULL;
                temp_even = *head_even;
            } else {
                temp_even->next = temp;
                temp_even = temp_even->next;
                temp = temp->next;
                temp_even->next = NULL;
            }
        } else {
            if (*head_odd == NULL) {
                *head_odd = temp;
                temp = temp->next;
                (*head_odd)->next = NULL;
                temp_odd = *head_odd;
            } else {
                temp_odd->next = temp;
                temp_odd = temp_odd->next;
                temp = temp->next;
                temp_odd->next = NULL;
            }
        }
    }
}

int
main() {
    Node * head = NULL;
    vector <int> arr = {1, 2, 3, 5, 7, 4, 8};
    head = create_linked_list(arr);
    // head = create_linked_list(6);
    print_linked_list(head);
    Node * head_odd = NULL, * head_even = NULL;
    create_odd_even_linked_list(head, &head_odd, &head_even);
    print_linked_list(head_odd);
    print_linked_list(head_even);
    return 0;
}
