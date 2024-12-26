#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <string>

using namespace std;

enum class SortType {
    Ascending = 0,
    Descending = 1,
};

auto print(const auto& container) {
    for(const auto& item : container)
        cout << item << endl;
    return container;
}

auto print_map(const auto& m) {
    for(const auto& [k, v] : m)
        cout << "key=" << k << " value=" << v << endl;
    return m;
}

template<typename Key, typename Value>
auto swap_key_value(const map<Key, Value>& m) {
    auto r = map<Value, Key>{};
    for(const auto& [k, v] : m)
        r[v] = k;
    return r;
}

template<typename Key, typename Value>
auto keys_of(const map<Key, Value>& m) {
    auto r = list<Key>{};
    for(const auto& [k, v] : m)
        r.push_back(k);
    return r;
}

template<typename Item>
auto sort(const list<Item>& container, SortType sorttype) {
    auto l = list<Item>{};
    auto m = map<Item, bool>{};

    for(const auto& item : container)
        m[item] = true;

    if(sorttype == SortType::Ascending) {
        for(const auto& [k, v] : m)
            l.push_back(k);
    } else {
        for(const auto& [k, v] : m)
            l.push_front(k);
    }
    return l;
}

template<typename Container>
auto assign_to(const auto& container) {
    auto cont_new = Container{};
    for(const auto& item : container)
        cont_new.push_back(item);
    return cont_new;
}

// Functional Pipeline Higher Order Functions
auto operator| (const auto& left, const auto& right) {
    return right(left);
}

auto print() {
    return [](const auto& container) {
        return print(container);
    };
}

auto keys_of() {
    return [](const auto& m) {
        return keys_of(m);
    };
}

auto sort(SortType sorttype) {
    return [sorttype](const auto& container) {
        return sort(container, sorttype);
    };
}

int main(int argc, char* argv[])
{
    auto m = map<int, string>{
                              {1, "one"},
                              {2, "two"},
                              {10, "ten"},
                              {12, "twelve"},
                              };
    m[11] = "eleven"; // dynamic run-time assignment of a value to a key

    cout << endl << "Q1: print_map" << endl;
    print_map(m);

    cout << endl << "Q2: swap_key_value of map" << endl;
    auto key_value_swapped = swap_key_value(m);
    print_map(key_value_swapped);

    cout << endl << "Q3: keys_of map" << endl;
    auto keys = keys_of(m);
    print(keys);

    cout << endl << "Q4: descending_sort" << endl;
    auto desc_sort = sort(list<double>{5.5, 1.1, -4.4, 10.1, 9.9}, SortType::Descending);
    print(desc_sort);

    cout << endl << "Q5: descending_sort_intcasted" << endl;
    auto descending_sorted_intcasted = assign_to<vector<int>>(desc_sort);
    print(descending_sorted_intcasted);

    cout << endl << "Q6: functional pipeline with higher order functions" << endl;
    m | keys_of() | sort(SortType::Descending) | print();
}
