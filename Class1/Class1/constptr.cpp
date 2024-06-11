#include <iostream>
using namespace std;

int ptrtest()
{
	int a = 10;
	int b = 10;
	
	const int* p;
	p = &a;
	cout << p << endl;
	p = &b;
	cout << p << endl;
	return 0;
}