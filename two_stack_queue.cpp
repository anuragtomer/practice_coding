#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

class MyQueue {

    public:
        stack<int> stack_newest_on_top, stack_oldest_on_top;   
        void push(int x) {
            cout << "Inserting into newest on top" << x << endl;
            stack_newest_on_top.push(x);
        }

        void pop() {
            if (stack_oldest_on_top.empty()) {
                cout << "oldest on top is empty. need to fill it up" << endl;
                while(!stack_newest_on_top.empty()) {
                    cout << "Inserting into oldest on top" << stack_newest_on_top.top() << endl;
                    stack_oldest_on_top.push(stack_newest_on_top.top());
                    cout << "Removing form newest on top" << endl;
                    stack_newest_on_top.pop();
                }
            }            
            cout << "oldest on top has some elements.. removing" << stack_oldest_on_top.top() << endl;
            stack_oldest_on_top.pop();
        }

        int front() {            
            return stack_oldest_on_top.top();
        }
};

int main() {
    MyQueue q1;
    int q, type, x;
    cin >> q;

    for(int i = 0; i < q; i++) {
        cin >> type;
        if(type == 1) {
            cin >> x;
            q1.push(x);
        }
        else if(type == 2) {
            q1.pop();
        }
        else cout << q1.front() << endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
