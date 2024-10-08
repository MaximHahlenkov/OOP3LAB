#pragma once
#include "iostream"

class Fraction 
{
	const int AfterPoint = 3;

	long* AbFractional;
	unsigned short* Fractional; 

public:
	Fraction();
	Fraction(long _AbFractional, unsigned short _Fractional);
	Fraction(const Fraction& other);
	~Fraction();
	
	long getAbFractional() { return *AbFractional; };
	unsigned short getFractional() { return *Fractional; };
	void setAbFractional(long _AbFractional) { *AbFractional = _AbFractional; };
	void setFractional(unsigned short _Fractional) { *Fractional = _Fractional; };
	
	void PrintFrac();
	double ToDouble() const;

	Fraction& operator=(const Fraction& Frac);
	Fraction operator+(const Fraction& Frac);
	Fraction operator-(const Fraction& Frac);
	Fraction operator*(const Fraction& Frac);
	Fraction operator/(const Fraction& Frac);

	bool operator==(const Fraction& Frac);
	bool operator>(const Fraction& Frac);
	bool operator<(const Fraction& Frac);
	bool operator>=(const Fraction& Frac);
	bool operator<=(const Fraction& Frac);

	friend std::istream& operator>>(std::istream& is, Fraction& frac);
};