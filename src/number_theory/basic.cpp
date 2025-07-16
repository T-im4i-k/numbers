#include "numbers/number_theory/basic.hpp"

#include <cmath>

namespace Numbers
{

    IntT gcd(IntT lhs, IntT rhs)
    {
        lhs = std::abs(lhs);
        rhs = std::abs(rhs);
        while (rhs != 0)
        {
            IntT tmp = lhs % rhs;
            lhs = rhs;
            rhs = tmp;
        }

        return lhs;
    }

    IntT lcm(const IntT lhs, const IntT rhs)
    {
        if (lhs == 0 || rhs == 0)
        {
            return 0;
        }

        return lhs * rhs / gcd(lhs, rhs);
    }

} // namespace Numbers