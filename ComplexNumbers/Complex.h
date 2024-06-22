#include <iostream>
using namespace std;

#pragma once
class Complex
{
	friend Complex& operator*(const double& d, const Complex& num);
	friend Complex& operator/(const double& d, const Complex& num);
	friend istream& operator>>(istream& input, Complex& num);
	friend ostream& operator<<(ostream& output, Complex& num);
private:
	double real;
	double img;
public:
	Complex(double n_real = 1, double n_img = 1);
	Complex(const Complex& num);
	double GetReal() const;
	double GetImg() const;
	void SetReal(const double& r);
	void SetImg(const double& i);
	Complex& operator+=(const Complex& num);
	Complex& operator *=(const Complex& num);
	Complex& operator /=(const Complex& num);
	Complex& operator -=(const Complex& num);
	Complex& operator+(const Complex& num) const;
	Complex& operator-(const Complex& num) const;
	Complex& operator*(const Complex& num) const;
	Complex& operator/(const Complex& num) const;
	Complex& operator*(const double& d) const;
	Complex& operator/(const double& d) const;
};

