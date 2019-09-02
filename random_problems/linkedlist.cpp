#include<iostream>
using namespace std;

struct List{
    int data;
    List *next;
    List(int n):next(nullptr), data(n){};
};

List * insert(int elem, List *head) {
    if (head == nullptr) {
        head = new List(elem);
    } else {
        int option {};
        cout << "Head exists!! Insert where? (start[0], end[1], at nth position[2]): ";
        cin >> option;
        List *temp = new List(elem);
        switch(option) {
            case 0:
                {
                    temp->next = head;
                    head = temp;
                    break;
                }
            case 1:
                {
                    List *temp2 = head;
                    while(temp2->next != nullptr) {
                        temp2 = temp2->next;
                    }
                    temp2->next = temp;
                    break;
                }
            case 2:
                {
                    int n {};
                    cout << "Enter position: ";
                    cin >> n; 
                    List *temp2 = head;
                    int nodes {};
                    while(temp2 && nodes < n-1) {
                        temp2 = temp2->next;
                        nodes++;
                    }
                    temp->next = temp2->next;
                    temp2->next = temp;
                    break;
                }
            default:
                {
                    cout << "Incorrect option!! Exiting without adding...\n";
                    break;
                }
        }
    }
    return head;
}

void printList(List *head) {
    while(head) {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "nullptr\n";
}

int main() {
    List *head = nullptr;
    int elem{};
    int conti{};
    int option{};
    do {
        cout << "Insert an element? (0)\n See the list? (1) : ";
        cin >> option;
        switch(option) {
            case 0:
                {
                    cout << "Enter element: ";
                    cin >> elem;
                    head = insert(elem, head);
                    break;
                    }
            case 1:
                {
                    printList(head);
                    break;
                }
            default:
                {
                    cout << "Incorrect option.. \n";
                    break;
                }
        }
        cout << "Do you want to continue? (0/1): ";
        cin >> conti;
    } while(conti == 1);
    return 0;
}