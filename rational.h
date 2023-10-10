#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include <string>
#include <numeric>

class Rational
{
public:
    Rational();
    Rational(int n, int d);
    Rational(std::string s);
    Rational(const char s[]);
    Rational(Rational &r);
    Rational operator=(Rational &r);
    Rational operator=(std::string s);
    
    void reduce();
    Rational operator+(Rational &r);
    Rational operator-(Rational &r);
    Rational operator*(Rational &r);
    Rational operator/(Rational &r);
    operator double() const;
    friend std::ostream & operator<<(std::ostream &out, const Rational &c);
private:
    int numerator;
    int denominator;
};
#endif