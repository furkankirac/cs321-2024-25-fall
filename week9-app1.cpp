// pure functions != free functions --> functions that have no side-effect
// pure functions are better. eliminate state if possible.
// if state is definitely required, better use OOP to encapsulate it from the outside world in a lambda function

// compile-time pure functions are represented by template meta programming in C++
// and also "constexpr" keyword.
// meta-programming trick in templates

// Multiply, Divide, IsSame, ConditionalType
// constexpr, if constexpr


#include <iostream>

using namespace std;

int func() { // not a pure function
    static int i = 0;
    i++;
    return i;
}

struct FuncObj {
    int i = 0;
    auto get() const {
        return i;
    }
    int operator() () {
        i++;
        return i;
    }
};


int main(int argc, char* argv[])
{
    // cout << func() << endl;
    // cout << func() << endl;

    // {
    //     auto fo = FuncObj{};
    //     // auto value = fo.get();
    //     cout << fo() << endl;
    //     cout << fo() << endl;
    // }

    auto lambda1 = [i=0]() mutable {
        i++;
        return i;
    };

    auto lambda2 = [i=0]() mutable {
        i++;
        return i;
    };

    cout << lambda1() << endl;
    cout << lambda1() << endl;

    cout << lambda2() << endl;
    cout << lambda2() << endl;

    return 0;
}
