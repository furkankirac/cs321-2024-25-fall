// IsSame

#include <iostream>
#include <vector>
#include <list>

using namespace std;

template<typename T1, typename T2> struct IsSame       { static const bool value = false; };
template<typename T>               struct IsSame<T, T> { static const bool value = true; };


// struct IsSame_int_float {
//     static const bool value = false;
// };


// template<typename T1, typename T2>
// bool is_same_type() {
//     if constexpr( IsSame<T1, T2>::value )
//         return true;
//     else
//         return false;
// }

template<typename T>
void print(const T& container) {
    if constexpr(IsSame<T, vector<int>>::value) {
        cout << "Oh I like vector<int>s" << endl;
    }

    for(const auto& item : container) {
        cout << item << endl;
    }
}

void print_vector_int(const vector<int>& container) {
    cout << "Oh I like vector<int>s" << endl;

    for(const auto& item : container) {
        cout << item << endl;
    }
}

void print_list_int(const list<int>& container) {
    for(const auto& item : container) {
        cout << item << endl;
    }
}

int main(int argc, char* argv[])
{
    auto v1 = vector<int>{1, 2, 3};
    auto v2 = list<int>{11, 22, 33};

    // print<vector<int>>(v1);
    // print<list<int>>(v2);
    print(v1);
    print(v2);

    // cout << IsSame_int_float::value << endl;
    cout << IsSame<int, float>::value << endl;


    return 0;
}
