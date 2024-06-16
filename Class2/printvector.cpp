#include<iostream>
#include<vector>
#include<array>
#include<string>
#include<sstream>

#include"printvector.h"

void printvector() {
	int studentID[10];
	std::vector<int> studentID2(5);
	std::array<int, 10> studentID3{};

	std::string inputline;
	std::getline(std::cin, inputline);

	std::istringstream stream(inputline);   //解析字符串

	for (int i = 0; i < 10; i++) {
		stream >> studentID[i];
	}

	for (int i = 0; i < 10; i++) {
		std::cout << studentID[i] << std::endl;
	}
}