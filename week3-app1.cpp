// C has malloc and free for dynamic memory handling.
// C++ has new/delete. (C++ old dialects use these, older than C++'11 - 2011)
// Vector object with dynamic dimensions
// static variables, static member variables
// Generic Programming = Templates in C++
// const keyword
// curly bracket usage for deeper lower scopes

// function overloading
// operators and operator overloading
// function parameters: pass by value, pass by reference

// auto, AAA rule (almost always auto)

#include <iostream>
#include "memory.h"

int main(int argc, char* argv[])
{
    // we are at the leftmost location in our logical memory
    // that is also beginning of the stack space for my app

    int a = 10; // sizeof(int)

    int* p = &a;
    int** p2 = &p;

    float f = 3.14f;
    float* f_heap = (float*)malloc(sizeof(float)); // dynamic memory allocation
    free(f_heap);

    float* f_heap_ = (float*)malloc(sizeof(float)*20); // dynamic memory allocation
    free(f_heap_);

    float* f_heap_cpp = new float;
    delete f_heap_cpp;

    float* f_heap_cpp_arr = new float[20];
    delete[] f_heap_cpp_arr;

    std::cout << sizeof(int*) << std::endl;
    std::cout << sizeof(short) << std::endl;
    std::cout << sizeof(int) << std::endl;
    std::cout << sizeof(long int) << std::endl;
    std::cout << sizeof(float) << std::endl;
    std::cout << sizeof(double) << std::endl;
    std::cout << sizeof(long double) << std::endl;

    return 0;
}
