#include <iostream>
#include "Header.h"
namespace NS
{
	/*
	int Fraction::gcd(int d_1, int d_2)
	{
		int d = d_1 > d_2 ? d_1 : d_2;
		int divisor = d_1 < d_2 ? d_1 : d_2;

		while (divisor != 0)
		{
			int temp = d % divisor;
			d = divisor;
			divisor = temp;
		}

		return d;
	};

	int Fraction::lcm(int d_1, int d_2)
	{
		int gcd = gcd(int d_1, int d_2);
		return (d_1 * d_2) / gcd;
	};

	void Fraction::reduce()
	{
		int gcd = gcd(abs(m_numerator), m_denominator);

		if (gcd != 1)
		{
			m_numerator /= gcd;
			m_denominator /= gcd;
		}
		std::cout << "The fraction is reduced." << '\n';
	};
	*/

	Fraction::Fraction() : m_numerator(0), m_denominator(1)
	{
		std::cout << "Fraction() is created." << '\n';
	}

	Fraction::Fraction(int n, int d) :
		m_numerator(n), m_denominator(d)
	{
		if (not m_denominator) { std::cout << "Bad!" << '\n'; };
		std::cout << "Fraction(int n, int d) is created." << '\n';
	};
	
	int Fraction::get_numerator() const
	{
		std::cout << "Got the numerator!" << '\n';
		return m_numerator;
	};

	int Fraction::get_denominator() const
	{
		std::cout << "Got the denominator!" << '\n';
		return m_denominator;
	};
	
	/*std::ostream& operator<< (std::ostream& stream, const Fraction& fraction)
	{
		std::string res = "";
		if (m_numerator == 0)
		{
			res.append("0");

			return res;
		}

		else
		{
			res.append(m_numerator);

			if (m_denominator > 1)
			{
				res.append("/");
				res.append(m_denominator);
			}
			return res;
		}
	};

	std::istream& operator>> (std::istream& stream, Fraction& fraction)
	{
		int* d = new int[2];
		stream >> d;
		fraction = Fraction(d);
		delete[] d;

		return stream;
	};*/
	std::ostream& operator<< (std::ostream& stream, const Fraction& fraction)
	{
		if (fraction.m_denominator == 1 || fraction.m_numerator == 0)
		{
			stream << fraction.m_numerator;
			return stream;
		}
		stream << fraction.m_numerator;
		stream << "/";
		stream << fraction.m_denominator;
		return stream;
	}
	std::istream& operator>> (std::istream& stream, Fraction& fraction)
	{
		stream >> fraction.m_numerator;
		stream >> fraction.m_denominator;
		if (fraction.m_denominator == 0)
		{
			std::cout << "Error,  devided by 0" << std::endl;
			std::abort();
		}
		fraction.reduce();
		return stream;
	}
	/*
	Fraction& Fraction::operator=(const Fraction& other)
	{
		std::cout << "Fraction& operator= (const Fraction& other) is working." << '\n';

		if (this == &other)
		{
			return *this;
		}

		m_numerator = other.m_numerator;
		m_denominator = other.m_denominator;

		return *this;
	};
	*/

	/*
	Fraction& Fraction::operator=(Fraction&& other)
	{
		std::cout << "Fraction& operator= (Fraction&& other) is working." << '\n';


		if (this == &other)
		{
			return *this;
		}

		m_numerator = other.m_numerator;
		m_denominator = other.m_denominator;

		other.m_numerator = 0;
		other.m_denominator = 1;

		return *this;
	};
	*/
	Fraction operator+(const Fraction& d1, const Fraction& d2)
	{
		int chislX = d1.m_numerator * d2.m_denominator + d2.m_numerator * d1.m_denominator;
		int znamX = d1.m_denominator * d2.m_denominator;
		return Fraction(chislX, znamX);
	}
	/*Fraction& Fraction::operator+(const Fraction& fraction)
	{
		m_numerator = m_numerator * fraction.m_denominator + fraction.m_numerator * m_denominator;
		m_denominator += fraction.m_denominator;
		reduce();
		return *this;
	};
	*/
   /*
	Fraction& Fraction::operator-(const Fraction& fraction)
	{
		std::cout << "Fraction& operator-(const Fraction& fraction) is working." << '\n';

		int relNumerator = m_numerator * fraction.get_denominator();
		m_numerator = m_numerator * fraction.get_denominator() - m_denominator * fraction.get_numerator();
		m_denominator = gcd(m_denominator, fraction.get_denominator());

		reduce();
		return *this;
	};

	Fraction& Fraction::operator*(const Fraction& fraction)
	{
		std::cout << "Fraction& operator*(const Fraction& fraction) is working." << '\n';

		m_numerator = m_numerator * fraction.get_numerator();
		m_denominator = m_denominator * fraction.get_denominator();

		reduce();
		return *this;
	};

	Fraction& Fraction::operator/(const Fraction& fraction)
	{
		std::cout << "Fraction& operator/(const Fraction& fraction) is working." << '\n';

		m_numerator = m_numerator * fraction.get_denominator();
		m_denominator = m_denominator * fraction.get_numerator();

		reduce();
		return *this;
		
	};*/
	/*
		bool operator==(const Fraction& f_l, const Fraction& f_r)
		{
			std::cout << "bool operator==(const Fraction& fraction) is working." << '\n';
			return f_l.&m_numerator == f_r. & m_numerator && f_l.&m_denominator == f_r. & m_denominator;
		};
		*/
		/*bool Fraction::operator==(int num, const Fraction& f_r)
		{
			Fraction f_l = Fraction(int num, int d = 1);
			return f_l.m_numerator == f_r.m_numerator && f_l.m_denominator == f_r.m_denominator;
		};

		bool Fraction::operator==(const Fraction& f_l, int num)
		{
			Fraction f_r = Fraction(int num, int d = 1);
			return f_r.m_numerator == f_l.m_numerator && f_r.m_denominator == f_l.m_denominator;
			
		};
	
	Fraction& Fraction::operator+=(const Fraction& fraction)
	{
		std::cout << "Fraction& Fraction::operator+=(const Fraction& fraction) is working." << '\n';

		*this = *this + fraction;

		reduce();
		return *this;
	};

	Fraction& Fraction::operator-=(const Fraction& fraction)
	{
		std::cout << "Fraction& Fraction::operator-=(const Fraction& fraction) is working." << '\n';

		*this = *this - fraction;

		reduce();
		return *this;
	};
		
	double Fraction::operator_to_double(const Fraction& fraction)
	{
		std::cout << "Fraction& Fraction::operator_to_double(const Fraction& fraction) is working." << '\n';
		double res = m_numerator / m_denominator;
		return res;
	};


	Fraction::~Fraction()
	{
		m_denominator = 0;

		std::cout << "~Fraction() - Fraction is deleted." << '\n';
	};
	*/
};
