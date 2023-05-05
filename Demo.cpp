/**
 * Demo file for the exercise on binary tree
 *
 * @author Evgeny Hershkovitch Neiterman
 * @since 2023-03
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "sources/Fraction.hpp"

using namespace ariel;

int main()
{
    Fraction a(-5, 3), b(14, 21);
    cout << "a: " << a << "b: " << b << endl;
    cout << "a+b" << a + b << endl;
    cout << "a-b" << a - b << endl;
    cout << "a/b" << a / b << endl;
    cout << "a*b" << a * b << endl;
    cout << "2.3*b" << 2.3 * b << endl;
    cout << "a+2.421" << a + 2.421 << endl;
    Fraction c = a + b - 1;
    cout << c++ << endl;
    cout << --c << endl;

    cout << "c >=b ? : " << (c >= b) << endl;
    if (a > 1.1)
        cout << " a is bigger than 1.1" << endl;
    else
        cout << " a is smaller than 1.1" << endl;

    cout << "===========================" << endl;
    cout << "         my demo:" << endl;
    cout << "===========================" << endl;
    //3 constructors
    cout << "construcrots: \n" << endl;
    //int int
    Fraction d(-5, -3);
    cout << d << endl;
    double num1 = 0.8854;
    float num2 = 0.8857;
    //double
    Fraction e(num1);
    cout << e << endl; // will be only 3 after the point
    //float
    Fraction f(num2);
    cout << f << endl; // will be only 3 after the point
    cout << "e == f ? " << (e == f) << endl << endl; //equal

    //get
    cout << "get: " << endl;
    cout << f.getNumerator() << "/" << f.getDenominator() << endl << endl;

    //set
    cout << "set: " << endl;
    cout << "before set: " << e << endl;
    e.setNumerator(22);
    e.setDenominator(223);
    cout << "after set: " << e << endl << endl;

    //operators
    cout << "operators: \n" << endl;
    //+
    cout << "+: " << endl;
    Fraction g1 = d + f;
    cout << g1 << endl;
    cout << (0.88511111111111111111111 + d) << endl; // sould be like line before
    cout << (d + 0.88511111111111111111111) << endl << endl; // sould be like line before

    //-
    cout << "-: " << endl;
    Fraction g2 = d - f;
    cout << g2 << endl;
    cout << (0.88511111111111111111111 - d) << endl; // sould be like line before
    cout << (d - 0.88511111111111111111111) << endl << endl; // sould be like line before

    //*
    cout << "*: " << endl;
    Fraction g3 = d * f;
    cout << g3 << endl;
    cout << (0.88511111111111111111111 * d) << endl; // sould be like line before
    cout << (d * 0.88511111111111111111111) << endl << endl; // sould be like line before

    // /
    cout << "/: " << endl;
    Fraction g4 = d / f;
    cout << g4 << endl;
    cout << (0.88511111111111111111111 / d) << endl; // sould be like line before
    cout << (d / 0.88511111111111111111111) << endl << endl; // sould be like line before

    // ==
    cout << "==: " << endl;
    Fraction g5 = 2 / 0.5;
    Fraction g6(4,1);
    cout << g5 <<" == "<< g6 << " ? " << (g5 == g6) << endl;
    cout <<"4 == "<< g5 << " ? " << (4 == g5) << endl;
    cout << g5 <<" == 4 ? " << (g5 == 4) << endl << endl; // sould be like line before

    // >
    cout << ">: " << endl;
    Fraction g7(3,1);
    cout << g5 <<" > "<< g6 << " ? " << (g5 > g6) << endl;
    cout << g5 <<" > "<< g7 << " ? " << (g5 > g7) << endl;
    cout <<"3.99999 > "<< g5 << " ? " << (3.99999 > g5) << endl;
    cout << g5 <<" > 3.99999 ? " << (g5 > 3.99999) << endl << endl;

    // <
    cout << "<: " << endl;
    Fraction g8(5,1);
    cout << g5 <<" < "<< g6 << " ? " << (g5 < g6) << endl;
    cout << g5 <<" < "<< g8 << " ? " << (g5 < g8) << endl;
    cout <<"4.01 < "<< g5 << " ? " << (4.01 < g5) << endl;
    cout << g5 <<" < 4.01 ? " << (g5 < 4.01) << endl << endl;

    // >=
    cout << ">=: " << endl;
    Fraction g9(3,1);
    cout << g5 <<" >= "<< g6 << " ? " << (g5 >= g6) << endl;
    cout << g5 <<" >= "<< g7 << " ? " << (g5 >= g9) << endl;
    cout << g5 <<" >= 7.9 ? " << (g5 >= 7.9) << endl;
    cout <<"3.99999 >= "<< g5 << " ? " << (3.99999 >= g5) << endl;
    cout << g5 <<" >= 3.99999 ? " << (g5 >= 3.99999) << endl << endl;

    // <=
    cout << "<=: " << endl;
    Fraction g10(5,1);
    cout << g5 <<" <= "<< g6 << " ? " << (g5 <= g6) << endl;
    cout << g5 <<" <= "<< g8 << " ? " << (g5 <= g10) << endl;
    cout << g5 <<" <= 2.01 ? " << (g5 <= 2.01) << endl;
    cout <<"4.01 <= "<< g5 << " ? " << (4.01 <= g5) << endl;
    cout << g5 <<" <= 4.01 ? " << (g5 <= 4.01) << endl << endl;

    // a++:
    Fraction a1(2,5);
    Fraction b1(2,5);
    cout << "a++: " << endl;
    cout << "before: " << a1 << endl;
    cout << b1 << " + (" << a1 << " ++) = ? "<< (b1 + (a1++)) << endl;
    cout << "4.00003 + (" << a1 << " ++) - "<< g5 << "= ? "<< (4.00003 + (a1++) - g5) << endl;
    cout << "after: " << a1 << endl << endl;

    // ++a:
    Fraction a2(2,5);
    Fraction b2(2,5);
    cout << "++a: " << endl;
    cout << "before: " << a2 << endl;
    cout << b2 << " + (++ " << a2 << ") = ? "<< (b2 + (++a2)) << endl;
    cout << "4.00003 + (++ " << a2 << ") - "<< g5 << "= ? "<< (4.00003 + (++a2) - g5) << endl;
    cout << "after: " << a2 << endl << endl;

    // a--:
    Fraction a3(2,5);
    Fraction b3(2,5);
    cout << "a--: " << endl;
    cout << "before: " << a3 << endl;
    cout << b3 << " + (" << a3 << " --) = ? "<< (b3 + (a3--)) << endl;
    cout << "4.00003 + (" << a3 << " --) - "<< g5 << "= ? "<< (4.00003 + (a3--) - g5) << endl;
    cout << "after: " << a3 << endl << endl;

    // --a:
    Fraction a4(2,5);
    Fraction b4(2,5);
    cout << "--a: " << endl;
    cout << "before: " << a4 << endl;
    cout << b4 << " + (-- " << a4 << ") = ? "<< (b4 + (--a4)) << endl;
    cout << "4.00003 + (-- " << a4 << ") - "<< g5 << "= ? "<< (4.00003 + (--a4) - g5) << endl;
    cout << "after: " << a4 << endl << endl;

}
