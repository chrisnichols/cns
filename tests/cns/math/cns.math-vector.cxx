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

            CHECK(v.x() == v[0]);
            CHECK(v.y() == v[1]);
            CHECK(v.z() == v[2]);
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

        WHEN("The vector is divided by 0") {
            THEN("An exception is thrown") {
                CHECK_THROWS(v / 0.0);
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

        WHEN("The vector has been normalized") {
            const auto result = cns::normalize(v);

            THEN("The magnitude of the result is 1.0") {
                CHECK(cns::magnitude(result) == 1.0);
            }
        }

        GIVEN("A second vector") {
            const auto v2 = cns::Vector3D{5.0, 2.0, 4.0};

            WHEN("The two vectors are added") {
                const auto result = v + v2;

                THEN("The result has been calculated correctly") {
                    CHECK(result.x() == 8.0);
                    CHECK(result.y() == 3.0);
                    CHECK(result.z() == 6.0);
                }

                WHEN("The two vectors are added in the other order") {
                    const auto result2 = v2 + v;

                    THEN("The results are the same") {
                        CHECK(result == result2);
                    }
                }
            }

            WHEN("The two vectors are subtracted") {
                const auto result = v - v2;

                THEN("The result has been calculated correctly") {
                    CHECK(result.x() == -2.0);
                    CHECK(result.y() == -1.0);
                    CHECK(result.z() == -2.0);
                }

                WHEN("The two vectors are subtracted in the other order") {
                    const auto result2 = v2 - v;

                    THEN("The results are not the same") {
                        CHECK(result != result2);
                    }
                }
            }
        }
    }

    GIVEN("The 0 vector") {
        const auto v = cns::Vector3D{0.0, 0.0, 0.0};

        WHEN("The vector is normalized") {
            THEN("An exception is thrown") {
                CHECK_THROWS(cns::normalize(v));
            }
        }
    }
}
