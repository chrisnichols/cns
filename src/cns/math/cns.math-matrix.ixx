module;

#include <array>
#include <compare>

export module cns.math:matrix;

export import :vector;

namespace cns {

/// @brief 3x3 Matrix in column-major order
export class Matrix3D {
  public:
    /// @brief Constructs a Matrix3D with the specified column vectors
    /// @param column0
    /// @param column1
    /// @param column2
    Matrix3D(const Vector3D& column0, const Vector3D& column1,
             const Vector3D& column2) noexcept;

    /// @brief Defaulted Three-Way Comparison operator
    /// @param m Another Matrix3D
    /// @return
    auto operator<=>(const Matrix3D& m) const = default;

    /// @brief Matrix index operator. Access the elements in the normal m(i, j)
    /// form.
    /// @param row Row index
    /// @param column Column index
    /// @return
    [[nodiscard]] auto operator()(int row, int column) const -> double;

    /// @brief Column index operator.
    /// @param column Column index
    /// @return The column Vector3D
    [[nodiscard]] auto operator[](int column) const -> const Vector3D&;

  private:
    std::array<Vector3D, 3> m_entries;
};

/// @brief Multiplication between 3x3 Matrix and 3x1 Vector
/// @param m The Matrix3D
/// @param v The column Vector3D
/// @return
export auto operator*(const Matrix3D& m, const Vector3D& v) -> Vector3D;

} // namespace cns