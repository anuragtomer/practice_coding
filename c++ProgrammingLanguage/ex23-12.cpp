#include <iostream>
template<typename T>
class Xref {
public:
    Xref(int i, T* p) // Store a pointer: xref is the owner.
        :index{i}, elem{p}, owner{true}
        {}

    Xref(int i, T& r) // Store a reference to r: xref is not the owner.
        :index{i}, elem{&r}, owner{false}
        {}
    
    Xref(int i, T&& r) // Move r into Xref and make Xref the owner.
        :index{i}, elem{new T{move(r)}}, owner{true}
        {}
        
    ~Xref() {
        if (owner) delete elem;
    }
private:
    int index;
    T* elem;
    bool owner;
};

std::string x{"There and back again"};

Xref<std::string> r1 {7, "here"}; // r1 owns a copy of string("Here") "here" is rvalue. So, would go to && constructor.
Xref<std::string> r1 {9, x};      // r2 just refers to x. x is lvalue. Would go to & constructor.
Xref<std::string> r1 {3, new std::string{"There"}}; // r3 owns the string "There". Uses new, would go to move constructor.
