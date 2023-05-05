#include "Fraction.hpp"
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <climits>

using namespace ariel;
using namespace std;

// this func can throw an exception
Fraction::Fraction(int numa, int numb)
    : numerator_(numa), denominator_(numb)
{
    if (numb == 0)
    {
        throw invalid_argument("denominator can't be 0"); // throw an exception
    }
    this->reduce_fraction();
}

Fraction::Fraction(float flo)
{
    // reduce to only 3 after point
    int int_val = flo * 1000;
    float float_val = (float)int_val / 1000;
    *this = Fraction(float_val * 1000, 1000);
}

Fraction::Fraction(double dou)
{
    *this = Fraction(float(dou));
}

Fraction &Fraction::reduce_fraction()
{
    // gcd- greatest common divisor
    int gcd_frac = __gcd(this->numerator_, this->denominator_);
    this->numerator_ /= gcd_frac;
    this->denominator_ /= gcd_frac;
    //denominator_ will be positive
    if (this->denominator_ < 0)
    {
        this->numerator_ *= -1;
        this->denominator_ *= -1;
    }
    return *this;
}

// get
int Fraction::getNumerator() const
{
    return this->numerator_;
}
int Fraction::getDenominator() const
{
    return this->denominator_;
}

// set
void Fraction::setNumerator(int num)
{
    this->numerator_ = num;
}
void Fraction::setDenominator(int num)
{
    this->denominator_ = num;
}

// operators
// this func can throw an exception
Fraction Fraction::operator+(const Fraction &frac) const
{
    // a1/a2 + b1/b2 == (a1*b2)+(b1*a2)/(a2*b2)
    long int a1 = this->numerator_;
    long int b2 = frac.getDenominator();
    long int a =  a1* b2;
    long int a2 = frac.getNumerator();
    long int b1 = this->denominator_;
    long int b =  a2* b1;
    if (((a + b) < INT_MIN) || ((a + b) > INT_MAX))
    {
        throw overflow_error("out the range of int"); // throw an exception
    }
    Fraction new_frac(a + b, this->denominator_ * frac.getDenominator());
    return new_frac;
}

Fraction Fraction::operator+(float flo) const
{
    Fraction new_frac(flo);
    return this->operator+(new_frac);
}

// this func can throw an exception
Fraction Fraction::operator-(const Fraction &frac) const
{
    // a1/a2 - b1/b2 == (a1*b2)-(b1*a2)/(a2*b2)
    long int a1 = this->numerator_;
    long int b2 = frac.getDenominator();
    long int a =  a1* b2;
    long int a2 = frac.getNumerator();
    long int b1 = this->denominator_;
    long int b =  a2* b1;
    if (((a - b) < INT_MIN) || ((a - b) > INT_MAX))
    {
        throw overflow_error("out the range of int"); // throw an exception
    }
    Fraction new_frac(a - b, this->denominator_ * frac.getDenominator());
    return new_frac;
}

Fraction Fraction::operator-(float flo) const
{
    Fraction new_frac(flo);
    return this->operator-(new_frac);
}

// this func can throw an exception
Fraction Fraction::operator*(const Fraction &frac) const
{
    // a1/a2 * b1/b2 = (a1*b1)/(a2*b2)
    long int a = this->numerator_;
    long int b =frac.getNumerator();
    if ((a*b) > INT_MAX || ((a*b) < INT_MIN))
    {
        throw overflow_error("out the range of int"); // throw an exception
    }
    a = this->denominator_;
    b =frac.getDenominator();
    if ((a*b) > INT_MAX || ((a*b) < INT_MIN))
    {
        throw overflow_error("out the range of int"); // throw an exception
    }
    return Fraction((this->numerator_ * frac.getNumerator()), (this->denominator_ * frac.getDenominator()));
}

Fraction Fraction::operator*(float flo) const
{
    Fraction new_frac(flo);
    return this->operator*(new_frac);
}

// this func can throw an exception
Fraction Fraction::operator/(const Fraction &frac) const
{
    // a1/a2 / b1/b2 == a1/a2 * b2/b1
    // oposite frac
    if (frac.getNumerator() == 0)
    {
        throw runtime_error("can't devide by 0"); // throw an exception
    }
    Fraction new_frac(frac.getDenominator(), frac.getNumerator());
    return this->operator*(new_frac);
}

// this func can throw an exception
Fraction Fraction::operator/(float flo) const
{
    if (flo == 0.0)
    {
        throw runtime_error("denominator can't be 0"); // throw an exception
    }
    Fraction flo_frac(flo);
    Fraction new_frac(flo_frac.getDenominator(), flo_frac.getNumerator());
    return this->operator*(new_frac);
}

