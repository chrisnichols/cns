module;

#include <cmath>
#include <stdexcept>

module cns.math;

namespace cns {

Matrix3D::Matrix3D(double a00, double a01, double a02, double a10, double a11, double a12,
                   double a20, double a21, double a22) noexcept
    : m_entries{a00, a01, a02, a10, a11, a12, a20, a21, a22} {
}

Matrix3D::Matrix3D(const Vector3D& column0, const Vector3D& column1,
                   const Vector3D& column2) noexcept
    : Matrix3D(column0[0], column1[0], column2[0], column0[1], column1[1], column2[1], column0[2],
               column1[2], column2[2]) {
}

auto Matrix3D::operator[](int row, int column) const -> double {
    return this->m_entries[row * 3 + column];
}

auto Matrix3D::operator[](int row, int column) -> double& {
    return this->m_entries[row * 3 + column];
}

auto operator*(const Matrix3D& m, const double s) noexcept -> Matrix3D {
    return {m[0, 0] * s, m[0, 1] * s, m[0, 2] * s, m[1, 0] * s, m[1, 1] * s,
            m[1, 2] * s, m[2, 0] * s, m[2, 1] * s, m[2, 2] * s};
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
    return {leftM[0, 0] + rightM[0, 0], leftM[0, 1] + rightM[0, 1], leftM[0, 2] + rightM[0, 2],
            leftM[1, 0] + rightM[1, 0], leftM[1, 1] + rightM[1, 1], leftM[1, 2] + rightM[1, 2],
            leftM[2, 0] + rightM[2, 0], leftM[2, 1] + rightM[2, 1], leftM[2, 2] + rightM[2, 2]};
}

auto operator-(const Matrix3D& leftM, const Matrix3D& rightM) -> Matrix3D {
    return leftM + (-rightM);
}

auto operator-(const Matrix3D& m) noexcept -> Matrix3D {
    return m * -1.0;
}

auto operator*(const Matrix3D& leftM, const Matrix3D& rightM) -> Matrix3D {
    return Matrix3D{
        leftM[0, 0] * rightM[0, 0] + leftM[0, 1] * rightM[1, 0] + leftM[0, 2] * rightM[2, 0],
        leftM[0, 0] * rightM[0, 1] + leftM[0, 1] * rightM[1, 1] + leftM[0, 2] * rightM[2, 1],
        leftM[0, 0] * rightM[0, 2] + leftM[0, 1] * rightM[1, 2] + leftM[0, 2] * rightM[2, 2],
        leftM[1, 0] * rightM[0, 0] + leftM[1, 1] * rightM[1, 0] + leftM[1, 2] * rightM[2, 0],
        leftM[1, 0] * rightM[0, 1] + leftM[1, 1] * rightM[1, 1] + leftM[1, 2] * rightM[2, 1],
        leftM[1, 0] * rightM[0, 2] + leftM[1, 1] * rightM[1, 2] + leftM[1, 2] * rightM[2, 2],
        leftM[2, 0] * rightM[0, 0] + leftM[2, 1] * rightM[1, 0] + leftM[2, 2] * rightM[2, 0],
        leftM[2, 0] * rightM[0, 1] + leftM[2, 1] * rightM[1, 1] + leftM[2, 2] * rightM[2, 1],
        leftM[2, 0] * rightM[0, 2] + leftM[2, 1] * rightM[1, 2] + leftM[2, 2] * rightM[2, 2]};
}

auto operator*(const Matrix3D& m, const Vector3D& v) -> Vector3D {
    return {m[0, 0] * v.x() + m[0, 1] * v.y() + m[0, 2] * v.z(),
            m[1, 0] * v.x() + m[1, 1] * v.y() + m[1, 2] * v.z(),
            m[2, 0] * v.x() + m[2, 1] * v.y() + m[2, 2] * v.z()};
}

auto transpose(const Matrix3D& m) -> Matrix3D {
    return {m[0, 0], m[1, 0], m[2, 0], m[0, 1], m[1, 1], m[2, 1], m[0, 2], m[1, 2], m[2, 2]};
}

} // namespace cns