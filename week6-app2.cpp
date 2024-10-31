// generic programming:
//   transform algorithm (map in other languages)
//     inline version with side-effects vs pure version
//   filter algorithm
//   count_if algorithm

//   accumulate algorithm (reducer in other languages)

#include <iostream>
#include <vector>

using namespace std;

template<typename Container>
void print(const Container& container) {
    // for(auto it = container.begin(); it != container.end(); it++) {
    //     const auto& item = *it;
    //     cout << item << " ";
    // }
    for(const auto& item : container)
        cout << item << " ";

    cout << endl;
}

// template<typename Container, typename Function>
void transform_inline(auto& container, const auto& func) {
    for(auto& item : container) {
        item = func(item);
    }
}

auto transform(const auto& container, const auto& func) {
    auto container_new = container;
    transform_inline(container_new, func);
    return container_new;
}


template<typename Container>
auto filter(const Container& container, const auto& func) {
    // decltype(container) container_new();
    auto container_new = Container();
    for(auto& item : container) {
        if(func(item)) {
            container_new.push_back(item);
        }
    }
    return container_new;
}

auto accumulate(const auto& container, const auto& func, auto init) {
    auto value = init;
    for(const auto& item: container) {
        value = func(value, item);
    }
    return value;
}



auto multiply_by_2 = [](const auto& item) {
    return item * 2;
};

int main(int argc, char* argv[])
{
    auto v = vector<float>{1.1f, 2.2f, 3.3f};
    print(v);
    transform_inline(v, multiply_by_2);
    print(v);
    auto v2 = transform(v, [](const auto& item) {
        return item + 1.1f;
    });
    print(v);
    print(v2);

    auto v_filtered = filter(v2, [](const auto& item) { return item > 4.0f; });
    print(v_filtered);

    auto sum = 0.0f;
    for(const auto& item: v_filtered) {
        sum = sum + item;
    }
    cout << "sum=" << sum << endl;

    auto product = accumulate(v_filtered, [](const auto& value, const auto& item) {
        return value * item;
    }, 1.0f);

    // auto product = 1.0f;
    // for(const auto& item: v_filtered) {
    //     product = product * item;
    // }
    cout << "product=" << product << endl;


    return 0;
}
