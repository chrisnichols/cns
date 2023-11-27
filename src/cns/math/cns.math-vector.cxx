module;

#include <cmath>
#include <stdexcept>

module cns.math;

namespace cns {

Vector3D::Vector3D(const double x, const double y, const double z) noexcept
    : m_x{x},
      m_y{y},
      m_z{z} {
}

auto Vector3D::x() const noexcept -> double {
    return this->m_x;
}

auto Vector3D::y() const noexcept -> double {
    return this->m_y;
}

auto Vector3D::z() const noexcept -> double {
    return this->m_z;
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

auto operator+(const Vector3D& leftV, const Vector3D& rightV) -> Vector3D {
    return {leftV.x() + rightV.x(), leftV.y() + rightV.y(),
            leftV.z() + rightV.z()};
}

auto operator-(const Vector3D& leftV, const Vector3D& rightV) -> Vector3D {
    return leftV + (-rightV);
}

auto operator-(const Vector3D& v) noexcept -> Vector3D {
    return {-v.x(), -v.y(), -v.z()};
}

auto magnitude(const Vector3D& v) noexcept -> double {
    return std::sqrt(v.x() * v.x() + v.y() * v.y() + v.z() * v.z());
}

auto normalize(const Vector3D& v) -> Vector3D {
    return v / magnitude(v);
}
} // namespace cns