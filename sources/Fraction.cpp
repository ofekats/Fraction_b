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

Fraction::Fraction(double dou)
{
    float_to_frac(float(dou));
}

Fraction::Fraction(float flo)
{
    float_to_frac(flo);
}

Fraction &Fraction::reduce_fraction()
{
    // gcd
    int gcd_frac = __gcd(this->numerator_, denominator_);
    this->numerator_ /= gcd_frac;
    this->denominator_ /= gcd_frac;
    return *this;
}

// LCM = (a * b) / GCD(a, b)
int Fraction::lcm_demon(const Fraction &frac) const
{
    return (this->denominator_ * frac.getDenominator()) / __gcd(this->denominator_, frac.getDenominator());
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

// static func
float Fraction::float_only_3_after_point(float flo)
{
    int int_val = flo * 1000;
    float float_val = (float) int_val / 1000;
    return float_val;
}
Fraction Fraction::float_to_frac(float flo){
    //reduce
    float_only_3_after_point(flo);
    //how many numbers after the point
    int decimalPlaces = -1 * (int)floor(log10(fabs(flo)));
    int demon;
    switch (decimalPlaces)
    {
    case 0:
        demon = 1;
        break;
    case 1:
        demon = 10;
        break;
    case 2:
        demon = 100;
        break;
    case 3:
        demon = 1000;
        break;    
    default:
        break;
    }
    return Fraction(flo*demon, demon);
}

// operators
Fraction Fraction::operator+(const Fraction &frac) const
{
    int lcm = this->lcm_demon(frac);
    int a = this->numerator_ * frac.getDenominator();
    int b = frac.getNumerator() * this->denominator_;
    if (a + b > INT_MAX)
    {
        throw invalid_argument("too big for int"); // throw an exception
    }
    Fraction new_frac(a + b, lcm);
    return new_frac.reduce_fraction();
}

Fraction Fraction::operator+(float flo) const
{
    Fraction new_frac = float_to_frac(flo);
    return this->operator+(new_frac);
}

Fraction Fraction::operator-(const Fraction &frac)const
{
    int lcm = this->lcm_demon(frac);
    int a = this->numerator_ * frac.getDenominator();
    int b = frac.getNumerator() * this->denominator_;
    if (a - b < INT_MIN)
    {
        throw invalid_argument("too little for int"); // throw an exception
    }
    Fraction new_frac(a - b, lcm);
    return new_frac.reduce_fraction();
}

Fraction Fraction::operator-(float flo) const
{
    Fraction new_frac = float_to_frac(flo);
    return this->operator-(new_frac);
}


Fraction Fraction::operator*(const Fraction &frac)const
{
    if ((this->numerator_ * frac.getNumerator()) > INT_MAX)
    {
        throw invalid_argument("too big for int"); // throw an exception
    }
    if((this->numerator_ * frac.getNumerator()) < INT_MIN)
    {
        throw invalid_argument("too little for int"); // throw an exception
    }
    if((this->denominator_ * frac.getDenominator()) > INT_MAX)
    {
        throw invalid_argument("too big for int"); // throw an exception
    }
    if((this->denominator_ * frac.getDenominator()) < INT_MIN)
    {
        throw invalid_argument("too little for int"); // throw an exception
    }
    return Fraction((this->numerator_ * frac.getNumerator()), (this->denominator_ * frac.getDenominator()));
}

Fraction Fraction::operator*(float flo)const
{
    Fraction new_frac = float_to_frac(flo);
    return this->operator*(new_frac);
}

Fraction Fraction::operator/(const Fraction &frac)const
{
    //oposite
    Fraction new_frac(frac.getDenominator(), frac.getNumerator());
    return this->operator*(new_frac);
}

Fraction Fraction::operator/(float flo)const
{
    Fraction flo_frac = float_to_frac(flo);
    Fraction new_frac(flo_frac.getDenominator(), flo_frac.getNumerator());
    return this->operator*(new_frac);
}

bool Fraction::operator==(const Fraction &frac) const
{
    if(this->numerator_ != frac.getNumerator())
    {
        return false;
    }
    if(this->denominator_ != frac.getDenominator())
    {
        return false;
    }
    return true;
}

bool Fraction::operator==(float flo) const
{
    Fraction new_frac = float_to_frac(flo);
    return this->operator==(new_frac);
}

// a/b > c/d if and only if a*d > b*c
bool Fraction::operator>(const Fraction &frac) const
{
    if((this->numerator_ * frac.getDenominator()) > (this->denominator_ * frac.getNumerator()))
    {
        return true;
    }
    return false;
}

bool Fraction::operator>(float flo) const
{
    Fraction new_frac = float_to_frac(flo);
    return this->operator>(new_frac);
}

// a/b < c/d if and only if a*d < b*c
bool Fraction::operator<(const Fraction &frac) const
{
    if((this->numerator_ * frac.getDenominator()) < (this->denominator_ * frac.getNumerator()))
    {
        return true;
    }
    return false;
}

bool Fraction::operator<(float flo) const
{
    Fraction new_frac = float_to_frac(flo);
    return this->operator<(new_frac);
}

bool Fraction::operator>=(const Fraction &frac) const
{
    return (this->operator>(frac) || this->operator==(frac));
}

bool Fraction::operator>=(float flo) const
{
    Fraction new_frac = float_to_frac(flo);
    return this->operator>=(new_frac);
}

bool Fraction::operator<=(const Fraction &frac) const
{
    return (this->operator<(frac) || this->operator==(frac));
}

bool Fraction::operator<=(float flo) const
{
    Fraction new_frac = float_to_frac(flo);
    return this->operator<=(new_frac);
}

//++a
Fraction &Fraction::operator++()
{
    this->numerator_ += this->denominator_;
    this->reduce_fraction(); //needed????????????????????????????????????????????????????
    return *this;
}

//a++
Fraction Fraction::operator++(int) // postfix
{
    Fraction new_frac = *this;
    this->operator++();
    return new_frac;
}

Fraction &Fraction::operator--()
{
    this->numerator_ -= this->denominator_;
    this->reduce_fraction(); //needed????????????????????????????????????????????????????
    return *this;
}

Fraction Fraction::operator--(int) // postfix
{
    Fraction new_frac = *this;
    this->operator--();
    return new_frac;
}

// friends
ostream &ariel::operator<<(ostream &stream, Fraction const &frac)
{
    return stream << " " << frac.getNumerator() << "/" << frac.getDenominator() << " ";
}
istream &ariel::operator>>(istream &stream, Fraction const &frac)
{
    char c;
    stream >> frac.getNumerator() >> c >> frac.getDenominator();
    return stream;
}
// float options
Fraction &ariel::operator+(float flo, Fraction &frac)
{
    return frac;
}

Fraction &ariel::operator-(float flo, Fraction &frac)
{
    return frac;
}

Fraction &ariel::operator/(float flo, Fraction &frac)
{
    return frac;
}

Fraction &ariel::operator*(float flo, Fraction &frac)
{
    return frac;
}

bool ariel::operator==(float flo, Fraction &frac)
{
    return true;
}

bool ariel::operator>(float flo, Fraction &frac)
{
    return true;
}

bool ariel::operator<(float flo, Fraction &frac)
{
    return true;
}

bool ariel::operator>=(float flo, Fraction &frac)
{
    return true;
}

bool ariel::operator<=(float flo, Fraction &frac)
{
    return true;
}
