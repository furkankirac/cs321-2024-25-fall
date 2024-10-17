// function pointers
// for_each

// Fraction class: Want to represent rational numbers with a numerator and denominator

// OOP: (encapsulates all necessary tools in a box that communicates
//  with caller via c-tors, assignment operators, and casting
// ctor/dtor
// copy-ctor, copy-assignment
// casting
// inheritance (will discuss later)

// function overloading, overload set
// operators and operator overloading

// literals, types of constants (remember units in your Physics class: 9.8 m/s^2)
// user-defined literals (a special way to create your own literals)

// Celsius/Fahrenheit example
// converting constructors

// pass by value, pass by reference, pass by constant reference
// implicit/explicit constructors

// operator== and operator+ overloads for Celsius/Fahrenheit
// static attributes and staticness. static variable initialization

#include <iostream>

struct Fraction {
    int n;
    int d;

    /*explicit*/ Fraction(int n) : n(n), d(1) { }
    Fraction(int n, int d) : n(n), d(d) { }

    Fraction(const Fraction& other) : n(other.n), d(other.d) {
        std::cout << "Copy c-tor is run" << std::endl;
    }

    void operator=(const Fraction& other) {
        auto& self = *this;
        this->n = other.n;
        self.d = other.d;
        std::cout << "Copy assignment is run" << std::endl;
    }
};

void print(const Fraction& f) {
    std::cout << f.n << "/" << f.d << std::endl;
}

void print(int a) {
    std::cout << a << std::endl;
}

int main(int argc, char* argv[])
{
    auto f1 = Fraction(1, 2); // 1/2
    auto f2 = Fraction(5); // 5/1

    Fraction f3 = 15;

    auto f4 = f1; // copy c-tor

    auto& f5 = f4;

    f5 = f1;

    print(f1);
    print(f2);
    print(f3);
    print(f4); // same value with f3

    return 0;
}
