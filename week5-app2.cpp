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

template<typename T>
T take_square(T a) { return a * a; }

// int addK_MulM(int a, int k, int m) { return (a+k)*m; }

int global_k;
int global_m;
int addK_MulM(int a) { return (a+global_k)*global_m; }

// float take_square_float(float a) { return a * a; }

template<typename Container>
void print(const Container& v) {
    for(const auto& item : v)
        std::cout << item << " ";

    std::cout << std::endl;
}

template<typename Container, typename Obj>
void for_each(Container& v, const Obj& obj) {
    for(auto it = v.begin(); it != v.end(); it++) {
        auto& item = *it;
        item = obj(item);
    }
}

// template<typename Container, typename Func>
// void for_each(Container& v, Func transform_func, int k, int m) {
//     for(auto it = v.begin(); it != v.end(); it++) {
//         auto& item = *it;
//         item = transform_func(item, k, m);
//     }
// }

template<typename T>
struct AddK_MulM {
    T k;
    T m;

    AddK_MulM(T k, T m) : k(k), m(m) { }

    T operator() (T a) const {
        return (a + this->k) * this->m;
    }
};

auto AddK_MulM_lambda = [k=15, m=2](auto a) {
    return (a + k) * m;
};

template<typename T>
struct AddK {
    T k;
    AddK(T k) : k(k) { }

    T operator() (T a) const {
        return a + this->k;
    }
};

int main(int argc, char* argv[])
{
    auto v = std::vector<float>{1.1, 2.2, 3.3, 10.1, 20.2};
    // auto obj = AddK_MulM<float>(15, 2);
    auto obj = AddK<float>(11.11);
    auto obj_lambda = [k=11.11f](const auto& a) {
        return a + k;
    };


    // for_each(v, obj_lambda);
    for_each(v, AddK_MulM_lambda);


    print(v);

    return 0;
}
