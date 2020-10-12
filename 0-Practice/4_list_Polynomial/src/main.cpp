#include "PolynomialList.h"
#include <list>
#include <iostream>


int main(int argc, char** argv) {
	PolynomialList p1("P3.txt");
	PolynomialList p2("P4.txt");
	PolynomialList p3;
	p1.Print();
	p2.Print();

	p3 = p1 + p2;
	p3.Print();
	p3 = p1 - p2;
	p3.Print();

	p3 = p1 * p2;
	p3.Print();

	p2 = p1;
	p1.Print();
	p2.Print();

	return 0;
}