#include <cmath>
#include<iostream>
#include<cstdlib>

using namespace std;
//Ex1
/*
class A {
public:
	A(int x = 5, int y = 5) {
		cout << x << " " << y <<" "<< x + y << endl;
	}
};

int main() {
	A a;
	A b(1);
	A c(1, 2);
	A d('1', 1);
}*/
//Ex2
/*
class B {
	int value = 0;
public:
	B() {
		value = 10;
	}
	B(B& copy) {
		value = copy.value + 10;
	}
	int get() {
		return value;
	}
};

int main() {
	B b1, b2 = b1, b3(b2);
	cout << b1.get() << b2.get() << b3.get() << endl;

}
*/
//Ex4
/*
// #include "Fraction.h"

int main() {
	Fraction a(3, 4), b(5, 6), z(3,6);
	a.show();
	z.show();
	Fraction c = a + b;
	c.show();
	c = a - b;
	c.show();
	c = a * b;
	c.show();
	c = a / b;
	c.show();
}
*/
//Ex5
#includer "Complex.h"

int main() {
	Complex a(1,2), b(3,4);
	Complex c;
	c = a+b;
	c.show();
	c = a-b;
	c.show();
	c = a*b;
	c.show();
	c = a/b;
	c.show();
	c = pow(a,3);
	c.show();
}