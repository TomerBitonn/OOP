#include "Rational.h"

Rational::Rational(int mone, int mechane)
{
	if (mone < 0 && mechane < 0)
	{
		mone *= (-1);
		mechane *= (-1);
	}
	if (mechane == 0)
	{
		denominator = 1;
	}
	else
	{
		denominator = mechane;
	}
	numerator = mone;
	Gcd();
}

void Rational::Gcd()
{
	int mone = numerator, mechane = denominator,temp;
	while (mechane != 0)
	{
		temp = mechane;
		mechane = mone % mechane;
		mone = temp;
	}
	numerator /= mone;
	denominator /= mone;
}

void Rational::SetNumerator(int mone)
{
	numerator = mone;
	Gcd();
}

void Rational::SetDenomirator(int mechane)
{
	if (mechane != 0)
	{
		denominator = mechane;
		Gcd();
	}
}

int Rational::GetNumerator() const
{
	return numerator;
}

int Rational::GetDenominator() const
{
	return denominator;
}

Rational& Rational::operator+(const Rational& r) const
{
	int mone = numerator * r.denominator + denominator * r.numerator;
	int mechane = denominator * r.denominator;
	Rational* temp = new Rational(mone, mechane);
	return *temp; // return the value of temp. reference.
}

Rational& Rational::operator+(const int& num) const
{
	int mone = numerator + denominator * num, mechane = denominator;
	Rational* temp = new Rational(mone,mechane);
	return *temp;
}

Rational& Rational::operator*(const Rational& r) const
{
	Rational* temp = new Rational(numerator * r.numerator, denominator * r.denominator);
	return *temp;
}

Rational& Rational::operator*(const int& num) const
{
	Rational* temp = new Rational(numerator * num, denominator);
	return *temp;
}

Rational& Rational::Inverse() const
{
	Rational* temp = new Rational(denominator,numerator);
	return *temp;
}

Rational& Rational::operator-(const Rational& r) const
{
	int mone = numerator * r.denominator - r.numerator * denominator;
	int mechane = denominator * r.denominator;
	Rational* temp = new Rational(mone, mechane);
	return *temp;
}

Rational& Rational::operator-(const int& num) const
{
	int mone = numerator - num * denominator;
	Rational* temp = new Rational(mone, denominator);
	return *temp;
}

Rational& Rational::operator/(const Rational& r) const
{
	int mone = denominator * r.numerator, mechane = numerator * r.denominator;
	Rational* temp = new Rational(mone,mechane);
	return (*temp).Inverse();
}

Rational& Rational::operator/(const int& num) const
{
	Rational* temp = new Rational(numerator, denominator * num);
	return *temp;
}

istream& operator>>(istream& input, Rational& r)
{
	cout << "Enter 2 numbers(num1, num2): ";
	input >> r.numerator >> r.denominator;
	r.Gcd();
	return input;
}

ostream& operator<<(ostream& output, const Rational& r)
{
	output << r.numerator << "/" << r.denominator << endl;
	return output;
}

Rational& operator+(const int& num, const Rational& r)
{
	return r + num;
}

Rational& operator*(const int& num, const Rational& r)
{
	return r * num;
}

Rational& operator-(const int& num, const Rational& r)
{
	int mone = num * r.denominator - r.numerator;
	Rational* temp = new Rational(mone, r.denominator);
	return *temp;
}

Rational& operator/(const int& num, const Rational& r)
{
	Rational* temp = new Rational(num * r.denominator, r.numerator);
	return *temp;
}