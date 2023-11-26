#include "catch2/catch_test_macros.hpp"

#include <cmath>

import cns;

SCENARIO("Vector3D supports basic operations") {

    GIVEN("A vector") {
        const auto v = cns::Vector3D{3.0, 1.0, 2.0};

        THEN("The vector has been initialized") {
            CHECK(v.x() == 3.0);
            CHECK(v.y() == 1.0);
            CHECK(v.z() == 2.0);
        }

        WHEN("The vector undergoes post-scalar multiplication") {
            const auto result = v * 2.0;

            THEN("The result has been scaled") {
                CHECK(result.x() == 6.0);
                CHECK(result.y() == 2.0);
                CHECK(result.z() == 4.0);
            }
        }

        WHEN("The vector undergoes pre-scalar multiplication") {
            const auto result = 3.0 * v;

            THEN("The result has been scaled") {
                CHECK(result.x() == 9.0);
                CHECK(result.y() == 3.0);
                CHECK(result.z() == 6.0);
            }
        }

        WHEN("The vector undergoes scalar division") {
            const auto result = v / 2.0;

            THEN("The result has been scaled") {
                CHECK(result.x() == 1.5);
                CHECK(result.y() == 0.5);
                CHECK(result.z() == 1.0);
            }
        }

        WHEN("The vector has been negated") {
            const auto result = -v;

            THEN("The result is the negation of the vector") {
                CHECK(result.x() == -v.x());
                CHECK(result.y() == -v.y());
                CHECK(result.z() == -v.z());
            }
        }

        WHEN("The magnitude of the vector has been calculated") {
            const auto result = cns::magnitude(v);

            THEN("The result has been calculated correctly") {
                CHECK(result == std::sqrt(14.0));
            }
        }
    }
}
