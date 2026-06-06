module;

export module cns.numeric:compare;

namespace cns {

/// @brief Compares two double values to determine tolerable equality
/// @param left The first double to compare
/// @param right The second double to compare
/// @return
export auto areEqual(double left, double right) noexcept -> bool;
} // namespace cns