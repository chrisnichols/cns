module;

#include <compare>

export module cns.math:vector;

namespace cns {

/// @brief Three Dimesional Vector
export class Vector3D {
  public:
    /// @brief Constructs a vector with the specified components
    /// @param x
    /// @param y
    /// @param z
    Vector3D(double x, double y, double z) noexcept;

    /// @brief Defaulted Three-Way Comparison operator
    /// @param v Another Vector3D
    /// @return
    auto operator<=>(const Vector3D& v) const = default;

    /// @brief Returns the x-compopnent of the vector
    /// @return x-component
    [[nodiscard]] auto x() const noexcept -> double;

    /// @brief Returns the y-compopnent of the vector
    /// @return y-component
    [[nodiscard]] auto y() const noexcept -> double;

    /// @brief Returns the z-compopnent of the vector
    /// @return z-component
    [[nodiscard]] auto z() const noexcept -> double;

  private:
    double m_x;
    double m_y;
    double m_z;
};

/// @brief Scalar multiplication for a Vector3D
/// @param v The Vector3D
/// @param s The scalar multiplier
/// @return
export [[nodiscard]] auto operator*(const Vector3D& v, double s) noexcept
    -> Vector3D;

/// @brief Scalar multiplication for a Vector3D
/// @param s The scalar multiplier
/// @param v The Vector3D
/// @return
export [[nodiscard]] auto operator*(double s, const Vector3D& v) noexcept
    -> Vector3D;

/// @brief Scalar division for a Vector3D
/// @param v The Vector3D
/// @param s The scalar divisor
/// @return
export [[nodiscard]] auto operator/(const Vector3D& v, double s) -> Vector3D;

/// @brief Vector addition
/// @param leftV The left Vector3D
/// @param rightV The right Vector3D
/// @return
export [[nodiscard]] auto operator+(const Vector3D& leftV,
                                    const Vector3D& rightV) -> Vector3D;

/// @brief Vector subtraction
/// @param leftV The left Vector3D
/// @param rightV The right Vector3D
/// @return
export [[nodiscard]] auto operator-(const Vector3D& leftV,
                                    const Vector3D& rightV) -> Vector3D;

/// @brief Negates a Vector3D
/// @param v The Vector3D
/// @return
export [[nodiscard]] auto operator-(const Vector3D& v) noexcept -> Vector3D;

/// @brief Calculates the magnitude of the input vector
/// @param v The Vector3D
/// @return
export [[nodiscard]] auto magnitude(const Vector3D& v) noexcept -> double;

/// @brief Creates the unit vector with the same direction as the input vector
/// @param v The Vector3D
/// @return
export [[nodiscard]] auto normalize(const Vector3D& v) -> Vector3D;
} // namespace cns