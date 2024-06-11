#include <iostream>
#include "compare.h"
using namespace std;

void compare()
{
	int a;
	int b;
	cout<<"Enter the value of a: ";
	cin>>a;
	cout<<"Enter the value of b: ";
	cin>>b;
	if (a > b) {
		cout << "a is greater than b" << endl;
	}
	else if (a == b) {
		cout<< "a is equal to b" << endl;
	}
	else {
		cout << "b is greater than a" << endl;
	}
	return;
}