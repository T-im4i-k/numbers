#pragma once

#include "numbers/number_types/num_aliases.hpp"

#include <compare>
#include <stdexcept>

namespace Numbers
{

    class Rational
    {
    public:
        Rational(IntT numerator, IntT denominator = 1);

        friend Rational operator+(Rational lhs, Rational rhs);

        friend Rational operator*(Rational lhs, Rational rhs);

        Rational operator-();

        Rational operator~();

        friend Rational operator-(Rational lhs, Rational rhs);

        friend Rational operator/(Rational lhs, Rational rhs);

        friend bool operator==(Rational lhs, Rational rhs);

        friend std::strong_ordering operator<=>(Rational lhs, Rational rhs);

    private:
        void normalize();

        IntT numerator_;
        IntT denominator_;
    };
    
} // namespace Numbers
