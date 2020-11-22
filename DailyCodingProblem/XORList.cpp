#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

struct XORNode {
    int data;
    XORNode *both;
    XORNode(int _data) : data(_data), both(nullptr){};
};

XORNode *XOR(XORNode *left, XORNode *right) {
    return reinterpret_cast<XORNode *>(reinterpret_cast<uintptr_t>(left) ^ reinterpret_cast<uintptr_t>(right));
}

class XORList {
   public:
    XORList() {
        root = nullptr;
    }
    XORNode *root;
    void add(int data) {
        if (!root) {
            root = new XORNode(data);
            return;
        }
        XORNode *curr = root, *prev = nullptr;
        XORNode *newNode = new XORNode(data);
        while (curr->both != prev) {
            auto *temp = curr;
            curr = XOR(curr->both, prev);
            prev = temp;
        }
        curr->both = XOR(prev, newNode);
        auto *temp = curr;
        curr = XOR(curr->both, prev);
        prev = temp;
        curr->both = prev;
    }

    int get(int index) {
        XORNode *curr = root, *prev = nullptr;
        while (index-- > 0) {
            auto *temp = curr;
            curr = XOR(curr->both, prev);
            prev = temp;
        }
        return curr->data;
    }
};
int main() {
    XORList list = XORList();
    list.add(5);
    list.add(7);
    list.add(1);
    list.add(6);
    assert(1 == list.get(2));
    assert(5 == list.get(0));
    assert(7 == list.get(1));
    assert(6 == list.get(3));
    return 0;
}
