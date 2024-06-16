#include<iostream>
#include<vector>
#include"testvector.h"
void testvector() {
	std::vector<int> vec(5,3);
	for (auto i : vec) {
		std::cout << i << std::endl;
	}
	std::cout << vec.size() << std::endl;
	std::cout << vec.at(1);
	std::cout << vec[2];

	std::cout << vec.empty() << std::endl;
	vec.assign(10, 5);
	for (auto i : vec) {
		std::cout << i << std::endl;
	}
	vec.clear();
	std::cout << vec.empty() << std::endl;
}