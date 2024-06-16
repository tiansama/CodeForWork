#include<iostream>
#include"defpoint.h"
//数据类型* 变量名称
void defpoint() {
	/*int* StudentID{};
	std::cout << &StudentID << std::endl;
	std::cout << StudentID << std::endl;*/
	int a = 5000;
	std::cout << &a << std::endl;

	int* pa = &a;
	std::cout << pa << std::endl;
	std::cout << &pa << std::endl;
	std::cout << *pa << std::endl;
}