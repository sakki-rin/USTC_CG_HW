#include <iostream>
#include "DArray.h"

using namespace std;

int main()
{
	CDArray a;
	a.InsertAt(0, 2.1);
	a.Print();

	a.PushBack(3.0);
	a.PushBack(3.1);
	a.PushBack(3.2);
	a.Print();

	a.DeleteAt(0);
	a.Print();
	a.InsertAt(0, 4.1);
	a.Print();

	CDArray b;
	b.PushBack(21);
	b.Print();
	b.DeleteAt(0);
	b.Print();
	b.PushBack(22);
	b.SetSize(5);
	b.Print();

	CDArray c(5, 3.4);
	c.PushBack(5.5);
	c.Print();
	c.SetSize(10);
	c.Print();

	c = a;
	c.Print();

	cout << c[0] << endl;

	return 0;
}