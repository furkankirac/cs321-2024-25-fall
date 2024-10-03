// C++ is the new assembly language!
// tries to aim being as high level as possible and
// to achieve this with zero extra speed cost

// it's like trying to be hot and cold at the same time (dondurmali irmik helvasi?)
// and always keep hot and cold parts separate.
// this part is the mission of the C++ Design Committee

// Our mission is to use this still dangerous tool carefully
// Linus Torvalds when designing Linux didn't like C++'s default behaviours
// So, he chose C. Cannot blame the guy. He wanted to more precisely control the OS code.



// stack memory vs heap memory
// value semantics vs reference semantics

// global scope, local scope
// free-functions

// class/struct? object? ------> type? instance?
// typedef (C)

// c-tor of a primitive type
// c-tor of a complex type (struct)

// write a c-tor of a struct instance as a free function (imperative programming paradigm)
// write a c-tor of a struct instance as a member function (OOP paradigm)

// allocate memory at run-time (dynamic memory allocation)
// free memory at run-time

// write a dtor as a free function (imperative programming paradigm)
// write a dtor as a member function (OOP paradigm)

// member variables ~= attributes ~= properties (OOP)

struct Vector2d {
    // --------> this
    int dim1;
    int dim2;

    // Vector2d(int d1, int d2) {
    //     dim1 = d1;
    //     dim2 = d2;
    // }

    Vector2d() {

    }

    Vector2d(/*Vector2d* this,*/ int dim1, int dim2) : dim1(dim1), dim2(dim2)
    {
        // this->dim1 = dim1;
        // this->dim2 = dim2;
    }

    Vector2d operator+(/*const Vector2d* this,*/ const Vector2d& right) const {
        Vector2d retval;

        retval.dim1 = this->dim1 + right.dim1;
        retval.dim2 = dim2 + right.dim2;

        // this->dim1 = 10000;

        return retval;
    }

};



#include <iostream>

int main(int argc, char* argv[])
{
    Vector2d a(/*a, */10, 5);

    // a.dim1 = 10;
    // a.dim2 = 5;

    Vector2d b(-3, 14);
    // b.dim1 = -3;
    // b.dim2 = 14;

    Vector2d c = a + b; // addVector2d(a, b);
    // Vector2d c = operator+(a, b);
    // [10, 5] + [-3, 14] ---> [7, 19]

    std::cout << "dim1 = " << c.dim1 << std::endl;
    operator<<(std::cout, "dim1");
    std::cout << "dim2 = " << c.dim2 << std::endl;

    return 0; // 0 means everything is okay
}
