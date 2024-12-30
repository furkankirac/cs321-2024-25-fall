// SUMMARY OF THE COURSE
// ------------------------------------------------------------------------------

// SEMANTICS:
// - value semantics vs reference semantics
// - const correctness: const keyword

// SCOPES:
// - global scope
// - local scope, curly bracket usage for deeper lower scopes

// TYPES / INSTANCES(VALUES)
// - primitive types / complex types (struct/class)
// - staticness: static variables, static member variables
// - casting types to other types
// - automatic type deduction: auto keyword, AAA (almost always auto)

// REFLECTION: (ask the compiler about stuff)
// - sizeof, decltype, sizeof..., etc.

// MEMORY LAYOUT:
// - stack, heap, static memory
// - allocate memory at run-time (dynamic memory allocation), free memory at run-time
// - C has malloc and free for dynamic memory handling.
// - C++ has new/delete. (C++ old dialects use these, older than C++'11 - 2011)
// - C++ has std::vector object with dynamic dimensions for the same purpose
// POINTERS:
// - memory pointers, pointing to anything that is in the memory (function pointers, variable pointers)

// FUNCTIONAL PROGRAMMING:
// FUNCTIONS:
// - free-functions
// - OOP-functions=methods
// - functions themselves (with func pointers),
// - function objects
// - lambda functions (immutable, mutable)
// PARAMETERS:
// - pass by value, pass by reference
// OVERLOADING
// - as a way of indirect control flow control (instead of imperative IF)
// HIGHER ORDER FUNCTIONS: reverse, filter, take<x>, transform, accumulate algorithms
//  a function returning a function object: delays function use
//  less_than(x), greater_than(x), get_name(), ...
// PURE FUNCTIONS --> functions that have no side-effect, pure functions are better. eliminate state if possible.
// compile-time pure functions are represented by template meta programming in C++, and also with constexpr
// COMPILE-TIME FUNCTIONS:
// - template metaprogramming + constexpr functions
// COROUTINES (more elegant routines/functions):
// - C++ has Coroutines but will study them in Advanced C++
// - GENERATORS: we downgraded generators to their function equivalents
// OPERATORS and OPERATORS AS FUNCTIONS:
// - operator overloading

// OOP:
// - Objects: struct/class
// - member variables ~= attributes
// - constructors / destructors, implicit/explicit constructors, converting constructors
// - copy-ctor, copy-assignment
// - containers, iterators, range-for-loop
// - inheritance (left out for Adv. C++)

// GENERICS = Represented by TEMPLATES in C++
// - Meta-programming tricks: IsSame<T>, ConditionalType<...>
// - Variadics (... operator for parameter packs compression/expansion)
// - sizeof... operator
// - CONCEPTS, "requires" expression: IsContainer<T>, IsPushable<T>, ...

// ALGORITHMS:
// - "transform" algorithm ("map" in other languages)
// - "accumulate" algorithm ("reduce(r)" in other languages)
// - "filter" algorithm
// - nested for-loops in functional programming paradigm: cartesian_product
// - zip/attach algorithm: attaching two or more objects together for making them act as a single sequence

// GENERICS + FUNCTIONAL
// - composing functions
// - pipeline operator overloading

int main()
{
    return 0;
}
