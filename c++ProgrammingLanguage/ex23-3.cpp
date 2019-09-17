#include<iostream>
template<typename T>
struct X{
    void m1() {
        std::cout << "In m1().\n";
    }
    void m2();
};

template<typename T>
void X<T>::m2() {
    std::cout << "In m2.\n";
}
int main()
{
    X<int> a;
    a.m1();
    a.m2();
    return 0; 
}