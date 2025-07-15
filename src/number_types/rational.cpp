#include <numbers/number_types/rational.hpp>
#include <numbers/number_theory/basic.hpp>

namespace Numbers
{
    Rational::Rational(IntT numenator, IntT denominator) : numerator_(numenator), denominator_(denominator)
    {
        if (denominator_ == 0)
        {
            throw std::invalid_argument(
                "Rational::Rational: Denominator Cannot Be Equal to 0.");
        }
        normalize();
    }

    Rational operator+(Rational lhs, Rational rhs)
    {
        IntT numenator = lhs.numerator_ * rhs.denominator_ + rhs.numerator_ * lhs.denominator_;
        IntT denominator = lhs.denominator_ * rhs.denominator_;

        return Rational(numenator, denominator);
    }

    Rational operator*(Rational lhs, Rational rhs)
    {
        IntT numenator = lhs.numerator_ * rhs.numerator_;
        IntT denominator = lhs.denominator_ * rhs.denominator_;

        return Rational(numenator, denominator);
    }

    Rational Rational::operator-()
    {
        return Rational(-numerator_, denominator_);
    }

    Rational Rational::operator~()
    {
        return Rational(denominator_, numerator_);
    }

    Rational operator-(Rational lhs, Rational rhs)
    {
        return lhs + (-rhs);
    }

    Rational operator/(Rational lhs, Rational rhs)
    {
        return lhs * (~rhs);
    }

    bool operator==(Rational lhs, Rational rhs)
    {
        return lhs.numerator_ == rhs.numerator_ && lhs.denominator_ == rhs.denominator_;
    }

    std::strong_ordering operator<=>(Rational lhs, Rational rhs)
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
