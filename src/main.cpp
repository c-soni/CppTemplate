#include <iostream>
#include <type_traits>

template <typename Int>
concept Integral = requires(Int i) {
    std::is_integral<Int>();
};

auto add(Integral auto x, Integral auto y) -> Integral auto { return x + y; }

int main() {
    std::cout << "Hello world " << add(2, 3) << std::endl;
    return 0;
}
