    #include "rational.h"
    /**
     * @brief default constructor
     * 
     */
    Rational::Rational()
    {
        numerator = 1;
        denominator = 1;
    }
    /**
     * @brief Construct a new Rational:: Rational object
     * 
     * @param n = numerator
     * @param d = denominator
     */
    Rational::Rational(int n, int d)
    {
        numerator = n;
        denominator = d;
        reduce();
    }
    /**
     * @brief Construct a new Rational:: Rational object
     * 
     * @param s = char array parsed to gather numerator and denominator ("4/5")
     */
    Rational::Rational(const char s[])
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
      /**
     * @brief Construct a new Rational:: Rational object
     * 
     * @param s = string object parsed to gather numerator and denominator ("4/5")
     */
    Rational::Rational(std::string s)
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
    /**
     * @brief Construct a new Rational:: Rational object
     * 
     * @param r rational object for copy constructor
     */
    Rational::Rational(Rational &r)
    {
        denominator = r.denominator;
        numerator = r.numerator;
    }
    /**
     * @brief assignment operator
     * 
     * @param r rational object that is coppied into *this
     * @return Rational, returns *this
     */
    Rational Rational::operator=(Rational &r)
    {
        denominator = r.denominator;
        numerator = r.numerator;
        return *this;
    }
    /**
     * @brief parses string and sets object to new value
     * 
     * @param s = string to parse
     * @return Rational, returns itself
     */
    Rational Rational::operator=(std::string s)
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
    /**
     * @brief finds greatest common divisor and simplifies fraction
     * 
     */
    void Rational::reduce()
    {
        int divisor = std::gcd(numerator, denominator);
        numerator /= divisor;
        denominator /= divisor;
    }
    /**
     * @brief converts rational type to double
     * 
     * @return double = representation of the number
     */
    Rational::operator double() const
    {
        return double(numerator) / denominator;
    }
    /**
     * @brief defines addition between two rationals
     * 
     * @param r rational number being added
     * @return Rational sum
     */
    Rational Rational::operator+(Rational &r)
    {
        Rational sum;
        sum.denominator = denominator * r.denominator;
        sum.numerator = (numerator * r.denominator) + (r.numerator * denominator);
        sum.reduce();
        return sum;
    }
    /**
     * @brief defines subtraction between two rationals
     * 
     * @param r rational number being subtracted
     * @return Rational difference
     */
    Rational Rational::operator-(Rational &r)
    {
        Rational sum;
        sum.denominator = denominator * r.denominator;
        sum.numerator = (numerator * r.denominator) - (r.numerator * denominator);
        sum.reduce();
        return sum;

    }
    /**
     * @brief defines multiplication between two rationals
     * 
     * @param r rational number being multiplied
     * @return Rational product
     */
    Rational Rational::operator*(Rational &r)
    {
        Rational sum;
        sum.denominator = denominator * r.denominator;
        sum.numerator = numerator * r.numerator;
        sum.reduce();
        return sum;
    }
    /**
     * @brief defines division between two rationals
     * 
     * @param r rational number being divided
     * @return Rational dividend
     */
    Rational Rational::operator/(Rational &r)
    {
        Rational sum;
        sum.denominator = denominator * r.numerator;
        sum.numerator = numerator * r.denominator;
        sum.reduce();
        return sum;

    }
    /**
     * @brief allows use of stream insertion with Rationals
     * 
     * @param out ostream object
     * @param r Rational object
     * @return std::ostream& returns ostream object after inserting Rational data 
     */
    std::ostream & operator<<(std::ostream &out, const Rational &r)
    {
        out << r.numerator<<"/"<<r.denominator;
        return out;
    }