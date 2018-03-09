#include <iostream>
#include "Rational.h"

using namespace std;

#define NORMAL
#ifdef NORMAL

int main()
{
    Rational r = Rational::make(1, 1);
    cin >> r;
    cout << r << endl;
    return 0;
}

#else

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("Rational make method with invalid denominator", "Should throw exception") {
    CHECK_THROWS(Rational::make(1, 0));
}

TEST_CASE("Operator ==", "Should return true") {
    Rational r = Rational::make(1, 2);
    Rational r2 = Rational::make(1, 2);

    CHECK(r == r2);
}

TEST_CASE("Operator *", "Should return 1/4") {
    Rational r = Rational::make(1, 2);
    Rational r2 = Rational::make(1, 2);
    Rational r3 = Rational::make(1, 4);
    CHECK((r * r2) == r3);
}

#endif
