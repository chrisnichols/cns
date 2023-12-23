#include "catch2/catch_test_macros.hpp"

#include <cmath>

import cns;

SCENARIO("Matrix3D supports basic operations") {

    GIVEN("A matrix") {
        const auto m = cns::Matrix3D{{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};

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

        THEN("The matrix can be indexed in row- or column-major order") {
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

        THEN("The matrix can be transposed") {
            const auto t = cns::transpose(m);

            CHECK(m(0, 0) == t(0, 0));
            CHECK(m(0, 1) == t(1, 0));
            CHECK(m(0, 2) == t(2, 0));

            CHECK(m(1, 0) == t(0, 1));
            CHECK(m(1, 1) == t(1, 1));
            CHECK(m(1, 2) == t(2, 1));

            CHECK(m(2, 0) == t(0, 2));
            CHECK(m(2, 1) == t(1, 2));
            CHECK(m(2, 2) == t(2, 2));
        }
    }
}

SCENARIO("Matrix3D supports multiplication with a column Vector3D") {

    GIVEN("A matrix composed of column vectors") {
        const auto a = cns::Vector3D{1.0, 2.0, 3.0};
        const auto b = cns::Vector3D{4.0, 5.0, 6.0};
        const auto c = cns::Vector3D{7.0, 8.0, 9.0};

        const auto m = cns::Matrix3D{a, b, c};

        THEN("The matrix multiplied by the unit axis aligned vectors produces "
             "the columns of the matrix") {
            CHECK(a == m * cns::Vector3D{1, 0, 0});
            CHECK(b == m * cns::Vector3D{0, 1, 0});
            CHECK(c == m * cns::Vector3D{0, 0, 1});
        }
    }
}

SCENARIO("Matrix3D supports multiplication with a Matrix3D") {

    GIVEN("Two matrices composed of column vectors") {
        const auto a = cns::Vector3D{1.0, 2.0, 3.0};
        const auto b = cns::Vector3D{4.0, 5.0, 6.0};
        const auto c = cns::Vector3D{7.0, 8.0, 9.0};

        const auto m1 = cns::Matrix3D{a, b, c};
        const auto m2 = cns::Matrix3D{b, c, a};

        THEN("The product of the matrices is another matrix") {
            const auto result = m1 * m2;

            CHECK(66.0 == result(0, 0));
            CHECK(81.0 == result(1, 0));
            CHECK(96.0 == result(2, 0));

            CHECK(102.0 == result(0, 1));
            CHECK(126.0 == result(1, 1));
            CHECK(150.0 == result(2, 1));

            CHECK(30.0 == result(0, 2));
            CHECK(36.0 == result(1, 2));
            CHECK(42.0 == result(2, 2));
        }
    }
}

SCENARIO("Matrix3D follows the basic properties") {
    GIVEN("Three matrices and two scalars") {
        const auto v1 = cns::Vector3D{1.0, 2.0, 3.0};
        const auto v2 = cns::Vector3D{-3.0, 7.0, -1.0};
        const auto v3 = cns::Vector3D{5.0, -17.0, -10.0};

        const auto a = cns::Matrix3D{v1, v2, v3};
        const auto b = cns::Matrix3D{v2, v3, v1};
        const auto c = cns::Matrix3D{v3, v1, v2};

        const auto s = 3.0;
        const auto t = -2.0;

        THEN("Associative law for matrix addition") {
            CHECK((a + b) + c == a + (b + c));
        }

        THEN("Commutative law for matrix addition") {
            CHECK(a + b == b + a);
        }

        THEN("Associative law for scalar-matrix multiplication") {
            CHECK((s * t) * a == s * (t * a));
        }

        THEN("Commutative law for scalar-matrix multiplication") {
            CHECK(t * a == a * t);
        }

        THEN("Distributive laws for scalar-matrix multiplication") {
            CHECK(s * (a + b) == s * a + s * b);
            CHECK((s + t) * a == s * a + t * a);
        }

        THEN("Associative law for matrix multiplication") {
            CHECK((a * b) * c == a * (b * c));
        }

        THEN("Distributive laws for matrix multiplication") {
            CHECK(a * (b + c) == a * b + a * c);
            CHECK((a + b) * c == a * c + b * c);
        }

        THEN("Scalar factorization for matrices") {
            CHECK((t * a) * b == a * (t * b));
            CHECK((t * a) * b == t * (a * b));
        }

        THEN("Product rule for matrix transpose") {
            CHECK(cns::transpose(a * b) == cns::transpose(b) * cns::transpose(a));
        }
    }
}