#include "catch2/catch_test_macros.hpp"

#include <cmath>

import cns;

SCENARIO("Matrix3D supports basic operations") {

    GIVEN("A matrix") {
        const auto m =
            cns::Matrix3D{{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};

        THEN("The matrix has been initialized") {
            CHECK(m[0][0] == 1.0);
            CHECK(m[0][1] == 2.0);
            CHECK(m[0][2] == 3.0);

            CHECK(m[1][0] == 4.0);
            CHECK(m[1][1] == 5.0);
            CHECK(m[1][2] == 6.0);

            CHECK(m[2][0] == 7.0);
            CHECK(m[2][1] == 8.0);
            CHECK(m[2][2] == 9.0);
        }

        THEN("The matrix can be indexed normally or in column-major order") {
            CHECK(m[0][0] == m(0, 0));
            CHECK(m[0][1] == m(1, 0));
            CHECK(m[0][2] == m(2, 0));

            CHECK(m[1][0] == m(0, 1));
            CHECK(m[1][1] == m(1, 1));
            CHECK(m[1][2] == m(2, 1));

            CHECK(m[2][0] == m(0, 2));
            CHECK(m[2][1] == m(1, 2));
            CHECK(m[2][2] == m(2, 2));
        }
    }
}
