#include <iostream>
using namespace std;

#pragma once
class Rational
{
	friend istream& operator>>(istream& input, Rational& r);
	friend ostream& operator<<(ostream& output, const Rational& r);
	friend Rational& operator+(const int& num,const Rational& r);
	friend Rational& operator*(const int& num, const Rational& r);
	friend Rational& operator-(const int& num, const Rational& r);
	friend Rational& operator/(const int& num, const Rational& r);
private:
	int numerator;
	int denominator;
public:
	Rational(int mone = 0, int mechane = 1);
	void Gcd();
	void SetNumerator(int mone);
	void SetDenomirator(int mechane);
	int GetNumerator() const;
	int GetDenominator() const;
	Rational& operator+(const Rational& r) const; 
	Rational& operator+(const int& num) const;
	Rational& operator*(const Rational& r) const;
	Rational& operator*(const int& num) const;
	Rational& Inverse() const;
	Rational& operator-(const Rational& r) const;
	Rational& operator-(const int& num) const;
	Rational& operator/(const Rational& r) const;
	Rational& operator/(const int& num) const;
};

