#include <type_traits>

#include "Poco/DigestStream.h"
#include "Poco/MD5Engine.h"
#include "spdlog/spdlog.h"

template <typename Int>
concept Integral = requires(Int i) {
    std::is_integral<Int>();
};

auto add(Integral auto x, Integral auto y) -> Integral auto { return x + y; }

auto main() -> int {
    Poco::MD5Engine md5;
    Poco::DigestOutputStream ds(md5);
    ds << "abcdefghijklmnopqrstuvwxyz";
    ds.close();

    spdlog::info("Welcome to spdlog! {}, {}", add(2, 3),
        Poco::DigestEngine::digestToHex(md5.digest()));
    return 0;
}
