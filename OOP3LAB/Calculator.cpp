#include "Calculator.h"
#include "Fraction.h"
#include "Utility.h"
#include <iostream>

Calculator::Calculator() 
{
	Calcul = Fraction();
	Other = Fraction();
}

Calculator::Calculator(Fraction _Calcul, Fraction _Other) 
{
	Calcul = _Calcul;
	Other = _Other;
}

Fraction Calculator::Addition()
{
	return Calcul + Other;
}

Fraction Calculator::Substract()
{
	return Calcul - Other;
}

Fraction Calculator::Multiply()
{
	return Calcul * Other;
}

Fraction Calculator::Division()
{
	return Calcul / Other;
}

