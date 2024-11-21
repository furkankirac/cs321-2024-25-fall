// ConditionalType

// template<...>
// struct blabla {
//     // static const bool value; /// ...
//     using type = ...; ///
// };


// auto value_returner(auto first, auto second, bool which) {
//     if(which) return first;
//     else return second;
// }

int main(int argc, char* argv[])
{
    using INT = int;

    // ConditionalType<int, float, true>::type; // --> int
    // ConditionalType<int, float, false>::type; // --> float

    return 0;
}
