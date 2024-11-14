// in search of a simpler and more understandable generic way of writing code
//  the dance of OOP, FP and GP paradigms

// lifting a function (higher order functions):
//  a function returning a function object: delays function use
// less_than(x), greater_than(x), get_name(), ...

// composing functions

// extra generic algorithms on containers


#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum class Genre {
    Scifi,
    Fantasy,
    Thriller,
};

struct Book {
    double price; // 8 bytes
    string title; // 32 bytes
    Genre genre;

    // Book(double price, string title, Genre genre)
    //     : price(price), title(title), genre(genre) { }
};


auto get_price_(const auto& item) { // real worker
    return item.price;
}

auto get_price() { // managerial level
    return [](const auto& item) {
        return get_price_(item);
    };
}

bool less_than_(const auto& item, auto value) { // whether item is less than value
    return item < value;
}

auto less_than(auto value) { // whether something is less than value
    return [value](const auto& item) {
        return less_than_(item, value);
    };
}

// template<typename F, typename G>
auto compose(auto f, auto g) {
    return [f, g](auto item) {
        return g(f(item));
    };
}

auto operator|(auto f, auto g) {
    return compose(f, g);
    // return [f, g](auto item) {
    //     return g(f(item));
    // };
}

template<typename Container>
auto filter(const Container& cont, const auto& func) {
    auto new_cont = Container{};
    for(const auto& item : cont) {
        if(func(item)) {
            new_cont.push_back(item);
        }
    }
    return new_cont;
}

void print(const auto& cont) {
    for(const auto& item : cont) {
        cout << item.title << endl;
    }
}


auto printer_(const auto& item) {
    cout << item << endl;
}

auto printer() {
    return [](const auto& item) {
        printer_(item);
        return item;
    };
}

int main(int argc, char* argv[])
{
    // auto s = string{"Name of the Wind"};
    // cout << sizeof(s) << endl;
    // cout << sizeof(Genre) << endl;
    auto v = vector<Book>{
        {10.5, "Harry Potter", Genre::Fantasy},
        {15.1, "Name of the Wind", Genre::Fantasy},
        {50, "Introduction to ML", Genre::Thriller},
    };
    // v.push_back(Book{10.5, "Harry Potter", Genre::Fantasy});

    const auto& item = v[0];
    // auto price_worker = get_price();
    // auto real_price = price_worker(item);

    // auto less_than_20_worker = less_than(20);

    // auto result = less_than_20_worker(real_price);
    // cout << real_price << endl;
    // cout << result << endl;

    // auto f = get_price(); // this is a lambda that reads the price out of any item
    // auto g = less_than(20); // this is a lambda that checks if the value is less than 20
    // auto GoF = compose(f, g);

    // auto GoF = get_price() | less_than(20);
    // cout << GoF(item) << endl;

    // auto comp = compose(compose(compose(get_price(), printer()), less_than(15)), printer());
    // auto v_filtered = filter(v, comp);
    auto v_filtered = filter(v, get_price() | printer() | less_than(15) | printer());
    // transform(v, get_reverse() | take(2));
    print(v_filtered);

    return 0;
}
