#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include <string>

class Rational
{
public:
    Rational();
    Rational(int n, int d);
    Rational(std::string s);
    Rational(char s[]);
    Rational(Rational &r);
    Rational operator=(Rational &r);
    Rational operator=(std::string s);
    Rational operator=(char s[]);
    void reduce();
    operator double() const;
    Rational operator+(Rational &r);
    Rational operator-(Rational &r);
    Rational operator*(Rational &r);
    Rational operator/(Rational &r);
    friend std::ostream & operator << (std::ostream &out, const Rational &c);

private:
    int numerator;
    int denominator;






};








#endif