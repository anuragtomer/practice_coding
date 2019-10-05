#include<vector>
#include<iostream>
using namespace std;
template<typename T, typename Compare = less<T>> 
void sort(vector<T> &);
void f(vector<int>& vi, vector<string> &vs) {
    sort(vi); // default less-than comparison
    sort<int, greater<int>>(vi); // Greater-than comparison

    sort(vs); // default comparison
    sort<string, No_case>(vs); // use No_case comparison
}
/* We can ask user to give comparison class because > or <
 * may not be defined on all the templates(strings, user-defined 
 * types). Putting default comparator to less.
 */
template<typename T, typename Compare = less<T>> 
void sort(vector<T> & v) {
    Compare cmp;
    const size_t n = v.size();

    for(int gap = n/2; 0 < gap; gap/=2)
        for (int i = gap; i < n; i++)
            if (cmp(v[j+gap], v[j]))
                swap(v[j], v[j+gap]); // swap would be faster because it uses move semantics.
}

struct No_case{
    bool operator()(const string& a, const string& b) const; // Would need to define this.
};

