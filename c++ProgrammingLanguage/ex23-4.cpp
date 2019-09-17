#include<iostream>
template<typename T>
struct X{
    static const int m1 = 8;
    // static int m2 = 9; // Must be const if initializing inside template class.
    static int m3;
    static void f1() {
        std::cout << "In f1().\n";
    }
    static void f2();
};

template<typename T>
void X<T>::f2() {
    std::cout << "In f2.\n";
}

template<typename T> int X<T>::m3 = 99; // Not doing this would cause runtime-error in ln 21.

int main()
{
    X<int> a;
    std::cout << a.m1 << " " << a.m3 << "\n";
    a.f1();
    a.f2();
    return 0; 
}