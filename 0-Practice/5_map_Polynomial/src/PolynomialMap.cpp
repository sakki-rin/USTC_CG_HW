#include "PolynomialMap.h"

#include <iostream>
#include <fstream>
#include <cassert>
#include <cmath>

#define EPSILON 1.0e-10

using namespace std;

PolynomialMap::PolynomialMap(const PolynomialMap& other) {
	// TODO
	m_Polynomial = other.m_Polynomial;//拷贝构造
}

PolynomialMap::PolynomialMap(const string& file) {
	ReadFromFile(file);
}

PolynomialMap::PolynomialMap(const double* cof, const int* deg, int n) {
	// TODO
	for (int i = 0; i < n; i++)
	{
		coff(deg[i]) = cof[i]; //值列表初始化
	}
}

PolynomialMap::PolynomialMap(const vector<int>& deg, const vector<double>& cof) {
	assert(deg.size() == cof.size());
	// TODO
	for (unsigned int i = 0; i < deg.size(); i++)
	{
		coff(deg[i]) = cof[i];
	}
}

double PolynomialMap::coff(int i) const{
	// TODO
	if (m_Polynomial.find(i) != m_Polynomial.end())
	{
		//return m_Polynomial[i]; //wrong
		return m_Polynomial.at(i);
	}
	else
	{
		return 0;
	}
	// you should return a correct value
}

double& PolynomialMap::coff(int i) {
	// TODO
	return m_Polynomial[i]; // you should return a correct value
}

void PolynomialMap::compress() {
	// TODO
	for (map<int, double>::iterator itr = m_Polynomial.begin(); itr != m_Polynomial.end(); )
	{
		if (fabs(itr->second) < EPSILON)
		{
			itr = m_Polynomial.erase(itr);
		}
		else
			itr++;
	}
}

PolynomialMap PolynomialMap::operator+(const PolynomialMap& right) const {
	// TODO
	PolynomialMap poly(right);
	map<int, double>::const_iterator itr = m_Polynomial.begin();
	for (; itr != m_Polynomial.end(); itr++)
	{
		poly.coff(itr->first) += itr->second;
	}
	poly.compress();
	return poly; // you should return a correct value
}

PolynomialMap PolynomialMap::operator-(const PolynomialMap& right) const {
	// TODO
	PolynomialMap poly(right);
	map<int, double>::const_iterator itr = m_Polynomial.begin();
	for (; itr != m_Polynomial.end();itr++)
	{
		//poly.coff(itr->first) -= itr->second;
		poly.m_Polynomial[itr->first] -= itr->second;
	}
	poly.compress();
	return poly; // you should return a correct value
}

PolynomialMap PolynomialMap::operator*(const PolynomialMap& right) const {
	// TODO
	PolynomialMap poly;
	map<int, double> p1, p2;
	p1 = this->m_Polynomial;
	p2 = right.m_Polynomial;
	for (map<int, double>::const_iterator itr1 = p1.begin(); itr1 != p1.end(); itr1++)
	{
		for (map<int, double>::const_iterator itr2 = p2.begin(); itr2 != p2.end(); itr2++)
		{
			double cof = itr1->second * itr2->second;
			int deg = itr1->first + itr2->first;
			poly.coff(deg) += cof;
		}
	}
	return poly; // you should return a correct value
}

PolynomialMap& PolynomialMap::operator=(const PolynomialMap& right) {
	// TODO
	m_Polynomial = right.m_Polynomial;
	return *this;
}

void PolynomialMap::Print() const {
	// TODO
	map<int, double>::const_iterator itr = m_Polynomial.begin();
	if (itr == m_Polynomial.end())
	{
		cout << "0" << endl;
		return;
	}
	for (; itr != m_Polynomial.end(); itr++)
	{
		if (itr != m_Polynomial.begin() && itr->second > 0)
		{
			cout << "+";
		}
		cout << itr->second;
		if (itr->first > 0)
		{
			cout << "x^"<<itr->first;
		}
	}
	cout << endl;
}

bool PolynomialMap::ReadFromFile(const string& file) {
	m_Polynomial.clear();
	// TODO
	ifstream inp(file);
	if (!inp.is_open())
	{
		cout << "ERROR:PolynomialList::ReadFromfile:" << endl
			<< "\t" << "file [" << "] opens failed" << endl;
		return false;
	}
	char ch;
	int n;
	inp >> ch;
	inp >> n;
	for (int i = 0; i < n; i++)
	{
		int deg;
		double cof;
		inp >> deg;
		inp >> cof;
		coff(deg) = cof;
	}
	inp.close();
	return true; // you should return a correct value
}