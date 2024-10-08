#pragma once
#include "Fraction.h"

class Calculator 
{
	Fraction Calcul;
	Fraction Other;

public:
	
	Calculator();
	Calculator(Fraction _Calcul, Fraction _Other);

	Fraction getCalcul() { return Calcul; };
	Fraction getOther() { return Other; };

	void setCalcul(Fraction _Calcul) { Calcul = _Calcul; }
	void setOther(Fraction _Other) { Other = _Other; }

	Fraction Addition();
	Fraction Substract();
	Fraction Multiply();
	Fraction Division();
};

