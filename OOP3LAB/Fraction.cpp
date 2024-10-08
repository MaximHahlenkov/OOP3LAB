#include <iostream>
#include "Fraction.h"
#include "Utility.h"

Fraction::Fraction()
{
	AbFractional = new long(1);
	Fractional = new unsigned short(pow(10, AfterPoint));
}

Fraction::Fraction(long _AbFractional, unsigned short _Fractional) 
{
	AbFractional = new long(_AbFractional);
	Fractional = new unsigned short(ToAfterPoint(_Fractional, AfterPoint));
}

Fraction::~Fraction() 
{
	delete AbFractional;
	delete Fractional;

	AbFractional = nullptr;
	Fractional = nullptr;
}

Fraction::Fraction(const Fraction& frac) 
{
	AbFractional = new long(*frac.AbFractional);
	Fractional = new unsigned short(*frac.Fractional);
}

Fraction Fraction::operator+(const Fraction& frac) 
{
	Fraction temp;
	long res_l = *AbFractional + *frac.AbFractional;
	unsigned short res_us= *Fractional + *frac.Fractional;
	
	if (res_us >= pow(10, AfterPoint) || res_us < 0)
	{
		res_l--;
		res_us += pow(10, AfterPoint);
	}
	temp.setAbFractional(res_l);
	temp.setFractional(res_us);
	return temp;
}

Fraction Fraction::operator-(const Fraction& frac)
{
	Fraction temp;
	long res_l = *AbFractional - *frac.AbFractional;
	unsigned short res_us = *Fractional - *frac.Fractional;

	if (res_us >= pow(10, AfterPoint) || res_us < 0)
	{
		res_l--;
		res_us += pow(10, AfterPoint);
	}
	temp.setAbFractional(res_l);
	temp.setFractional(res_us);
	return temp;
}

Fraction Fraction::operator*(const Fraction& frac)
{
	Fraction temp = frac;
	double res = ToDouble() * temp.ToDouble();
	return ToFrac(res, AfterPoint);
}

Fraction Fraction::operator/(const Fraction& frac)
{
	if (frac.AbFractional == 0 && frac.Fractional == 0)
	{
		return *this;
	}
	else 
	{
		Fraction temp = frac;
		double res = ToDouble() / temp.ToDouble();
		return ToFrac(res, AfterPoint);
	}
}

Fraction& Fraction::operator=(const Fraction& frac)
{
	if (this == &frac)
		return *this;
	else
	{
		delete AbFractional;
		delete Fractional;

		AbFractional = new long(*frac.AbFractional);
		Fractional = new unsigned short(*frac.Fractional);
	}
	return *this;
}


bool Fraction::operator==(const Fraction& frac)
{
	if (ToDouble() == frac.ToDouble())
		return true;
	else
		return false;
}

bool Fraction::operator<(const Fraction& frac)
{
	if (ToDouble() < frac.ToDouble())
		return true;
	else
		return false;
}

bool Fraction::operator>(const Fraction& frac)
{
	if (ToDouble() > frac.ToDouble())
		return true;
	else
		return false;
}

bool Fraction::operator>=(const Fraction& frac)
{
	if (ToDouble() >= frac.ToDouble())
		return true;
	else
		return false;
}

bool Fraction::operator<=(const Fraction& frac)
{
	if (ToDouble() <= frac.ToDouble())
		return true;
	else
		return false;
}

std::istream& operator>>(std::istream& is, Fraction& frac) 
{
	is >> *frac.AbFractional >> *frac.Fractional;
	return is;
}