#include<iostream>
#include"refer.h"
void refer() {
	int a{ 500 };
	int& la{ a };
	la = 5000;
	std::cout << a << std::endl;
}