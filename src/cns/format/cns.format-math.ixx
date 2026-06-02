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