#pragma once
#include <iostream>

using namespace std;

class Drob {
	int x;
	int y;
public:
	explicit Drob(int x = 0, int y = 1);
	explicit Drob(double x);

	void setX(int x);
	void setY(int y);

	int getX() const;
	int getY() const;

	double getDecimal() const;
	void print() const;
	void reduce();

	Drob& operator+=(const Drob& right);
	Drob& operator-=(const Drob& right);
	Drob& operator*=(const Drob& right);
	Drob& operator/=(const Drob& right);
	Drob& operator+=(double right);
	Drob& operator-=(double right);
	Drob& operator*=(double right);
	Drob& operator/=(double right);

	Drob& operator++();
	Drob& operator++(int);

	friend Drob operator-(const Drob& a);
	friend Drob operator-(const Drob& a, const Drob& b);
	friend Drob operator-(const Drob& a, double b);
	friend Drob operator-(double a, const Drob& b);

	friend Drob operator+(const Drob& a, const Drob& b);
	friend Drob operator+(const Drob& a, double b);
	friend Drob operator+(double a, const Drob& b);

	friend bool operator<(const Drob& a, const Drob& b);
	friend bool operator>(const Drob& a, const Drob& b);
	friend bool operator<=(const Drob& a, const Drob& b);
	friend bool operator>=(const Drob& a, const Drob& b);
	friend bool operator==(const Drob& a, const Drob& b);
	friend bool operator!=(const Drob& a, const Drob& b);

	friend ostream& operator<<(ostream& out, const Drob& d);
	friend istream& operator>>(istream& in, Drob& d);
};