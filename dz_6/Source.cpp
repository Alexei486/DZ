#include "Header.h"
Fraction& Fraction::operator++()
{
    m_chisl += m_znam;
    return *this;
}
Fraction Fraction::operator++(int)
{
    Fraction temp(m_chisl, m_znam);
    ++(*this);
    return temp;
}
Fraction& Fraction::operator--()
{
    m_chisl -= m_znam;
    return *this;
}
Fraction Fraction::operator--(int)
{
    Fraction temp(m_chisl, m_znam);
    --(*this);
    return temp;
}

std::ostream& operator<< (std::ostream& out, const Fraction& d1)
{
    out << d1.m_chisl;
    return out;
}
Fraction& Fraction::operator+=(const Fraction& fraction)
{
    m_chisl = m_chisl * fraction.m_znam + fraction.m_chisl * m_znam;
    m_znam *= fraction.m_znam;
    reduce();
    return *this;
}
Fraction& Fraction::operator-=(const Fraction& fraction)
{
    m_chisl = m_chisl * fraction.m_znam - fraction.m_chisl * m_znam;
    m_znam *= fraction.m_znam;
    reduce();
    return *this;
}
Fraction& Fraction::operator*=(const Fraction& fraction)
{
    m_chisl *= fraction.m_chisl;
    m_znam *= fraction.m_znam;
    reduce();
    return *this;
}
Fraction& Fraction::operator/=(const Fraction& fraction)
{
    m_chisl = m_chisl * fraction.m_znam;
    m_znam = m_znam * fraction.m_chisl;
    reduce();
    return *this;
}
Fraction operator*(const Fraction& d1, const Fraction& d2)
{
    return Fraction(d1.m_chisl * d2.m_chisl, d1.m_znam * d2.m_znam);
}
Fraction operator/(const Fraction& d1, const Fraction& d2)
{
    return Fraction(d1.m_chisl * d2.m_znam, d1.m_znam * d2.m_chisl);
}
Fraction operator+(const Fraction& d1, const Fraction& d2)
{
    int chislX = d1.m_chisl * d2.m_znam + d2.m_chisl * d1.m_znam;
    int znamX = d1.m_znam * d2.m_znam;
    return Fraction(chislX, znamX);
}
Fraction operator-(const Fraction& d1, const Fraction& d2)
{
    int chislX = d1.m_chisl * d2.m_znam - d2.m_chisl * d1.m_znam;
    int znamX = d1.m_znam * d2.m_znam;
    return Fraction(chislX, znamX);
}
