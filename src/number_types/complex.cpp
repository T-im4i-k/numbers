#include "numbers/number_types/complex.hpp"

#include <cmath>
#include <stdexcept>

namespace Numbers
{
    Complex::Complex(const Real re, const Real im) : re_(re), im_(im)
    {
    }

    [[nodiscard]] Complex operator+(const Complex lhs, const Complex rhs)
    {
        return Complex(lhs.re() + rhs.re(),
                       lhs.im() + rhs.im());
    }
    [[nodiscard]] Complex operator*(const Complex lhs, const Complex rhs)
    {
        return Complex(lhs.re() * rhs.re() - lhs.im() * rhs.im(),
                       lhs.re() * rhs.im() + lhs.im() * rhs.re());
    }

    Complex Complex::operator-() const
    {
        return Complex(-re(), -im());
    }

    Complex Complex::operator~() const
    {
        if (*this == 0)
        {
            throw std::invalid_argument(
                "Complex::operator~: Complex(0) Has No Inverse");
        }

        const Real abs_sqr = abs() * abs();
        return Complex(re() / abs_sqr, -im() / abs_sqr);
    }

    [[nodiscard]] Complex operator-(const Complex lhs, const Complex rhs)
    {
        return lhs + (-rhs);
    }

    [[nodiscard]] Complex operator/(const Complex lhs, const Complex rhs)
    {
        return lhs * (~rhs);
    }

    [[nodiscard]] bool operator==(const Complex lhs, const Complex rhs)
    {
        return lhs.re() == rhs.re() && lhs.im() == rhs.im();
    }

    Real Complex::abs() const
    {
        return std::hypot(re(), im());
    }

    Real Complex::re() const
    {
        return re_;
    }

    Real Complex::im() const
    {
        return im_;
    }
} // namespace Numbers
