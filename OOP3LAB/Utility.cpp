#include "Fraction.h"
#include "Utility.h"
#include <iostream>
#include <cmath>
#include <iomanip>

void Fraction::PrintFrac() { 
	std::cout << *AbFractional << '.';
	if (*Fractional < 100 && *Fractional > 10)
		std::cout << "0";
	else if (*Fractional < 10)
		std::cout << "00";
	std::cout <<*Fractional << "\n";
}

double Fraction::ToDouble() const
{
	double temp = static_cast<double>(*AbFractional);
	if (temp < 0)
		temp -= static_cast<double>(*Fractional) / pow(10, AfterPoint);
	else
		temp += static_cast<double>(*Fractional) / pow(10, AfterPoint);
	return temp;
}

Fraction ToFrac(int res, int param) 
{
	Fraction temp;
	temp.setAbFractional(static_cast<long>(res / static_cast<int>(pow(10, param))));
	temp.setFractional(static_cast<unsigned short>(abs(res) % static_cast<int>(pow(10, param))));
	return temp;
}

Fraction ToFrac(double res, int param)
{
	Fraction temp;
	double FracTemp = res;
	temp.setAbFractional(static_cast<long>(res));
	FracTemp -= static_cast<double>(temp.getAbFractional());

	temp.setFractional(static_cast<unsigned short>( (res * static_cast<int>(pow(10, param)))) % static_cast<int>(pow(10, param)));
	return temp;
}

int DigNum(int inp) 
{
	int temp = inp;
	int res = 1;
	if (inp < 10)
		return res;
	else
		while (temp > 0) 
		{
			temp /= 10;
			res++;
		}
	return res-1;
}

unsigned short ToAfterPoint(unsigned short inp, int param) 
{
	int res = static_cast<int>(inp);
	int temp = DigNum(static_cast<int>(inp));
		
	if (temp <= param)
		return inp;
	else if (temp > param)
		res /= (pow(10,temp - param));
	return static_cast<unsigned short>(res);
}