#pragma once

#include <iostream>
using namespace std;

namespace ariel
{
    class Fraction
    {
    public:
        Fraction(int numa=1, int numb=1);
        Fraction(double dou);
        Fraction(float flo);
        Fraction &reduce_fraction();
        int getNumerator() const;
        int getDenominator() const;
        void setNumerator(int num);
        void setDenominator(int num);
        //operators
        Fraction operator+(const Fraction& frac) const;
        Fraction operator+(float flo) const;
        Fraction operator-(const Fraction& frac)const;
        Fraction operator-(float flo)const;
        Fraction operator*(const Fraction& frac)const;
        Fraction operator*(float flo)const;
        Fraction operator/(const Fraction& frac)const;
        Fraction operator/(float flo)const;
        bool operator==(const Fraction& frac) const;
        bool operator==(float flo) const;
        bool operator>(const Fraction& frac) const;
        bool operator>(float flo) const;
        bool operator<(const Fraction& frac) const;
        bool operator<(float flo) const;
        bool operator>=(const Fraction& frac) const;
        bool operator>=(float flo) const;
        bool operator<=(const Fraction& frac) const;
        bool operator<=(float flo) const;
        Fraction& operator++();
        Fraction operator++(int); //postfix
        Fraction& operator--();
        Fraction operator--(int); //postfix

        //friends
        friend ostream& operator<<(ostream& stream, const Fraction& frac);
        friend istream& operator>>(istream& stream, Fraction& frac);
        //float options
        friend Fraction operator+(float flo, const Fraction& frac);
        friend Fraction operator-(float flo, const Fraction& frac);
        friend Fraction operator/(float flo, const Fraction& frac);
        friend Fraction operator*(float flo, const Fraction& frac);
        friend bool operator==(float flo, const Fraction& frac);
        friend bool operator>(float flo, const Fraction& frac);
        friend bool operator<(float flo, const Fraction& frac);
        friend bool operator>=(float flo, const Fraction& frac);
        friend bool operator<=(float flo, const Fraction& frac);

    private:
        int numerator_;
        int denominator_;
    };
}