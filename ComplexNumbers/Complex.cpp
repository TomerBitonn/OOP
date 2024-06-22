#include "Complex.h"

Complex::Complex(double n_real, double n_img)
{
	real = n_real;
	img = n_img;
}

Complex::Complex(const Complex& num)
{
	real = num.real;
	img = num.img;
}

double Complex::GetReal() const
{
	return real;
}

double Complex::GetImg() const
{
	return img;
}

void Complex::SetReal(const double& r)
{
	real = r;
}

void Complex::SetImg(const double& i)
{
	img = i;
}

Complex& Complex::operator+=(const Complex& num)
{
	real += num.real;
	img += num.img;
	return *this;
}

Complex& Complex::operator*=(const Complex& num)
{
	double temp_real = real, temp_img = img;
	real = temp_real * num.real + temp_img * (-1 * num.img);
	img = temp_real * num.img + temp_img * num.real;
	return *this;
}

Complex& Complex::operator/=(const Complex& num)
{
	double temp_real = real, temp_img = img;
	double denominator = num.real * num.real + num.real * (-1 * num.img) + num.img * num.real + num.img * num.img;
	real = temp_real * num.real + temp_img * num.img;
	img = temp_real * (-1 * num.img) + temp_img * num.real;
	real /= denominator;
	img /= denominator;
	return *this;
}

Complex& Complex::operator-=(const Complex& num)
{
	real -= num.real;
	img -= num.img;
	return *this;
}

Complex& Complex::operator+(const Complex& num) const
{
	Complex* temp = new Complex(real + num.real, img + num.img);
	return *temp;
}

Complex& Complex::operator-(const Complex& num) const
{
	Complex* temp = new Complex(real - num.real, img - num.img);
	return *temp;
}

Complex& Complex::operator*(const Complex& num) const
{
	double temp_real = real, temp_img = img;
	temp_real = real * num.real + img * (-1 * num.img);
	temp_img = real * num.img + img * num.real;
	Complex* temp = new Complex(temp_real, temp_img);
	return *temp;
}

Complex& Complex::operator/(const Complex& num) const
{
	double real_temp = real, img_temp = img;
	double denominator = num.real * num.real + num.real * (-1 * num.img) + num.img * num.real + num.img * num.img;
	real_temp = real * num.real + img * num.img;
	img_temp = real * (-1 * num.img) + img * num.real;
	real_temp /= denominator;
	img_temp /= denominator;
	Complex* temp = new Complex(real_temp, img_temp);
	return *temp;
}

Complex& Complex::operator*(const double& d) const
{
	Complex* temp = new Complex(real * d, img * d);
	return *temp;
}

Complex& Complex::operator/(const double& d) const
{
	Complex* temp = new Complex(real / d, img / d);
	return *temp;
}

Complex& operator*(const double& d, const Complex& num)
{
	return num * d;
}

Complex& operator/(const double& d, const Complex& num)
{
	double real_temp = num.real, img_temp = num.img;
	double denominator = num.real * num.real + num.real * (-1 * num.img) + num.img * num.real + num.img * num.img;
	real_temp = num.real * d;
	img_temp = (-1 * num.img) * d;;
	real_temp /= denominator;
	img_temp /= denominator;
	Complex* temp = new Complex(real_temp, img_temp);
	return *temp;
}

istream& operator>>(istream& input, Complex& num)
{
	cout << "Enter real number:";
	input >> num.real;
	cout << "Enter img number:";
	input >> num.img;
	return input;
}

ostream& operator<<(ostream& output, Complex& num)
{
	double temp_img = num.img;
	char sign = NULL;

	if (num.img > 0)
		sign = '+';
	else
		sign = '-';

	if (num.img < 0)
		num.img *= -1;
	
	output << "The complex number is: " << num.real  << " " << sign  << " " << num.img << "i" << endl;

	num.img = temp_img;

	return output;
}