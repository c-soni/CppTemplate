#include <type_traits>

#include "fmt/format.h"
#include "nlohmann/json.hpp"
#include "spdlog/spdlog.h"

template <typename Int>
concept Integral = requires(Int i) {
    std::is_integral<Int>();
};

auto add(Integral auto x, Integral auto y) -> Integral auto { return x + y; }

auto main() -> int {

    nlohmann::json obj { { "pi", 3.141 }, { "happy", true }, { "name", "C" },
        { "nothing", nullptr }, { "answer", { { "everything", 42 } } },
        { "list", { 1, 0, 2 } },
        { "object", { { "someFormattedString",
                          fmt::format("{} I am not a number", "Arrgh!") },
                        { "value", 111 } } } };
    spdlog::info("Welcome to spdlog!\n{}\nSum is: {}", obj.dump(4), add(2, 3));
    return 0;
}
