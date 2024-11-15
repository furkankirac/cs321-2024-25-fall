#include <iostream>
#include <vector>

void F1(auto& a, auto& b) { auto  t = a;  a = b;   b = t; }
void F2(auto* a, auto* b) { auto t = *a; *a = *b; *b = t; }

void Q1() {
    auto a = 1;
    auto b = 3.14f;
    auto c = 2.22;

    // 6 pts
    F1(a, b);
    std::cout << a << "; " << b << "; " << c << std::endl;

    // 12 pts
    F2(&b, &c);
    std::cout << a << "; " << b << "; " << c << std::endl;
}

void Q2() {
    // Memory Layout
}

// Q3
struct Pair {
    int a;
    int b;
    Pair() : a(0), b(0) {}
    Pair(int a, int b) : a(a), b(b) {}
    Pair(const Pair& other) : a(other.a), b(other.b) {}
};


void Q4() {
    struct SequenceGenerator {
        int val;

        SequenceGenerator(int start) : val(start) { }

        int operator() () {
            val++;
            return val - 1;
        }
    };

    auto sg = SequenceGenerator(10);
    std::cout << sg() << std::endl;
    std::cout << sg() << std::endl;
    std::cout << sg() << std::endl;
}

void Q5() {
    auto sg = [val=10]() mutable {
        val++;
        return val - 1;
    };
    std::cout << sg() << std::endl;
    std::cout << sg() << std::endl;
    std::cout << sg() << std::endl;
}

auto accumulate(const auto& container, const auto& func, auto init) {
    auto acc = init;
    for(const auto& item: container) {
        acc = func(acc, item);
    }
    return acc;
}

void Q6() {
    auto v = std::vector<int>{1, 2, 3};

    // intentionally used "auto acc" in pass by value style to make a copy of acc via compiler assitance
    // if we capture by ref, then pushing to acc would change the call site.
    // acc here and there would be the same acc
    // returning acc from lambda below for the "acc = func(acc, item)" line in accumulate algorithm
    // would be like writing "acc = acc;". The copy assign operator of acc would try to copy itself onto itself
    // which is not a good idea
    auto y = accumulate(v, [](auto acc, const auto& item) {
        // push new pair to the cloned acc
        acc.push_back(Pair(item, item+1));
        return acc; // return the cloned acc
    }, std::vector<Pair>());
}

int main(int argc, char* argv[])
{
    Q1();
    // Q3();
    // Q4();
    // Q5();
    // Q6();
}
