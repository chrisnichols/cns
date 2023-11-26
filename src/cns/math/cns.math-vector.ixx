module;

#include <array>

export module cns.math:vector;

namespace cns {

/// @brief Three Dimesional Vector
export class Vector3D {
  public:
    /// @brief Constructs a vector with the specified components
    /// @param x
    /// @param y
    /// @param z
    Vector3D(double x, double y, double z);

    /// @brief Returns the x-compopnent of the vector
    /// @return x-component
    [[nodiscard]] auto x() const -> double;

    /// @brief Returns the y-compopnent of the vector
    /// @return y-component
    [[nodiscard]] auto y() const -> double;

    /// @brief Returns the z-compopnent of the vector
    /// @return z-component
    [[nodiscard]] auto z() const -> double;

  private:
    std::array<double, 3> m_coords;
};

/// @brief Scalar multiplication for a Vector3D
/// @param v The Vector3D
/// @param s The scalar multiplier
/// @return
export auto operator*(const Vector3D& v, double s) -> Vector3D;

/// @brief Scalar multiplication for a Vector3D
/// @param s The scalar multiplier
/// @param v The Vector3D
/// @return
export auto operator*(double s, const Vector3D& v) -> Vector3D;

/// @brief Scalar division for a Vector3D
/// @param v The Vector3D
/// @param s The scalar divisor
/// @return
export auto operator/(const Vector3D& v, double s) -> Vector3D;

/// @brief Negates a Vector3D
/// @param v The Vector3D
/// @return
export auto operator-(const Vector3D& v) -> Vector3D;

/// @brief Calculates the magnitude of the input vector
/// @param v The Vector3D
/// @return
export auto magnitude(const Vector3D& v) -> double;
} // namespace cns
