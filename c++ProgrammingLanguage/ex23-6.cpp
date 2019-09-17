template<typename Scalar>
class complex{
    Scalar re, im;
public:
    complex():re{}, im{} {} // Note that we are using {} rather than () to init private members.
    template<typename T>
    complex(T rr, T ii = 0): re{rr}, im{ii} {} // If we use () instead {}, it would allow narrowing which might not be correct for all the cases.

    complex(const complex&) = default; // Default copy constructor
    template<typename T>
    complex(const complex<T> &c) : re{c.real()}, im{c.imag()} {} // Same here.
};

complex<float> cf; // default value
complex<double> cd{cf}; // OK: uses float to double conversion
// complex<float> cf2{cd}; // Error: no implicit double to float conversion

// complex<float> cf3 {2.0, 3.0}; // Error: no implicit double->float conversion.
complex<double> cd2 {2.0F, 3.0F}; // OK. uses float to double conversion.

class Quad{
// No conversion to int
};

complex<Quad> cq;
// complex<int> ci {cq}; // No Quad to int conversion