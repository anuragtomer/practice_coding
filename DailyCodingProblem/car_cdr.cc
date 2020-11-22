#include <iostream>
#include <vector>

using namespace std;

template <typename T1, typename T2>
T1 car(pair<T1, T2> pr) {
    return pr.first;
}

template <typename T1, typename T2>
T2 cdr(pair<T1, T2> pr) {
    return pr.second;
}

int main() {
    // cons();
    // car();
    // cdr();
    pair<int, int> pr = {1, 2};
    assert(car(pr) == pr.first);
    assert(cdr(pr) == pr.second);
    return 0;
}
