module;

#include <stdexcept>

module cns.math;

namespace cns {

Matrix3D::Matrix3D(double a00, double a01, double a02, double a10, double a11, double a12,
                   double a20, double a21, double a22) noexcept
    : Matrix3D({a00, a10, a20}, {a01, a11, a21}, {a02, a12, a22}) {
}

Matrix3D::Matrix3D(const Vector3D& column0, const Vector3D& column1,
                   const Vector3D& column2) noexcept
    : m_columns{column0, column1, column2} {
}

auto Matrix3D::operator[](int row, int column) const -> double {
    return this->m_columns.at(column)[row];
}

auto Matrix3D::operator[](int row, int column) -> double& {
    return this->m_columns.at(column)[row];
}

auto Matrix3D::operator[](int column) const -> const Vector3D& {
    return this->m_columns.at(column);
}

auto Matrix3D::operator[](int column) -> Vector3D& {
    return this->m_columns.at(column);
}

auto operator*(const Matrix3D& m, const double s) -> Matrix3D {
    return {m[0, 0] * s, m[0, 1] * s, m[0, 2] * s, m[1, 0] * s, m[1, 1] * s,
            m[1, 2] * s, m[2, 0] * s, m[2, 1] * s, m[2, 2] * s};
}

auto operator*(const double s, const Matrix3D& m) -> Matrix3D {
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

auto operator-(const Matrix3D& m) -> Matrix3D {
    return m * -1.0;
}

auto operator*(const Matrix3D& leftM, const Matrix3D& rightM) -> Matrix3D {
    return Matrix3D{
        (leftM[0, 0] * rightM[0, 0]) + (leftM[0, 1] * rightM[1, 0]) + (leftM[0, 2] * rightM[2, 0]),
        (leftM[0, 0] * rightM[0, 1]) + (leftM[0, 1] * rightM[1, 1]) + (leftM[0, 2] * rightM[2, 1]),
        (leftM[0, 0] * rightM[0, 2]) + (leftM[0, 1] * rightM[1, 2]) + (leftM[0, 2] * rightM[2, 2]),
        (leftM[1, 0] * rightM[0, 0]) + (leftM[1, 1] * rightM[1, 0]) + (leftM[1, 2] * rightM[2, 0]),
        (leftM[1, 0] * rightM[0, 1]) + (leftM[1, 1] * rightM[1, 1]) + (leftM[1, 2] * rightM[2, 1]),
        (leftM[1, 0] * rightM[0, 2]) + (leftM[1, 1] * rightM[1, 2]) + (leftM[1, 2] * rightM[2, 2]),
        (leftM[2, 0] * rightM[0, 0]) + (leftM[2, 1] * rightM[1, 0]) + (leftM[2, 2] * rightM[2, 0]),
        (leftM[2, 0] * rightM[0, 1]) + (leftM[2, 1] * rightM[1, 1]) + (leftM[2, 2] * rightM[2, 1]),
        (leftM[2, 0] * rightM[0, 2]) + (leftM[2, 1] * rightM[1, 2]) + (leftM[2, 2] * rightM[2, 2])};
}

auto operator*(const Matrix3D& m, const Vector3D& v) -> Vector3D {
    return {(m[0, 0] * v.x()) + (m[0, 1] * v.y()) + (m[0, 2] * v.z()),
            (m[1, 0] * v.x()) + (m[1, 1] * v.y()) + (m[1, 2] * v.z()),
            (m[2, 0] * v.x()) + (m[2, 1] * v.y()) + (m[2, 2] * v.z())};
}

auto transpose(const Matrix3D& m) -> Matrix3D {
    return {m[0, 0], m[1, 0], m[2, 0], m[0, 1], m[1, 1], m[2, 1], m[0, 2], m[1, 2], m[2, 2]};
}

auto determinant(const Matrix3D& m) -> double {
    return (m[0, 0] * ((m[1, 1] * m[2, 2]) - (m[1, 2] * m[2, 1]))) +
           (m[0, 1] * ((m[1, 2] * m[2, 0]) - (m[1, 0] * m[2, 2]))) +
           (m[0, 2] * ((m[1, 0] * m[2, 1]) - (m[1, 1] * m[2, 0])));
}

auto inverse(const Matrix3D& m) -> Matrix3D {
    const Vector3D& a = m[0];
    const Vector3D& b = m[1];
    const Vector3D& c = m[2];

    Vector3D r0 = cross(b, c);
    Vector3D r1 = cross(c, a);
    Vector3D r2 = cross(a, b);

    const double oneOverDeterminant = 1.0 / dot(r2, c);

    return oneOverDeterminant *
           Matrix3D(r0.x(), r0.y(), r0.z(), r1.x(), r1.y(), r1.z(), r2.x(), r2.y(), r2.z());
}

} // namespace cns