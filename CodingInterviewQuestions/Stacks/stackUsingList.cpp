#include<iostream>

using namespace std;
struct List{
    int data;
    List *next;
    List(int elem): data(elem), next(nullptr) {};
};

void deleteList(List *head) {
    while(head) {
        List *temp = head;
        head = head->next;
        delete temp;
    }
    head = nullptr;
}

class stack{
    List *head = nullptr;
public:
    void push(int elem);
    void pop();
    int top();
    void printStack();
    void deleteStack();
    stack() : head(nullptr) {};
};

void stack::push(int elem) {
    List *temp;
    try {
        temp = new List(elem);
    } catch(exception &e) {
        cout << "No memory. Cannot push any more data.";
        deleteList(head);
        return;
    }
    temp->next = head;
    head = temp;
}

void stack::pop() {
    if (head != nullptr) {
        List *temp = head;
        head = head->next;
        delete temp;
    } else {
        cout << "No element to pop.";
    }
}

int stack::top() {
    if (head != nullptr) {
        return head->data;
    }
    cout << "Stack is empty";
    return -1;
}

void stack:: printStack() {
    List *temp = head;
    while(temp != nullptr) {
        cout << temp->data << "-> ";
        temp = temp->next;
    }
    cout << "nullptr\n";
}

void stack::deleteStack() {
    List *temp;
    while(head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
    head = nullptr;
}
int main() {
    stack st{};
    int option;
    cout << "1. Push\n2. Pop\n3. Top\n4. See stack\n5. Quit\n";
    do {
        cout << "Option: ";
        cin >> option;
        switch(option) {
            case 1: {
                int elem;
                cout << "Enter element to push: ";
                cin >> elem;
                st.push(elem);
                break;
            }
            case 2: {
                st.pop();
                break;
            }
            case 3: {
                cout << st.top() << endl;
                break;
            }
            case 4: {
                st.printStack();
                break;
            }
            default: {

            }
        }
    } while(option != 5);
    st.deleteStack();
    return 0;
}