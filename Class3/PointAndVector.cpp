#include<iostream>
#include"PointAndVector.h"

void pointandvector(){

	//如何实现数组
	int a[5];
	int* ptr{ a + 1 };

	a[0] = 5;
	a[1] = 2000;
	a[2] = 3000;


	std::cout << &a << std::endl;
	std::cout << ptr << std::endl;
	std::cout << ptr[1] << std::endl;

	int test[2][5]{
		{1,2,3,4,5},
		{6,7,8,9,10}
	};

	int* ptesta[5]; //指针数组
	int(*ptestb)[5] {test}; //数组指针，意思是是一个指针，但是指向的数组，而且每个是五个

	std::cout << ptestb[1][3] << std::endl;
}