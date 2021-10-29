#pragma once
#include <iostream>
#include <numeric>

class exception : public std::exception
{
public:
    exception(const std::string& s) : std::exception(s.c_str())
    {}
    ~exception() noexcept = default;
};

namespace Li
{
    class Fraction
    {
    private:
        int m_chisl;
        int m_znam;
        void reduce()
        {
            const auto nod = std::gcd(m_chisl, m_znam);
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

        friend Fraction operator*(const Fraction& d1, const Fraction& d2);
        friend Fraction operator==(const Fraction& d1, const Fraction& d2);
        friend Fraction operator+(const Fraction& d1, const Fraction& d2);
        friend Fraction operator-(const Fraction& d1, const Fraction& d2);
        friend Fraction operator/(const Fraction& d1, const Fraction& d2);
        friend std::ostream& operator<< (std::ostream& stream, const Fraction& fraction);
        friend std::istream& operator>> (std::istream& stream, Fraction& fraction);
        void print() const
        {
            std::cout << m_chisl << "/" << m_znam << "-> ";
        }
        void print1() const
        {
            if (m_chisl == 404)
            {
                std::cout << "False";
            }
            else
            {
                std::cout << "True";
            }
        }
    };
    std::ostream& operator<< (std::ostream& stream, const Fraction& fraction);
    std::istream& operator>> (std::istream& stream, Fraction& fraction);

}