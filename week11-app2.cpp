// we saw 3 main algorithms:
// - transform (called "map" in some languages)
// - filter
// - accumulate (called "reduce" in some languages)
// above algorithms cover 75% of all the necessities, BUT we need other algorithms as well

// nested for-loops in functional programming paradigm: cartesian_product
// zip/attach algorithm: attaching two or more objects together for making them act as a single sequence

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <tuple>

using namespace std;

auto cartesian_product(const auto& cont1, const auto& cont2, const auto& cont3, auto func) {
    for(const auto& item1 : cont1) {
        for(const auto& item2: cont2) {
            for(const auto& item3: cont3) {
                func(item1, item2, item3);
            }
        }
    }
}

// homework: remove func and make the cartesian_product return a new container (vector<>)
// that contains std::pair{item1, item2}
auto cartesian_product(const auto& cont1, const auto& cont2, auto func) {
    for(const auto& item1 : cont1) {
        for(const auto& item2: cont2) {
            func(item1, item2);
        }
    }
}

template<typename C1, typename C2>
auto zip(const C1& c1, const C2& c2) {
    using ITEM1 = decltype(*c1.begin());
    using ITEM2 = decltype(*c2.begin());

    auto cont_new = vector<std::pair<ITEM1, ITEM2>>{};
    auto sz = c1.size();
    if(c2.size() < sz)
        sz = c2.size();
    for(int i=0; i<sz; i++) {
        cont_new.push_back(std::pair{c1[i], c2[i]});
    }
    return cont_new;
}


int main(int argc, char* argv[])
{
    auto v1 = vector<int>   {1,     2,       3,     4,    5}; // 5 element
    auto v2 = list<float>   {1.1,   2.2,    -3.3,  -4.4};     // 4 element
    auto v3 = vector<string>{"aaa", "bbb",  "ccc"};           // 3 element

    cartesian_product(v1, v2, [](auto item1, auto item2) {
        cout << item1 << ", " << item2 << endl;
    });


    // auto v_zipped = zip<vector<int>, vector<float>>(v1, v2);
    // auto v_zipped = zip(v1, v2, v3); // vector<pair<int, float>>
    // print_(v_zipped);
    // auto v_zipped = vector<tuple<int, float, string>>{
    //    {1, 1.1, "aaa"},
    //    {2, 2.2, "bbb"},
    //    {3, -3.3, "ccc"},
    //    {4, -4.4, "ddd"},
    //    {5, 5.5, "eee"},
    // }

   // cartesian_product(v1, v2, [](const auto& i1, const auto& i2) {
   //     cout << "[" << i1 << ", " << i2 << "]" << endl;
   // });

    // cartesian_product(v1, v2, v1, [](const auto& i1, const auto& i2, const auto& i3) {
    //     cout << "[" << i1 << ", " << i2 << ", " << i3 << "]" << endl;
    // });

    return 0;
}
