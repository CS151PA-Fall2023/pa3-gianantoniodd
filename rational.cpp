    #include "rational.h"
    Rational::Rational()
    {
        numerator = 1;
        denominator = 1;
    }
    Rational::Rational(int n, int d)
    {
        numerator = n;
        denominator = d;
        reduce();
    }
    Rational::Rational(char s[])
    {
        int i = 0;
        int sign = 1;
        numerator = 0;
        denominator = 0;
        while (s[i] != '/')
        {
            if (s[i] == '-'){
                sign *= -1;
            }else{
                numerator = numerator *10;
                numerator += (s[i] - 48);
            }
            i++;
            
        }
        i++;
        while (s[i] != '\0')
        {
            if (s[i] == '-'){
                sign *= -1;
            }else{
                denominator = denominator *10;
                denominator += (s[i] - 48);
            }
            i++;
        }
        numerator *= sign;
    }
    Rational::Rational(std::string s)
    {
        std::string newstr = s;
        Rational(newstr.c_str());
    }
    Rational::Rational(Rational &r)
    {
        denominator = r.denominator;
        numerator = r.numerator;
    }
    Rational Rational::operator=(Rational &r)
    {
        denominator = r.denominator;
        numerator = r.numerator;
        return *this;
    }
    Rational Rational::operator=(char s[])
    {
        int i = 0;
        int sign = 1;
        numerator = 0;
        denominator = 0;
        while (s[i] != '/')
        {
            if (s[i] == '-'){
                sign *= -1;
            }else{
                numerator = numerator *10;
                numerator += (s[i] - 48);
            }
            i++;
        }
        i++;
        while (s[i] != '\0')
        {
            if (s[i] == '-'){
                sign *= -1;
            }else{
                denominator = denominator *10;
                denominator += (s[i] - 48);
            }
            i++;
        }
        numerator *= sign;
        return *this;

    }
    Rational Rational::operator=(std::string s)
    {
        std::string newstr = s;
        return operator=(newstr.c_str());
        
    }
    void Rational::reduce()
    {

    }
    Rational::operator double() const
    {
        return double(numerator) / denominator;
    }
    Rational Rational::operator+(Rational &r)
    {
        Rational sum;
        sum.denominator = denominator * r.denominator;
        sum.numerator = (numerator * r.denominator) + (r.numerator * denominator);
        sum.reduce();
        return sum;
    }
    Rational Rational::operator-(Rational &r)
    {
        Rational sum;
        sum.denominator = denominator * r.denominator;
        sum.numerator = (numerator * r.denominator) - (r.numerator * denominator);
        sum.reduce();
        return sum;

    }
    Rational Rational::operator*(Rational &r)
    {
        Rational sum;
        sum.denominator = denominator * r.denominator;
        sum.numerator = numerator * r.numerator;
        sum.reduce();
        return sum;
    }
    Rational Rational::operator/(Rational &r)
    {
        Rational sum;
        sum.denominator = denominator * r.numerator;
        sum.numerator = numerator * r.denominator;
        sum.reduce();
        return sum;

    }
    std::ostream & operator<<(std::ostream &out, const Rational &r)
    {
        out << r.numerator<<"/"<<r.denominator;
        return out;
    }