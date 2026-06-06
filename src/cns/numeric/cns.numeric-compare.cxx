module;

#include <algorithm>
#include <cmath>
#include <limits>

module cns.numeric;

namespace cns {

auto areEqual(double left, double right) noexcept -> bool {
    // TODO: Review the following for additional ideas on comparing doubles:
    // https://randomascii.wordpress.com/2012/02/25/comparing-floating-point-numbers-2012-edition/
    //
    // Calculate the difference between the inputs
    //
    const auto difference = std::abs(left - right);

    // Find the input with the largest magnitude and use it to scale the comparison
    //
    left = std::abs(left);
    right = std::abs(right);

    const auto largest = std::max(left, right);
    const auto tolerance = 10.0 * (largest * std::numeric_limits<double>::epsilon());

    return difference <= tolerance;
}

} // namespace cns