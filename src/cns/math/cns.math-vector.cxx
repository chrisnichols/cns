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

auto operator*(const Vector3D& v, const double s) -> Vector3D {
    return {v.x() * s, v.y() * s, v.z() * s};
}

auto operator*(const double s, const Vector3D& v) -> Vector3D {
    return v * s;
}

auto operator/(const Vector3D& v, const double s) -> Vector3D {
    return v * (1.0 / s);
}

auto operator-(const Vector3D& v) -> Vector3D {
    return {-v.x(), -v.y(), -v.z()};
}

auto magnitude(const Vector3D& v) -> double {
    return std::sqrt(v.x() * v.x() + v.y() * v.y() + v.z() * v.z());
}

auto normalize(const Vector3D& v) -> Vector3D {
    return v / magnitude(v);
}
} // namespace cns