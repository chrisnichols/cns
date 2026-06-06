module;

#include <cmath>
#include <stdexcept>

module cns.math;

namespace cns {

Vector3D::Vector3D(const double x, const double y, const double z) noexcept
    : m_components{x, y, z} {
}

auto Vector3D::operator[](int i) const -> double {
    return this->m_components.at(i);
}

auto Vector3D::operator[](int i) -> double& {
    return this->m_components.at(i);
}

auto Vector3D::x() const noexcept -> double {
    return this->m_components[0];
}

auto Vector3D::y() const noexcept -> double {
    return this->m_components[1];
}

auto Vector3D::z() const noexcept -> double {
    return this->m_components[2];
}

auto operator*(const Vector3D& v, const double s) noexcept -> Vector3D {
    return {v.x() * s, v.y() * s, v.z() * s};
}

auto operator*(const double s, const Vector3D& v) noexcept -> Vector3D {
    return v * s;
}

auto operator/(const Vector3D& v, const double s) -> Vector3D {
    if (s == 0.0) {
        throw std::domain_error("Divide by 0");
    }

    return v * (1.0 / s);
}

auto operator+(const Vector3D& a, const Vector3D& b) -> Vector3D {
    return {a.x() + b.x(), a.y() + b.y(), a.z() + b.z()};
}

auto operator-(const Vector3D& a, const Vector3D& b) -> Vector3D {
    return a + (-b);
}

auto operator-(const Vector3D& v) noexcept -> Vector3D {
    return {-v.x(), -v.y(), -v.z()};
}

auto magnitude(const Vector3D& v) noexcept -> double {
    return std::sqrt((v.x() * v.x()) + (v.y() * v.y()) + (v.z() * v.z()));
}

auto normalize(const Vector3D& v) -> Vector3D {
    return v / magnitude(v);
}

auto dot(const Vector3D& a, const Vector3D& b) noexcept -> double {
    return (a.x() * b.x()) + (a.y() * b.y()) + (a.z() * b.z());
}

auto cross(const Vector3D& a, const Vector3D& b) noexcept -> Vector3D {
    return {(a.y() * b.z()) - (a.z() * b.y()), (a.z() * b.x()) - (a.x() * b.z()),
            (a.x() * b.y()) - (a.y() * b.x())};
}

auto project(const Vector3D& a, const Vector3D& b) noexcept -> Vector3D {
    return b * (dot(a, b) / dot(b, b));
}

auto reject(const Vector3D& a, const Vector3D& b) noexcept -> Vector3D {
    return a - project(a, b);
}
} // namespace cns