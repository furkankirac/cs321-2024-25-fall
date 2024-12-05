// pair, tuple, std::map, variadic templates, sizeof... operator, structured binding

#include <tuple>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// struct KLMN {
//     string k;
//     int l;
//     double m;
//     float n;
// };

using KLMN = tuple<string, int, double, float>;

// template<typename T1, typename T2>
// struct Pair {
//     T1 first;
//     T2 second;
// };

// template<typename T1, typename T2>
// using AB = Pair<int, float>;

// struct AB {
//     int a;
//     float b;
// };

// using X = std::variant<int, float, double>;

// auto v = std::vector<X> { int{}, float{}, double{}, double{}, float{} };

// template<typename First, typename ... Rest> // First=int, Rest=int,float,double,int (type parameter pack)
// inline auto minimum_of(First first, Rest ... rest) { // first=5, rest=10,3.14f,3.14,20 (value parameter pack)
//     auto min_val = first;
//     if constexpr(sizeof...(rest) > 0) {
//         auto retval = minimum_of(rest...);

//     }
// }


int main(int, char* [])
{
    // auto val = minimum_of(5, 10, 3.14f, 3.14, 20);

    auto m = std::unordered_map<int, string>{
        {12, "twelve"},
        {1, "one"}, // int, const char[4] ---> const char *
        {2, "two"},
    };

    for(const auto& [key, value] : m) {
        cout << "key=" << key << ", value=" << value << endl;
    }

    return 0;
}
