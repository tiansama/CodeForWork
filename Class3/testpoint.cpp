#include<iostream>
#include"testpoint.h"
int testpoint() {
	int a[]{ 1,2,3,4,5 };
	int* ptr{ &a[0] };

	std::cout << ptr << std::endl;

	//std::cout << *ptr++ << std::endl;  //first show the *ptr then add one  指针+1的时候加的是它的1*size  //ptr位置变化，值不变
	std::cout << (*ptr)++ << std::endl;   //ptr位置不变，但是值增加
	std::cout << a[0] << std::endl;
	std::cout << a[1] << std::endl;

	std::cout << ptr << std::endl;


	std::cout << *ptr << std::endl;

	return 0;
}