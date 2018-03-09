#include "Rational.h"

Rational Rational::make(int numerator, int denominator) {

    if (denominator == 0) {
        throw DivisionByZeroException;
    }

    return Rational(numerator, denominator);
}

Rational& Rational::multiply(const Rational& rhs) {
    numerator *= rhs.numerator;
    denominator *= rhs.denominator;

    return (*this);
}

std::ostream& operator<<(std::ostream& out, const Rational& rational) {
    out << rational.numerator << "/" << rational.denominator;

    return out;
}

std::istream& operator>>(std::istream& in, Rational& rational) {
    in >> rational.numerator;

    int denominator;
    in >> denominator;

    rational.denominator = denominator == 0 ? 1 : denominator;

    return in;
}
