// compile-time pure functions are represented by template meta programming in C++
// and also "constexpr" keyword.
// meta-programming trick in templates

// Multiply, Divide, IsSame
// parameter packs, pack expansions


#include <iostream>

using namespace std;

// auto multiply_10_3 = 30;
// auto multiply_5_8 = 40;

template<int i, int j> struct Multiply { static const int value = i * j; };

template<int i, int j> struct Divide        { static const int value = i / j; };
template<int a>        struct Divide<0, a>  { static const int value = 0; };
template<int a>        struct Divide<a, 0>  { static const int value = 0; };
template<>             struct Divide<0, 0>  { static const int value = 0; };

template<int i, int j>
constexpr auto divide() {
    if constexpr(i == 0 || j == 0) {
        return 0;
    } else {
        return i / j;
    }
}


// struct Multiply_10_3 { static const int value = 10 * 3; };
// struct Multiply_3_5 { static const int value = 3 * 5; };

inline int safe_divide(int val1, int val2) {
    int d;
    if(val2 == 0)
        d = 0;
    else
        d = val1 / val2;
    return d;
}


int main(int argc, char* argv[])
{
    auto a = Multiply<10, 3>::value;
    cout << a << endl;

    auto b = Multiply<3, 5>::value;
    cout << b << endl;

    auto c = Divide<10, 2>::value;
    cout << c << endl;

    auto d = Divide<0, 0>::value;
    cout << d << endl;

    // auto val1 = 10;
    // auto val2 = 0;
    // safe_divide(val1, val2);
    // int d;
    // if(val2 == 0)
    //     d = 0;
    // else
    //     d = val1 / val2;
    // cout << d << endl;

    // // optimizer compiler switch is -O3
    // if (a > 10)
    //     cout << ">10" << endl;
    // else
    //     cout << "<=10" << endl;

    // cout << ">10" << endl;


    return 0;
}
