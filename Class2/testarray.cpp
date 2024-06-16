#include<iostream>
#include<array>
#include"testarray.h"
//容器  数组+额外功能
void testarray (){
	std::array<int, 3> arr{1,2,3};
	std::cout << arr.size() << std::endl;
	for (auto i : arr) {
		std::cout << i << std::endl;
	}
	arr.fill(999);
	for (auto i : arr) {
		std::cout << i << std::endl;
	}
	arr[0] = 100;
	std::cout << arr.at(0) << std::endl; //!!!从0开始
}