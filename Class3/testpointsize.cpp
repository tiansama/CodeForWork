#include<iostream>
#include"testpointsize.h"

void testpointsize() {
	// 初始化指针
	int* ptr = nullptr;

	int a = 10;
	int* ptr1 = &a;

	int* ptr2 = new int(10);

	std::cout << sizeof(ptr) << std::endl;
	std::cout << sizeof(ptr1) << std::endl;

	delete ptr2;
	ptr2 = nullptr;
}