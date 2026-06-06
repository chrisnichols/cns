module;

#include <array>

export module cns.math:vector;

namespace cns {

/// @brief 3-Dimesional Vector
export class Vector3D {
  public:
    /// @brief Constructs a Vector3D with the specified components
    /// @param x
    /// @param y
    /// @param z
    Vector3D(double x, double y, double z) noexcept;

    /// @brief Equality comparasion using a tolerable comparison
    /// @param v Another Vector3D
    /// @return
    auto operator==(const Vector3D& v) const -> bool;

    /// @brief Defaulted Three-Way Comparison operator
    /// @param v Another Vector3D
    /// @return
    auto operator<=>(const Vector3D& v) const = default;

    /// @brief Index operator
    /// @param i Index
    /// @return
    [[nodiscard]] auto operator[](int i) const -> double;

    /// @brief Index operator
    /// @param i Index
    /// @return
    [[nodiscard]] auto operator[](int i) -> double&;

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
    std::array<double, 3> m_components;
};

/// @brief Scalar multiplication for a Vector3D
/// @param v The Vector3D
/// @param s The scalar multiplier
/// @return
export [[nodiscard]] auto operator*(const Vector3D& v, double s) noexcept -> Vector3D;

/// @brief Scalar multiplication for a Vector3D
/// @param s The scalar multiplier
/// @param v The Vector3D
/// @return
export [[nodiscard]] auto operator*(double s, const Vector3D& v) noexcept -> Vector3D;

/// @brief Scalar division for a Vector3D
/// @param v The Vector3D
/// @param s The scalar divisor
/// @return
export [[nodiscard]] auto operator/(const Vector3D& v, double s) -> Vector3D;

/// @brief Vector addition
/// @param a The left Vector3D
/// @param b The right Vector3D
/// @return
export [[nodiscard]] auto operator+(const Vector3D& a, const Vector3D& b) -> Vector3D;

/// @brief Vector subtraction
/// @param a The left Vector3D
/// @param b The right Vector3D
/// @return
export [[nodiscard]] auto operator-(const Vector3D& a, const Vector3D& b) -> Vector3D;

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

/// @brief Calculates the dot product (scalar product) between two vectors
/// @param a The left Vector3D
/// @param b The right Vector3D
/// @return
export [[nodiscard]] auto dot(const Vector3D& a, const Vector3D& b) noexcept -> double;

/// @brief Calculates the cross product (vector product) between two vectors
/// @param a The left Vector3D
/// @param b The right Vector3D
/// @return
export [[nodiscard]] auto cross(const Vector3D& a, const Vector3D& b) noexcept -> Vector3D;

/// @brief Calculates the projection of a onto b
/// @param a The Vector3D being projected onto b
/// @param b The Vector3D onto which a is being projected
/// @return
export [[nodiscard]] auto project(const Vector3D& a, const Vector3D& b) noexcept -> Vector3D;

/// @brief Calculates the rejection of a from b
/// @param a The Vector3D to be rejected from b
/// @param b The Vector3D from which a is being rejected
/// @return
export [[nodiscard]] auto reject(const Vector3D& a, const Vector3D& b) noexcept -> Vector3D;
} // namespace cns