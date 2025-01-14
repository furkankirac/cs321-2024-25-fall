#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

template<typename T> struct IsInt { static const bool value = false; };
template<>           struct IsInt<int> { static const bool value = true; };
template<>           struct IsInt<const int> { static const bool value = true; };
template<>           struct IsInt<int&> { static const bool value = true; };
template<>           struct IsInt<const int&> { static const bool value = true; };

template<bool b, typename T1, typename T2>  struct ConditionalType { using type = T1; };
template<typename T1, typename T2>          struct ConditionalType<false, T1, T2> { using type = T2; };


template<typename C1, typename C2>
auto zip(const C1& c1, const C2& c2) {
    // every C++ container already has a "using value_type = T;" in its scope as a rule of thumb
    // we're using it to access the container's item type
    using ITEM1 = typename C1::value_type;
    using ITEM2 = typename C2::value_type;
    auto cont_new = vector<pair<ITEM1, ITEM2>>();
    auto iter1 = c1.begin();
    auto iter2 = c2.begin();
    while (iter1 != c1.end() && iter2 != c2.end())
        cont_new.push_back(pair{*iter1++, *iter2++});
    return cont_new;
}

template<typename C1, typename C2>
auto repeated_items(const C1& c1, const C2& c2, auto func) {
    using ITEM1 = typename C1::value_type;
    using ITEM2 = typename C2::value_type;
    static const auto C1_IS_TIMES = IsInt<ITEM1>::value;
    using ITEM = ConditionalType<C1_IS_TIMES, ITEM2, ITEM1>::type;

    auto container = vector<ITEM>();
    auto iter1 = c1.begin();
    auto iter2 = c2.begin();
    while (iter1 != c1.end() && iter2 != c2.end()) {
        if constexpr(C1_IS_TIMES)
            func(container, *iter1++, *iter2++);
        else
            func(container, *iter2++, *iter1++);
    }
    return container;
}


template<typename T>
concept IsContainer = requires(T t) {
    t.begin();
    t.end();
    t.size();
};

void print(const IsContainer auto& c) {
    for(const auto& item : c)
        cout << item << " ";
}

template<typename T>
void print(T value) requires (!IsContainer<T>) {
    cout << value << endl;
}


template<typename T>
void print_combo(const T& value) {
    if constexpr(IsContainer<T>) {
        for(const auto& item : value)
            cout << item << " ";
    } else {
        cout << value << endl;
    }
}


int main(int argc, char* argv[])
{
    auto v = vector<int>{3, 1, 2};
    auto l = list<string>{"Do", "Re", "Mi", "Fa"};
    // auto vl = zip(v, l);
    auto vl = repeated_items(v, l, [](auto& c, const auto& times, const auto& item) {
        for(int i=0; i<times; i++)
            c.push_back(item);
    });
    print_combo(vl);
    print_combo(vl.size());
}
