module;

#include <cmath>

module cns.math;

namespace cns {

Vector3D::Vector3D(const double x, const double y, const double z)
    : m_coords{x, y, z} {
}

auto Vector3D::x() const -> double {
    return this->m_coords[0];
}

auto Vector3D::y() const -> double {
    return this->m_coords[1];
}

auto Vector3D::z() const -> double {
    return this->m_coords[2];
}

auto operator*(const Vector3D& vector3D, const double val) -> Vector3D {
    return {vector3D.x() * val, vector3D.y() * val, vector3D.z() * val};
}

auto operator*(const double val, const Vector3D& vector3D) -> Vector3D {
    return vector3D * val;
}

auto operator/(const Vector3D& vector3D, const double val) -> Vector3D {
    return vector3D * (1.0 / val);
}

auto operator-(const Vector3D& vector3D) -> Vector3D {
    return {-vector3D.x(), -vector3D.y(), -vector3D.z()};
}

auto magnitude(const Vector3D& vector3D) -> double {
    return std::sqrt(vector3D.x() * vector3D.x() + vector3D.y() * vector3D.y() +
                     vector3D.z() * vector3D.z());
}

} // namespace cns