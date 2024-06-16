#include<iostream>
#include"testpoint2.h"
//操作ptr的内存
//指针也是个变量
//&a[0]一定要存了才能操作
void testpoint2() {

	int a[]{ 1,2,3,4,5 };
	int* ptr{ &a[0] };

	int** pptr{ &ptr };

	std::cout << *ptr << std::endl;

	std::cout << pptr << std::endl;
	std::cout << *pptr << std::endl;
	std::cout << **pptr << std::endl;

}