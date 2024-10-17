// function pointers
// for_each

// Fraction class: Want to represent rational numbers with a numerator and denominator

// OOP: (encapsulates all necessary tools in a box that communicates
//  with caller via c-tors, assignment operators, and casting
// ctor/dtor
// implicit/explicit constructors
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

// operator== and operator+ overloads for Celsius/Fahrenheit

#include <iostream>
#include <vector>


int dosmt1(int a, int b) { return a + b; }
int dosmt2(int a, int b) { return a - b; }
int dosmt3(int a, int b) { return a * b; }

double dosmt4(double a) { return a + 1; }

int take_square(int a) { return a * a; }

// typedef int INT; // C type aliasing
// using INT = int; // C++ type aliasing

// this is a type that stores a memory address
// at that memory address there is compiled binary code for a function
// that expects 2 integers to be available at stack
// does something with them and push the returned int to the stack
using TwoInters = int (*)(int, int);
// typedef int (*TwoInters)(int, int);

using OneDoubler = double (*)(double);
using OneInter = int (*)(int);

template<typename T>
void print(const std::vector<T>& v) {
    auto sz = v.size();
    for(int i=0; i<sz; i++)
        std::cout << v[i] << " ";

    std::cout << std::endl;
}

// void print_int(std::vector<int> v) {
//     auto sz = v.size();
//     for(int i=0; i<sz; i++)
//         std::cout << v[i] << " ";

//     std::cout << std::endl;
// }

// void print_float(std::vector<float> v) {
//     auto sz = v.size();
//     for(int i=0; i<sz; i++)
//         std::cout << v[i] << " ";

//     std::cout << std::endl;
// }

template<typename T>
void for_each(std::vector<T>& v, OneInter transform_func) {
    auto sz = v.size();
    for(int i=0; i<sz; i++) {
        auto& item = v[i];
        item = transform_func(item);
    }
}

// template void print<double>(const std::vector<double>&);


int main(int argc, char* argv[])
{
    auto v = std::vector<int>(10); // size of the vector storing many ints is 10
    for(int i=0; i<10; i++)
        v[i] = i;

    auto vf = std::vector<float>(10); // size of the vector storing many ints is 10
    for(int i=0; i<10; i++)
        vf[i] = i * 1.1f;

    print<int>(v);
    for_each<int>(v, &take_square);
    print<int>(v);

    // print_int(v);
    print<float>(vf);
    // print_float(vf);




    TwoInters func;
    int choice = 3;

    if(choice == 1)
        func = &dosmt1;
    else if(choice == 2)
        func = &dosmt2;
    else if(choice == 3)
        func = &dosmt3;
    // else if(choice == 4)
    //     func = &dosmt4;

    auto retval = func(10, 20);
    std::cout << retval << std::endl;

    return 0;
}
