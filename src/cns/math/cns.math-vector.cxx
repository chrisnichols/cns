module;

#include <cmath>
#include <stdexcept>

module cns.math;

namespace cns {

Vector3D::Vector3D(const double x, const double y, const double z) noexcept
    : m_components{x, y, z} {
}

auto Vector3D::operator[](int i) const -> double {
    return this->m_components[i];
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

auto operator+(const Vector3D& leftV, const Vector3D& rightV) -> Vector3D {
    return {leftV.x() + rightV.x(), leftV.y() + rightV.y(), leftV.z() + rightV.z()};
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

auto dot(const Vector3D& leftV, const Vector3D& rightV) noexcept -> double {
    return leftV.x() * rightV.x() + leftV.y() * rightV.y() + leftV.z() * rightV.z();
}
} // namespace cns