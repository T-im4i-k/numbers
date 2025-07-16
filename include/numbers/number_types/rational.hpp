#pragma once

#include "numbers/number_types/num_aliases.hpp"

#include <compare>
#include <stdexcept>

namespace Numbers
{

    class Rational
    {
    public:
        Rational(const IntT numerator, const IntT denominator = 1);

        friend Rational operator+(const Rational lhs, const Rational rhs);

        friend Rational operator*(const Rational lhs, const Rational rhs);

        [[nodiscard]] Rational operator-() const;

        [[nodiscard]] Rational operator~() const;

        friend Rational operator-(const Rational lhs, const Rational rhs);

        friend Rational operator/(const Rational lhs, const Rational rhs);

        friend bool operator==(const Rational lhs, const Rational rhs);

        friend std::strong_ordering operator<=>(const Rational lhs, const Rational rhs);

    private:
        void normalize();

        IntT numerator_;
        IntT denominator_;
    };
    
} // namespace Numbers
