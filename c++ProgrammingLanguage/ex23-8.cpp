template<typename T> class Matrix;

template<typename T>
class Vector{
    T v[4];
public:
    // friend function * that multiplies Matrix and vector.
    friend Vector operator*<>(const Matrix<T>&, const Vector&); // This <> is must for friend templates.
    // Some code.
};

template<typename T>
class Matrix {
    Vector<T> v[4];
public:
    // friend function * that multiplies Matrix and vector.
    friend Vector<T> operator*<>(const Matrix&, const Vector<T> &); // This <> is must for friend templates.
    // Some code.
};

template<typename T>
Vector<T> operator* (const Matrix<T> & m, const Vector<T>& v) {
    Vector<T> r;
    // Do multiplication. Used m.v[i] and v.v[i] directly.
    return r;
}