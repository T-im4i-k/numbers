#include "numbers/number_types/rational.hpp"
#include "numbers/number_theory/basic.hpp"

namespace Numbers
{
    Rational::Rational(const IntT numenator, const IntT denominator) : numerator_(numenator), denominator_(denominator)
    {
        if (denominator_ == 0)
        {
            throw std::invalid_argument(
                "Rational::Rational: Denominator Cannot Be Equal to 0.");
        }
        normalize();
    }

    [[nodiscard]] Rational operator+(const Rational lhs, const Rational rhs)
    {
        IntT numenator = lhs.numerator_ * rhs.denominator_ + rhs.numerator_ * lhs.denominator_;
        IntT denominator = lhs.denominator_ * rhs.denominator_;

        return Rational(numenator, denominator);
    }

    [[nodiscard]] Rational operator*(const Rational lhs, const Rational rhs)
    {
        IntT numenator = lhs.numerator_ * rhs.numerator_;
        IntT denominator = lhs.denominator_ * rhs.denominator_;

        return Rational(numenator, denominator);
    }

    Rational Rational::operator-() const
    {
        return Rational(-numerator_, denominator_);
    }

    Rational Rational::operator~() const
    {
        return Rational(denominator_, numerator_);
    }

    [[nodiscard]] Rational operator-(const Rational lhs, const Rational rhs)
    {
        return lhs + (-rhs);
    }

    [[nodiscard]] Rational operator/(const Rational lhs, const Rational rhs)
    {
        return lhs * (~rhs);
    }

    [[nodiscard]] bool operator==(const Rational lhs, const Rational rhs)
    {
        return lhs.numerator_ == rhs.numerator_ && lhs.denominator_ == rhs.denominator_;
    }

    [[nodiscard]] std::strong_ordering operator<=>(const Rational lhs, const Rational rhs)
    {
        return lhs.numerator_ * rhs.denominator_ <=> rhs.numerator_ * lhs.denominator_;
    }

    void Rational::normalize()
    {
        if (numerator_ == 0)
        {
            denominator_ = 1;
            return;
        }

        if (denominator_ < 0)
        {
            denominator_ = -denominator_;
            numerator_ = -numerator_;
        }

        IntT gcd_val = gcd(numerator_, denominator_);
        numerator_ /= gcd_val;
        denominator_ /= gcd_val;
    }
} // namespace Numbers
