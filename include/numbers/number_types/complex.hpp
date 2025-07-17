#pragma once

#include "numbers/number_types/num_aliases.hpp"

namespace Numbers
{

    class Complex
    {
    public:
        Complex(const Real re, const Real im = 0);

        friend Complex operator+(const Complex lhs, const Complex rhs);

        friend Complex operator*(const Complex lhs, const Complex rhs);

        [[nodiscard]] Complex operator-() const;

        [[nodiscard]] Complex operator~() const;

        friend Complex operator-(const Complex lhs, const Complex rhs);

        friend Complex operator/(const Complex lhs, const Complex rhs);

        friend bool operator==(const Complex lhs, const Complex rhs);

        [[nodiscard]] Real abs() const;

        [[nodiscard]] Real re() const;

        [[nodiscard]] Real im() const;

    private:
        Real re_;
        Real im_;
    };
} // namespace Numbers
