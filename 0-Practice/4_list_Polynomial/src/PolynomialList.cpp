#include "PolynomialList.h"

#define EPSILON 1.0e-10

using namespace std;

PolynomialList::PolynomialList(const PolynomialList& other) {
    // TODO
    m_Polynomial = other.m_Polynomial;
}

PolynomialList::PolynomialList(const string& file) {
    // TODO
    ReadFromFile(file);
}

PolynomialList::PolynomialList(const double* cof, const int* deg, int n) {
    // TODO
    for (int i = 0; i < n; i++)
    {
        AddOneTerm(Term(deg[i], cof[i])); //有参构造
    }
}

PolynomialList::PolynomialList(const vector<int>& deg, const vector<double>& cof) {
    // TODO
    assert(deg.size() == cof.size());

    for (size_t i = 0; i < deg.size(); i++)
    {
        AddOneTerm(Term(deg[i], cof[i]));
    }
}

double PolynomialList::coff(int i) const {
    // TODO
    list<Term>::const_iterator itr = m_Polynomial.begin();
    for (; itr != m_Polynomial.end(); itr++)
    {
        if ((*itr).deg > i)
            break;
        if ((*itr).deg == i)
        {
            return (*itr).cof;
        }
    }

    return 0.; // you should return a correct value
}

double& PolynomialList::coff(int i) {
    // TODO
   return AddOneTerm(Term(i,0)).cof; // you should return a correct value
}

void PolynomialList::compress() {
    // TODO
    list<Term>::iterator itr = m_Polynomial.begin();
    while(itr != m_Polynomial.end())
    {
        if (fabs((*itr).cof) < EPSILON)
        {
            itr = m_Polynomial.erase(itr);
        }
        else
            itr++;
    }
}

PolynomialList PolynomialList::operator+(const PolynomialList& right) const {
    // TODO
    PolynomialList poly(right);
    list<Term>::const_iterator itr = m_Polynomial.begin();
    for (; itr != m_Polynomial.end(); itr++)
    {
        poly.AddOneTerm(*itr);
    }
    poly.compress();
    return poly; // you should return a correct value
}

PolynomialList PolynomialList::operator-(const PolynomialList& right) const {
    // TODO
    PolynomialList poly(right);
    list<Term>::const_iterator itr = m_Polynomial.begin();
    for (; itr != m_Polynomial.end(); itr++)
    {
        poly.AddOneTerm(Term((*itr).deg, -(*itr).cof));
    }
 /*   for (const auto& term : m_Polynomial)
    {
        poly.AddOneTerm(Term(term.deg, -term.cof));
    }*/
    poly.compress();
    return poly; // you should return a correct value
}

PolynomialList PolynomialList::operator*(const PolynomialList& right) const {
    // TODO
    PolynomialList poly;
    list<Term> p1, p2;
    p1 = this->m_Polynomial;
    p2 = right.m_Polynomial;
    list<Term>::iterator itr1, itr2;
    for (itr1 = p1.begin(); itr1 != p1.end(); itr1++)
    {
        for (itr2 = p2.begin(); itr2 != p2.end(); itr2++)
        {
            double cof = (*itr1).cof * (*itr2).cof;
            int deg = (*itr1).deg + (*itr2).deg;
            poly.AddOneTerm(Term(deg, cof));
        }
    }
    return poly; // you should return a correct value
}

PolynomialList& PolynomialList::operator=(const PolynomialList& right) {
    // TODO
    m_Polynomial.clear();
    list<Term>::const_iterator itr = right.m_Polynomial.begin();
    for (; itr != right.m_Polynomial.end(); itr++)
    {
        this->AddOneTerm((*itr));
    }
    return *this;
}

void PolynomialList::Print() const {
    // TODO
    list<Term>::const_iterator itr = m_Polynomial.begin();
    if (itr == m_Polynomial.end())
    {
        cout << "0" << endl;
    }
    for (; itr != m_Polynomial.end(); itr++)
    {
        if (itr != m_Polynomial.begin() && (*itr).cof > 0)
        {
            cout << "+";
        }
        cout << (*itr).cof;
        if ((*itr).deg > 0)
        {
            cout << "x^" << (*itr).deg;
        }
    }
    cout << endl;
}

bool PolynomialList::ReadFromFile(const string& file) {
    // TODO
    m_Polynomial.clear();

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
        Term nd;
        inp >> nd.deg;
        inp >> nd.cof;

        AddOneTerm(nd);
    }
    inp.close();
    return true; // you should return a correct value
}

PolynomialList::Term& PolynomialList::AddOneTerm(const Term& term) {
    // TODO
    list<Term>::iterator itr = m_Polynomial.begin();
    for (; itr != m_Polynomial.end(); itr++)
    {
        if ((*itr).deg == term.deg)
        {
            (*itr).cof += term.cof;
            return *itr;
        }

        if ((*itr).deg > term.deg)
            break;
    }

    return *m_Polynomial.insert(itr,term); // you should return a correct value
}