import cns;

#include <print>

auto main() -> int {

    try {
        const auto v1 = cns::Vector3D{1.0, 2.0, 3.0};
        const auto v2 = cns::Vector3D{-3.0, 2.0, -1.0};

        std::println("Magnitude of v1 - v2 = {}", cns::magnitude(v1 - v2));

        const auto a = cns::Vector3D{1.0, 2.0, 3.0};
        const auto b = cns::Vector3D{-3.0, 7.0, -1.0};
        const auto c = cns::Vector3D{5.0, -17.0, -10.0};

        const auto a1 = cns::project(a, b) + cns::reject(a, b);
        std::println("a1 = {}", a1);
        const auto b1 = cns::project(b, c) + cns::reject(b, c);
        std::println("b1 = {}", b1);
        const auto c1 = cns::project(c, a) + cns::reject(c, a);
        std::println("c1 = {}", c1);

        const auto m = cns::Matrix3D{1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
        std::println("m = {}", m);

        const auto ma = cns::Matrix3D{1.0, 7.0, 2.0, 5.0, 2.0, 1.0, 3.0, 6.0, 9.0};
        const auto mb = cns::Matrix3D{-4.0, 2.0, 3.0, -5.0, 5.0, 2.0, 7.0, -4.0, 3.0};

        std::println("{} == {}", cns::determinant(cns::inverse(ma)), (1.0 / cns::determinant(ma)));
        std::println("{} == {}", cns::determinant(cns::inverse(mb)), (1.0 / cns::determinant(mb)));
    } catch (...) {
        return -1;
    }

    return 0;
}