#include<iostream>
#include"constpoint.h"


void constpoint() {
	//常量指针
	const int a = 5000;
	const int b = 3000;
	const int* ptr1{ &a };
	ptr1 = &b;  //“值不能改”指的是不能直接*ptr = 500，但是地址能改
	std::cout << *ptr1 << std::endl;


	//指针常量
	int c = 3000;
	int d = 1000;
	int* const ptr{ &c };

	*ptr = d;
	std::cout << &c << std::endl;
	std::cout << ptr << std::endl;
	std::cout << *ptr << std::endl;   //值能改，但是地址不能改

	//const 变量类型* const

}