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

/// @brief Scalar multiplication for a Matrix3D
/// @param m The Matrix3D
/// @param s The scalar multiplier
/// @return
export [[nodiscard]] auto operator*(const Matrix3D& m, double s) noexcept
    -> Matrix3D;

/// @brief Scalar multiplication for a Matrix3D
/// @param s The scalar multiplier
/// @param m The Matrix3D
/// @return
export [[nodiscard]] auto operator*(double s, const Matrix3D& m) noexcept
    -> Matrix3D;

/// @brief Scalar division for a Matrix3D
/// @param m The Matrix3D
/// @param s The scalar divisor
/// @return
export [[nodiscard]] auto operator/(const Matrix3D& m, double s) -> Matrix3D;

/// @brief Matrix addition
/// @param leftM The left Matrix3D
/// @param rightM The right Matrix3D
/// @return
export [[nodiscard]] auto operator+(const Matrix3D& leftM,
                                    const Matrix3D& rightM) -> Matrix3D;

/// @brief Matrix subtraction
/// @param leftM The left Matrix3D
/// @param rightM The right Matrix3D
/// @return
export [[nodiscard]] auto operator-(const Matrix3D& leftM,
                                    const Matrix3D& rightM) -> Matrix3D;

/// @brief Negates a Matrix3D
/// @param v The Matrix3D
/// @return
export [[nodiscard]] auto operator-(const Matrix3D& m) noexcept -> Matrix3D;

/// @brief Multiplication between two 3x3 matrices
/// @param leftM The left Matrix3D
/// @param rightM The right Matrix3D
/// @return
export auto operator*(const Matrix3D& leftM, const Matrix3D& rightM)
    -> Matrix3D;

/// @brief Multiplication between 3x3 Matrix and 3x1 Vector
/// @param m The Matrix3D
/// @param v The column Vector3D
/// @return
export auto operator*(const Matrix3D& m, const Vector3D& v) -> Vector3D;

/// @brief Tranposes the Matrix3D
/// @param m The Matrix3D
/// @return
export auto transpose(const Matrix3D& m) -> Matrix3D;

} // namespace cns