#include<map>
#include <istream>

template<typename C>
class String{
public:
    String(){
        String("");
    }
    explicit String(const C* c) {
        ptr = c;
    }
    String(const String&);
    String operator=(const String&);
    C& operator[](int n){return ptr[n];}
    String& operator+=(C c) {
        return *this;
    }
    /* istream& operator>>(istream& is, String<C>& s) {
        is >> s;
    } */
private:
    C* ptr;
    int sz;
    static const int short_max = 15;
};

template <typename C> 
String<C>::String(): sz{0}, ptr{ch} {
    ch[0] = {};
}
/* 
This didn't work.
template<typename C>
String& String<C>::operator+=(C c)
{
// ... add c to the end of this string ...
return ∗this;
}
 */
/* template <typename C>
String& String<C>::operator+=(C c) {
    ptr[sz++] = c;
    return *this;
} */
int main(){
    std::map<String<char>, int> m;
    for(String<char> buf; cin>>buf; )
        ++m[buf];
}