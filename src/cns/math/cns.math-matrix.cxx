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

auto operator*(const Matrix3D& m, const Vector3D& v) -> Vector3D {
    return m[0] * v.x() + m[1] * v.y() + m[2] * v.z();
}

} // namespace cns