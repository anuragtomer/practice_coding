#include<iostream>
using namespace std;
template<typename T, typename Allocator = allocator<T>> class Vector {};

using Cvec = Vector<char>;

Cvec vc = {'a', 'b', 'c'}; // Need to have constructor with variadic arguments.

template<typename T>
using Vec = Vector<T, My_alloc<T>>;
Vec<int> fib = {0, 1, 1, 2, 3, 5, 8, 13};