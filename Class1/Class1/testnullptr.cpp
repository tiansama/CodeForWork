#include <iostream>
using namespace std;

int testptr()
{
	int* ptr = nullptr;
	int a = 100;
	ptr = &a;
	cout << "The value of a is " << *ptr << endl;
	cout << "The address of a is " << ptr << endl;
	return 0;
}