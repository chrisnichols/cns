module;

#include <cmath>
#include <stdexcept>

module cns.math;

namespace cns {

Matrix3D::Matrix3D(const Vector3D& column0, const Vector3D& column1,
                   const Vector3D& column2) noexcept
    : m_entries{column0, column1, column2} {
}

auto Matrix3D::operator()(int row, int column) const -> double {
    return this->m_entries[column][row];
}

auto Matrix3D::operator[](int column) const -> const Vector3D& {
    return this->m_entries[column];
}

auto operator*(const Matrix3D& m, const double s) noexcept -> Matrix3D {
    return {m[0] * s, m[1] * s, m[2] * s};
}

auto operator*(const double s, const Matrix3D& m) noexcept -> Matrix3D {
    return m * s;
}

auto operator/(const Matrix3D& m, const double s) -> Matrix3D {
    if (s == 0.0) {
        throw std::domain_error("Divide by 0");
    }

    return m * (1.0 / s);
}

auto operator+(const Matrix3D& leftM, const Matrix3D& rightM) -> Matrix3D {
    return {leftM[0] + rightM[0], leftM[1] + rightM[1], leftM[2] + rightM[2]};
}

auto operator-(const Matrix3D& leftM, const Matrix3D& rightM) -> Matrix3D {
    return leftM + (-rightM);
}

auto operator-(const Matrix3D& m) noexcept -> Matrix3D {
    return {-m[0], -m[1], -m[2]};
}

auto operator*(const Matrix3D& leftM, const Matrix3D& rightM) -> Matrix3D {
    return {// First column
            {leftM(0, 0) * rightM(0, 0) + leftM(0, 1) * rightM(1, 0) + leftM(0, 2) * rightM(2, 0),
             leftM(1, 0) * rightM(0, 0) + leftM(1, 1) * rightM(1, 0) + leftM(1, 2) * rightM(2, 0),
             leftM(2, 0) * rightM(0, 0) + leftM(2, 1) * rightM(1, 0) + leftM(2, 2) * rightM(2, 0)},
            // Second column
            {leftM(0, 0) * rightM(0, 1) + leftM(0, 1) * rightM(1, 1) + leftM(0, 2) * rightM(2, 1),
             leftM(1, 0) * rightM(0, 1) + leftM(1, 1) * rightM(1, 1) + leftM(1, 2) * rightM(2, 1),
             leftM(2, 0) * rightM(0, 1) + leftM(2, 1) * rightM(1, 1) + leftM(2, 2) * rightM(2, 1)},
            // Third column
            {leftM(0, 0) * rightM(0, 2) + leftM(0, 1) * rightM(1, 2) + leftM(0, 2) * rightM(2, 2),
             leftM(1, 0) * rightM(0, 2) + leftM(1, 1) * rightM(1, 2) + leftM(1, 2) * rightM(2, 2),
             leftM(2, 0) * rightM(0, 2) + leftM(2, 1) * rightM(1, 2) + leftM(2, 2) * rightM(2, 2)}};
}

auto operator*(const Matrix3D& m, const Vector3D& v) -> Vector3D {
    return m[0] * v.x() + m[1] * v.y() + m[2] * v.z();
}

auto transpose(const Matrix3D& m) -> Matrix3D {
    return {{m(0, 0), m(0, 1), m(0, 2)}, {m(1, 0), m(1, 1), m(1, 2)}, {m(2, 0), m(2, 1), m(2, 2)}};
}

} // namespace cns