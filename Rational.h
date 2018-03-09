#ifndef RATIONAL_H_INCLUDED
#define RATIONAL_H_INCLUDED

#include <ostream>
#include <istream>
#include <iostream>
#include <sstream>

class Rational {

    private:
        int numerator;
        int denominator;

        Rational(int numerator, int denominator): numerator(numerator), denominator(denominator) {
            //this->numerator = numerator
            //this->denominator = denominator
        }

    public:
        enum RationalException {DivisionByZeroException};

        static Rational make(int numerator = 0, int denominator = 1);

        void setNumerator(int numerator) { this->numerator = numerator; }
        void setDenominator(int denominator) { this->denominator = denominator; }
        int getNumerator() { return numerator; }
        int getDenominator() { return denominator; }
        Rational invert() { return Rational(denominator, numerator); }
        Rational& multiply(const Rational& rhs);

        bool operator==(const Rational& rhs) { return numerator == rhs.numerator && denominator == rhs.denominator; }
        Rational& operator*(const Rational& rhs) { return multiply(rhs);}
        friend std::ostream& operator<<(std::ostream& out, const Rational& rational);
        friend std::istream& operator>>(std::istream& in, Rational& rational);

};

#endif // RATIONAL_H_INCLUDED
