// introducing std::vector<T>

// iterators and range-for-loop

// "transform" algorithm with function pointers

// encapsulating functions:
//   1) functions themselves (with func pointers),
//   2) function objects
//   3) lambda functions

// unified/universal construction:
//   stricter construction with {} instead of (),
//   initializer_list support for ctors

#include <iostream>
#include <vector>
#include <list>

using OneInterFunc = int (*)(int);
using TwoInterFunc = int (*)(int, int);

int take_square(int a) { return a * a; }

template<typename T>
void print(const std::vector<T>& v) {
    auto sz = v.size();
    for(int i=0; i<sz; i++)
        std::cout << v[i] << " ";

    std::cout << std::endl;
}

template<typename T>
void for_each(std::vector<T>& v, OneInterFunc transform_func) {
    auto sz = v.size();
    for(int i=0; i<sz; i++) {
        auto& item = v[i];
        item = transform_func(item);
    }
}

int main(int argc, char* argv[])
{
    auto v = std::vector<int>{1, 2, 3, 10, 20};
    auto it = v.begin();
    // *it = 5; // 1
    // it++;
    // *it = 10;
    // it += 2;
    // *it = 20;
    // it[-1] = 30;
    // v.end();
    // v.size();

    // auto sz = v.size();
    // for(auto it=v.begin(); it!=v.end(); it++) {
    //     const auto& item = *it;
    //     std::cout << item << std::endl;
    // }

    for(const auto& item : v) { // range for-loop
        std::cout << item << std::endl;
    }


    // for_each(v, &take_square);
    // print(v);

    return 0;
}
