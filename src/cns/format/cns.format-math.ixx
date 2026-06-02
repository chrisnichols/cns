module;

#include <format>

export module cns.format:math;

import cns.math;

using namespace cns;

/// @brief std::format support for Vector3D
template <>
struct std::formatter<Vector3D> : std::formatter<string> {
    auto format(const Vector3D& v, std::format_context& ctx) const {
        return formatter<string>::format(std::format("[{}, {}, {}]", v.x(), v.y(), v.z()), ctx);
    }
};

/// @brief std::format support for Matrix3D
template <>
struct std::formatter<Matrix3D> : std::formatter<string> {
    auto format(const Matrix3D& m, std::format_context& ctx) const {
        return formatter<string>::format(
            std::format("\n   [{}, {}, {}]\n.  [{}, {}, {}]\n   [{}, {}, {}]", m[0, 0], m[0, 1],
                        m[0, 2], m[1, 0], m[1, 1], m[1, 2], m[2, 0], m[2, 1], m[2, 2]),
            ctx);
    }
};