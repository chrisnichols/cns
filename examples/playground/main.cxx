#include <iostream>

import cns;

auto main() -> int {
    const auto v1 = cns::Vector3D{1.0, 2.0, 3.0};
    const auto v2 = cns::Vector3D{-3.0, 2.0, -1.0};

    std::cout << cns::magnitude(v1 - v2) << "\n";

    return 0;
}