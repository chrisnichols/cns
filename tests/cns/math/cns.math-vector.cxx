#include "catch2/catch_test_macros.hpp"

import cns;

SCENARIO("Vector3D supports basic operations") {

    GIVEN("A vector") {
        const auto vector3D = cns::Vector3D{3.0, 1.0, 2.0};

        THEN("The vector has been initialized") {
            CHECK(vector3D.x() == 3.0);
            CHECK(vector3D.y() == 1.0);
            CHECK(vector3D.z() == 2.0);
        }

        WHEN("The vector undergoes post-scalar multiplication") {
            const auto result = vector3D * 2.0;

            THEN("The result has been scaled") {
                CHECK(result.x() == 6.0);
                CHECK(result.y() == 2.0);
                CHECK(result.z() == 4.0);
            }
        }

        WHEN("The vector undergoes pre-scalar multiplication") {
            const auto result = 3.0 * vector3D;

            THEN("The result has been scaled") {
                CHECK(result.x() == 9.0);
                CHECK(result.y() == 3.0);
                CHECK(result.z() == 6.0);
            }
        }

        WHEN("The vector undergoes scalar division") {
            const auto result = vector3D / 2.0;

            THEN("The result has been scaled") {
                CHECK(result.x() == 1.5);
                CHECK(result.y() == 0.5);
                CHECK(result.z() == 1.0);
            }
        }

        WHEN("The vector has been negated") {
            const auto result = -vector3D;

            THEN("The result is the negation of the vector") {
                CHECK(result.x() == -vector3D.x());
                CHECK(result.y() == -vector3D.y());
                CHECK(result.z() == -vector3D.z());
            }
        }
    }
}
