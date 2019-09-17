#include<iostream>
//using namespace std;
template<typename T, int max>
struct Buffer{
    T buf[max];
    public:
    //
};

template<typename T, int max>
T& lookup(Buffer<T, max>&b, const char* p);

std::string& f(Buffer<std::string, 128>& buf, const char* p)
{
    return lookup(buf, p);
}

template<typename T1, typename T2>
std::pair<T1, T2> make_pair(T1 a, T2 b) {
    return {a, b};
}

auto x = make_pair(1, 2);
auto y = make_pair("ba", 7);

