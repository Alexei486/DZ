#pragma once
#include <iostream>
#include <numeric>
class Fraction
{
private:
    int m_chisl;
    int m_znam;
    // static int nod(int a, int b)
     //{
      //   return (b == 0) ? (a > 0 ? a : -a) : nod(b, a % b);
     //}
    void reduce()
    {
        const auto nod = std::gcd(m_chisl, m_znam);
        //  int nod = Fraction::nod(m_chisl, m_znam);
        m_chisl /= nod;
        m_znam /= nod;
    }
public:
    explicit operator double() const
    {
        return double(m_chisl) / double(m_znam);
    }
    Fraction& operator++();
    Fraction operator++(int);
    Fraction& operator--();
    Fraction operator--(int);
    Fraction(int chisl, int znam = 1) : m_chisl(chisl), m_znam(znam)
    {
        reduce();
    }
    Fraction& operator+=(const Fraction& fraction);
    Fraction& operator-=(const Fraction& fraction);
    Fraction& operator*=(const Fraction& fraction);
    Fraction& operator/=(const Fraction& fraction);
    //  Fraction& operator-=(const Fraction& fraction);
      //Fraction& operator/=(const Fraction& fraction);
      //Fraction& operator*=(const Fraction& fraction);
      //friend Fraction operator+=(const Fraction& d1, const Fraction& d2);
      //friend Fraction operator-=(const Fraction& d1, const Fraction& d2);
    friend Fraction operator*(const Fraction& d1, const Fraction& d2);
    friend Fraction operator+(const Fraction& d1, const Fraction& d2);
    friend Fraction operator-(const Fraction& d1, const Fraction& d2);
    friend Fraction operator/(const Fraction& d1, const Fraction& d2);
    friend std::ostream& operator << (std::ostream& out, const Fraction& d1);
    void print()
    {
        std::cout << m_chisl << "/" << m_znam << "-> ";
    }
};