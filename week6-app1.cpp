// overview of encapsulating functions (OOP):
//   functions themselves (with func pointers)
//   function objects (overloading the function call operator  "operator()"
//   lambda functions

// GENERATORS (Coroutines): for functional programming
// mutable lambdas: fibonacci generator

// generic programming:
//   transform algorithm (map in other languages)
//     inline version with side-effects vs pure version
//   accumulate algorithm (reducer in other languages)
//   filter algorithm
//   count_if algorithm

#include <iostream>

// 0, 1, 1, 2, 3, 5, 8,

using namespace std;

struct FibonacciGenerator {
    // ------> this
    int& a;
    int& b;

    FibonacciGenerator(int& a, int& b) : a(a), b(b) { }

    int operator() (/*const FibonacciGenerator* this*/) const {
        int c = a + b;
        // cout << c << endl;
        a = b;
        b = c;
        return c;
    }
};

int main(int argc, char* argv[])
{
    int a = 0;
    int b = 1;
    // auto fg = FibonacciGenerator(m, n);

    auto fg_lambda = [&a=a, &b=b]() {
        int c = a + b;
        // cout << c << endl;
        a = b;
        b = c;
        return c;
    };

    for(int i=0; i<10; i++) {
        cout << fg_lambda() << endl;
    }

    cout << "a=" << a << " b=" << b << endl;

    return 0;
}
