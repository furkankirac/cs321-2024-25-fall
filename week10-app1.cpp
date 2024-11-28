// Higher Order Functions: reverse, filter, take<x>, transform, accumulate algorithmss
// "and(...)" predicate

// C++ concepts, requires expression
// IsContainer<T>, IsPushable<T>

#include <iostream>
#include <vector>
// #include <list>

using namespace std;

// HW: improve this so that it doesn't use random access iterator
auto reverse_(auto cont_new) {
    auto sz = cont_new.size();
    auto sz_minus_one = sz - 1;
    for(int i=0; i<sz/2; i++) {
        std::swap(cont_new[i], cont_new[sz_minus_one-i]);
        // auto t = cont_new[i];
        // cont_new[i] = cont_new[sz_minus_one-i];
        // cont_new[sz_minus_one-i] = t;
    }
    return cont_new;
}

auto reverse() {
    return [](auto& cont_new) {
        return reverse_(cont_new);
    };
}

auto higher_than_(auto a, auto b) { return a > b; }
auto higher_than(auto b) {
    return [b](auto a) {
        return higher_than_(a, b);
    };
}

auto less_than_(auto a, auto b) { return a < b; }
auto less_than(auto b) {
    return [b](auto a) {
        return less_than_(a, b);
    };
}

template<typename Container>
auto filter_(const Container& container, auto func) {
    auto cont_new = Container{};
    for(const auto& item : container) {
        if (func(item))
            cont_new.push_back(item);
    }
    return cont_new;
}

auto filter(auto func) {
    return [func](const auto& container) {
        return filter_(container, func);
    };
}

// and(higher_than(0), less_than(60))

bool and_(auto item, auto f1, auto f2) {
    return f1(item) && f2(item);
}

auto AND(auto f1, auto f2) {
    return [f1, f2](auto item) {
        return and_(item, f1, f2);
    };
}


// HW, convert this to iterators
template<int sz, typename Container>
auto take_(const Container& container) {
    auto cont_new = Container{};
    for(int i=0; i<sz; i++) {
        cont_new.push_back(container[i]);
    }
    return cont_new;
}

template<int sz>
auto take() {
    return [](const auto& container) {
        return take_<sz>(container);
    };
}

auto add_(auto a, auto b) { return a + b; }
auto add(auto b) {
    return [b](auto a) {
        return add_(a, b);
    };
}

auto transform_(auto cont_new, auto func) {
    for(auto& item : cont_new) {
        item = func(item);
    }
    return cont_new;
}

auto transform(auto func) {
    return [func](const auto& cont_new) {
        return transform_(cont_new, func);
    };
}

auto operator|(const auto& left, const auto& right) {
    return right(left);
}


template<typename Container>
concept IsContainer = requires(Container container) {
    container.begin();
    container.end();
    container.size();
};

template<typename T>
requires (!IsContainer<T>)
auto print_(T item) {
    cout << item << endl;
}

// template<IsContainer Container>
    // requires IsContainer<Container>
auto print_(const IsContainer auto& container)
{
    for(const auto& item : container) {
        cout << item << ", ";
    }
    cout << endl;
    return container;
}

auto print() {
    return [](const auto& container) {
        return print_(container);
    };
}

void func(int) { }

int main(int, char* [])
{
    func({});

    print_(5);
    using CONTAINER = std::vector<float>;

    CONTAINER{1.1, 50.3, -3, 5, -10, 100}
        | print()
        | reverse()
        | print()
        | filter(AND(higher_than(-5), less_than(60)))
        | print()
        | take<2>()
        | print()
        | transform(add(2))
        | print()
        // HOMEWORK BELOW:
        // | accumulate(multiplier(), 1.0f)
        // | print()
        ;

    return 0;
}
