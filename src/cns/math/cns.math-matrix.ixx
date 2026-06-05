module;

#include <array>

export module cns.math:matrix;

export import :vector;

namespace cns {

/// @brief 3x3 Matrix in row-major order
export class Matrix3D {
  public:
    /// @brief Constructs a Matrix3D with the specified elements
    /// @param a00 Row 0 Column 0
    /// @param a01 Row 0 Column 1
    /// @param a02 Row 0 Column 2
    /// @param a10 Row 1 Column 0
    /// @param a11 Row 1 Column 1
    /// @param a12 Row 1 Column 2
    /// @param a20 Row 2 Column 0
    /// @param a21 Row 2 Column 1
    /// @param a22 Row 2 Column 2
    Matrix3D(double a00, double a01, double a02, double a10, double a11, double a12, double a20,
             double a21, double a22) noexcept;

    /// @brief Constructs a Matrix3D with the specified column vectors
    /// @param column0 Column 0
    /// @param column1 Column 1
    /// @param column2 Column 2
    Matrix3D(const Vector3D& column0, const Vector3D& column1, const Vector3D& column2) noexcept;

    /// @brief Defaulted Three-Way Comparison operator
    /// @param m Another Matrix3D
    /// @return
    auto operator<=>(const Matrix3D& m) const = default;

    /// @brief Matrix index operator.
    /// @param row Row index
    /// @param column Column index
    /// @return The element at position (row, column)
    [[nodiscard]] auto operator[](int row, int column) const -> double;

    /// @brief Matrix index operator.
    /// @param row Row index
    /// @param column Column index
    /// @return The element at position (row, column)
    [[nodiscard]] auto operator[](int row, int column) -> double&;

  private:
    static constexpr size_t matrixSize = 3;
    std::array<std::array<double, matrixSize>, matrixSize> m_data;
};

/// @brief Scalar multiplication for a Matrix3D
/// @param m The Matrix3D
/// @param s The scalar multiplier
/// @return
export [[nodiscard]] auto operator*(const Matrix3D& m, double s) -> Matrix3D;

/// @brief Scalar multiplication for a Matrix3D
/// @param s The scalar multiplier
/// @param m The Matrix3D
/// @return
export [[nodiscard]] auto operator*(double s, const Matrix3D& m) -> Matrix3D;

/// @brief Scalar division for a Matrix3D
/// @param m The Matrix3D
/// @param s The scalar divisor
/// @return
export [[nodiscard]] auto operator/(const Matrix3D& m, double s) -> Matrix3D;

/// @brief Matrix addition
/// @param leftM The left Matrix3D
/// @param rightM The right Matrix3D
/// @return
export [[nodiscard]] auto operator+(const Matrix3D& leftM, const Matrix3D& rightM) -> Matrix3D;

/// @brief Matrix subtraction
/// @param leftM The left Matrix3D
/// @param rightM The right Matrix3D
/// @return
export [[nodiscard]] auto operator-(const Matrix3D& leftM, const Matrix3D& rightM) -> Matrix3D;

/// @brief Negates a Matrix3D
/// @param m The Matrix3D
/// @return
export [[nodiscard]] auto operator-(const Matrix3D& m) -> Matrix3D;

/// @brief Multiplication between two 3x3 matrices
/// @param leftM The left Matrix3D
/// @param rightM The right Matrix3D
/// @return
export auto operator*(const Matrix3D& leftM, const Matrix3D& rightM) -> Matrix3D;

/// @brief Multiplication between 3x3 Matrix and 3x1 Vector
/// @param m The Matrix3D
/// @param v The column Vector3D
/// @return
export auto operator*(const Matrix3D& m, const Vector3D& v) -> Vector3D;

/// @brief Tranposes the Matrix3D
/// @param m The Matrix3D
/// @return
export auto transpose(const Matrix3D& m) -> Matrix3D;

/// @brief Calculates the determinant of the Matrix3D
/// @param m The Matrix3D
/// @return
export auto determinant(const Matrix3D& m) -> double;

} // namespace cns