template<typename T, typename U>
void f(const T*, U(*)(U));

int g(int);

void h(const char * p) {
    // Below f becomes (void f<char, int>(const char *, int (*)(int)))
    f(p, g); /* T is char, U is int. Recursively can be determined 
              * for both even though it is not directly deducible.
              */
    // But below cannot be deduced.
    // f(p, h); // Cannot deduce what would U be.
}
/* If a template parameter can be deduced from more than one 
 * function argument, the same type must be the result of each 
 * deduction 
 */