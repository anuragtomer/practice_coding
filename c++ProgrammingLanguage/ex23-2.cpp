#include<iostream>
template<typename T>
struct X{
  int m1 = 7;
  T m2;
  X(const T& x): m2(x) {}  
};

int main()
{
    X<int> a{9};
    X<std::string> b{"Hello"};
    std::cout << a.m1 << " " << a.m2 << std::endl;
    std::cout << b.m1 << " " << b.m2 << std::endl;
    return 0; 
}