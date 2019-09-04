#include<iostream>
#include <cassert>

using namespace std;

struct list {
    int data;
    list *next;
    list(int n): data(n), next(nullptr) {};
};

struct stack{
private:
    list *head = nullptr;
public:
    bool isempty() {
        return (head == nullptr);
    }
    int top() {
            return head->data;
    }
    void push(int n) {
        list *temp = new list(n);
        temp->next = head;
        head = temp;
    }
    void pop() {
        list *temp = head;
        head = head->next;
        delete temp;
    }
    stack(): head(nullptr) {};
    void printstack() {
        list *temp = head;
        while (temp) {
            cout << temp -> data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr\n";
    }
    void deletestack() {
        list *temp;
        while(head) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

struct advanced_stack{
private:
    stack *normalstack;
    stack *minstack;
public:
    void push(int n) {
        normalstack->push(n);
        int mintop;
        if (minstack->isempty() == false) {
            mintop = minstack->top();
            if (mintop > n) {
                minstack->push(n);
            } else {
                minstack->push(mintop);
            }
        } else {
            minstack->push(n);
        }
    }
    void pop() {
        if (normalstack->isempty() == false && minstack->isempty() == false) {
            normalstack->pop();
            minstack->pop();
        }
    }
    int top() {
        if (normalstack->isempty() == false)
        return normalstack->top();
        else cout << "STack is empty()\n";
    }
    int min() {
        return minstack->top();
    }
    advanced_stack() {
        normalstack = new stack();
        minstack = new stack();
    };
    void print() {
        cout << "Normal stack: ";
        normalstack->printstack();
        cout << "Min stack: ";
        minstack->printstack();
    }
    void deleteStack() {
        normalstack->deletestack();
        minstack->deletestack();
        delete normalstack;
        delete minstack;
    }
    bool isempty() {
        return normalstack->isempty();
    }
};

int main() {
    advanced_stack *as = new advanced_stack();
    int choice;
    int n;
    cout << "1. Push\n2. Pop\n3. Top\n4. Min\n5. Print stack\n 6. Exit: ";
    do {        
        cin >> choice;
        switch(choice) {
            case 1: {
                cout << "Input: ";
                cin >> n;
                as->push(n);
                break;
            }
            case 2: {
                as->pop();
                break;
            }
            case 3: {
                if (as->isempty() == false)
                    as->top();
                else 
                    cout << "Stack is empty.\n";
                break;
            }
            case 4: {
                if (as->isempty() == false)
                    cout << as->min() << endl;
                else 
                    cout << "Stack is empty.\n";
                break;
            }
            case 5: {
                as->print();
                break;
            }
            default:
                break;
        }
    } while(choice != 6);
    as->deleteStack();
    return 0;
}