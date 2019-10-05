#include<iostream>
#include<complex>
using namespace std;

template<typename T>
T sqrt(T) {
    cout << "normal";
    return 5;
}

template<typename T>
complex<T> sqrt(complex<T>) {
    cout << "complex";
    return {1,2};
}

double sqrt(double);

void f(complex<double> z) {
    /*
    int x = sqrt(2); // sqrt <int> (int)
    double y = sqrt(2.0); // sqrt(double)
    complex<double> abc = sqrt(z); // sqrt<double> (complex<double>)
    */
}
/* Above doesn't seem to be working on my system though. Complains that call is ambiguous.*/

/* But the following works:
This still doesn't work -> int x = sqrt<int>(static_cast<int>(2)); // sqrt <int> (int)
    double y = sqrt(2.0); // sqrt(double)
This works->    complex<double> abc = sqrt<complex<double>>(z); // sqrt<double> (complex<double>)
*/