bool Fraction::operator==(const Fraction &frac) const
{
    int ispos1 = 0;
    int ispos2 = 0;
    // is the fractions positive
    if ((this->numerator_ >= 0 && this->denominator_ >= 0) || (this->numerator_ <= 0 && this->denominator_ <= 0))
    {
        ispos1 = 1;
    }
    if ((frac.getNumerator() >= 0 && frac.getDenominator() >= 0) || (frac.getNumerator() <= 0 && frac.getDenominator() <= 0))
    {
        ispos2 = 1;
    }
    // 0/a == 0/b : true
    if (this->numerator_ == 0 & frac.getNumerator() == 0)
    {
        return true;
    }
    // only one of the fractions is negative
    if (ispos1 != ispos2)
    {
        return false;
    }
    // both fractions are negative
    if (ispos1 == 0)
    {
        //"-" in not in the same level
        if ((this->numerator_ <= 0 && frac.getNumerator() >= 0) || (this->numerator_ >= 0 && frac.getNumerator() <= 0))
        {
            if ((this->numerator_ * (-1)) != frac.getNumerator())
            {
                return false;
            }
            if ((this->denominator_ * (-1)) != frac.getDenominator())
            {
                return false;
            }
            return true;
        }
    }
    // both fractions are positive or "-" in the same level
    if (this->numerator_ != frac.getNumerator())
    {
        return false;
    }
    if (this->denominator_ != frac.getDenominator())
    {
        return false;
    }
    return true;
}

bool Fraction::operator==(float flo) const
{
    Fraction new_frac(flo);
    return this->operator==(new_frac);
}

bool Fraction::operator>(const Fraction &frac) const
{
    // a/b > c/d == a*d > b*c
    if ((this->numerator_ * frac.getDenominator()) > (this->denominator_ * frac.getNumerator()))
    {
        return true;
    }
    return false;
}

bool Fraction::operator>(float flo) const
{
    Fraction new_frac(flo);
    return this->operator>(new_frac);
}

bool Fraction::operator<(const Fraction &frac) const
{
    // a/b < c/d == a*d < b*c
    if ((this->numerator_ * frac.getDenominator()) < (this->denominator_ * frac.getNumerator()))
    {
        return true;
    }
    return false;
}

bool Fraction::operator<(float flo) const
{
    Fraction new_frac(flo);
    return this->operator<(new_frac);
}

bool Fraction::operator>=(const Fraction &frac) const
{
    return (this->operator>(frac) || this->operator==(frac));
}

bool Fraction::operator>=(float flo) const
{
    Fraction new_frac(flo);
    return this->operator>=(new_frac);
}

bool Fraction::operator<=(const Fraction &frac) const
{
    return (this->operator<(frac) || this->operator==(frac));
}

bool Fraction::operator<=(float flo) const
{
    Fraction new_frac(flo);
    return this->operator<=(new_frac);
}

//++a
Fraction &Fraction::operator++()
{
    this->numerator_ += this->denominator_;
    return *this;
}

// a++
Fraction Fraction::operator++(int) // postfix
{
    Fraction new_frac = *this;
    this->operator++();
    return new_frac;
}

//--a
Fraction &Fraction::operator--()
{
    this->numerator_ -= this->denominator_;
    return *this;
}

// a--
Fraction Fraction::operator--(int) // postfix
{
    Fraction new_frac = *this;
    this->operator--();
    return new_frac;
}

// friends
ostream &ariel::operator<<(ostream &stream, Fraction const &frac)
{
    if(frac.getDenominator() < 0)
    {
        return stream << (-1) * frac.getNumerator() << "/" << (-1) * frac.getDenominator();
    }
    else
    {
        return stream << frac.getNumerator() << "/" << frac.getDenominator();
    }

}
// this func can throw an exception
istream &ariel::operator>>(istream &stream, Fraction &frac)
{
    char c;
    int numerator = 0;
    int denominator = 0;
    stream >> numerator >> denominator;
    if (denominator == 0)
    {
        throw runtime_error("not 2 numbers"); // throw an exception
    }
    frac.setNumerator(numerator);
    frac.setDenominator(denominator);
    return stream;
}
// float options
Fraction ariel::operator+(float flo, const Fraction &frac)
{
    Fraction new_frac(flo);
    return new_frac.operator+(frac);
}

Fraction ariel::operator-(float flo, const Fraction &frac)
{
    Fraction new_frac(flo);
    return new_frac.operator-(frac);
}

Fraction ariel::operator/(float flo, const Fraction &frac)
{
    Fraction new_frac(flo);
    return new_frac.operator/(frac);
}

Fraction ariel::operator*(float flo, const Fraction &frac)
{
    Fraction new_frac(flo);
    return new_frac.operator*(frac);
}

bool ariel::operator==(float flo, const Fraction &frac)
{
    Fraction new_frac(flo);
    return new_frac.operator==(frac);
}

bool ariel::operator>(float flo, const Fraction &frac)
{
    Fraction new_frac(flo);
    return new_frac.operator>(frac);
}

bool ariel::operator<(float flo, const Fraction &frac)
{
    Fraction new_frac(flo);
    return new_frac.operator<(frac);
}

bool ariel::operator>=(float flo, const Fraction &frac)
{
    Fraction new_frac(flo);
    return new_frac.operator>=(frac);
}

bool ariel::operator<=(float flo, const Fraction &frac)
{
    Fraction new_frac(flo);
    return new_frac.operator<=(frac);
}
