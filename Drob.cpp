#include "Drob.h"
#include <iostream>

using namespace std;

Drob::Drob(int x, int y) {
	this->setX(x);
	this->setY(y);
}
Drob::Drob(double x) : Drob() {
	int denominator = 1;
	while (true) {
		if (x == (int)x) {
			this->x = x;
			this->y = denominator;
			break;
		}
		x *= 10;
		denominator *= 10;
	}
}

void Drob::setX(int x) {
	this->x = x;
}
void Drob::setY(int y) {
	(y == 0) ? this->y = 1 : this->y = y;
}

int Drob::getX() const { return this->x; }
int Drob::getY() const { return this->y; }

double Drob::getDecimal() const {
	return (double)this->x / this->y;
}
void Drob::print() const {
	cout << this->x << " / " << this->y << " = " << (double)this->x / this->y;
}
void Drob::reduce() {
	if (this->x == 0)
		return;
	int denominator;
	this->x > this->y ? denominator = this->x : denominator = this->y;
	while (true) {
		if (((double)this->x / denominator == this->x / denominator) && ((double)this->y / denominator == this->y / denominator)) {
			this->x /= denominator;
			this->y /= denominator;
			return;
		}
		denominator--;
	}
}

Drob& Drob::operator+=(const Drob& right) {
	this->x = this->x * right.y + right.x * this->y;
	this->y = this->y * right.y;
	this->reduce();
	return *this;
}
Drob& Drob::operator-=(const Drob& right) {
	this->x = this->x * right.y - right.x * this->y;
	this->y = this->y * right.y;
	this->reduce();
	return *this;
}
Drob& Drob::operator*=(const Drob& right) {
	this->x = this->x * right.x;
	this->y = this->y * right.y;
	this->reduce();
	return *this;
}
Drob& Drob::operator/=(const Drob& right) {
	this->x = this->x * right.y;
	this->y = this->y * right.x;
	this->reduce();
	return *this;
}
Drob& Drob::operator+=(double right) {
	*this += Drob(right);
	this->reduce();
	return *this;
}
Drob& Drob::operator-=(double right) {
	*this -= Drob(right);
	this->reduce();
	return *this;
}
Drob& Drob::operator*=(double right) {
	*this *= Drob(right);
	this->reduce();
	return *this;
}
Drob& Drob::operator/=(double right) {
	*this /= Drob(right);
	this->reduce();
	return *this;
}

Drob& Drob::operator++() {
	this->x += this->y;
	return *this;
}
Drob& Drob::operator++(int) {
	Drob tmp = *this;
	this->x += this->y;
	return tmp;
}

Drob operator-(const Drob& a) {
	Drob res(-a.x, a.y);
	return res;
}
Drob operator-(const Drob& a, const Drob& b) {
	Drob res;
	res.x = a.x * b.y - b.x * a.y;
	res.y = a.y * b.y;
	return res;
}
Drob operator-(const Drob& a, double b) {
	Drob res = a;
	res -= Drob(b);
	return res;
}
Drob operator-(double a, const Drob& b) {
	Drob res = b;
	res -= Drob(a);
	return res;
}

Drob operator+(const Drob& a, const Drob& b) {
	Drob res;
	res.x = a.x * b.y + b.x * a.y;
	res.y = a.y * b.y;
	return res;
}
Drob operator+(const Drob& a, double b) {
	Drob res = a;
	res += Drob(b);
	return res;
}
Drob operator+(double a, const Drob& b) {
	Drob res = b;
	res += Drob(a);
	return res;
}

bool operator<(const Drob& a, const Drob& b) {
	return a.getDecimal() < b.getDecimal();
}
bool operator>(const Drob& a, const Drob& b) {
	return a.getDecimal() > b.getDecimal();
}
bool operator<=(const Drob& a, const Drob& b) {
	return a.getDecimal() <= b.getDecimal();
}
bool operator>=(const Drob& a, const Drob& b) {
	return a.getDecimal() >= b.getDecimal();
}
bool operator==(const Drob& a, const Drob& b) {
	return a.getDecimal() == b.getDecimal();
}
bool operator!=(const Drob& a, const Drob& b) {
	return a.getDecimal() != b.getDecimal();
}

ostream& operator<<(ostream& out, const Drob& d) {
	out << d.x << " / " << d.y << " = " << (double)d.x / d.y;
	return out;
}
istream& operator>>(istream& in, Drob& d) {
	cout << "Enter x\n";
	in >> d.x;
	cout << "Enter y\n";
	int q;
	cin >> q;
	d.setY(q);
	return in;
}