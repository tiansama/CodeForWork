#include<iostream>

#include"studentsign.h"

void studentsign() {
	int id[100]{};
	int indexID{};  //初始化
	while (indexID < 100) {
		std::cout << "Please input your student ID: if input=0,check all the information";
		std::cin >> id[indexID];
		if (id[indexID] == 0) {
			//system("cls");
			for (int i = 0; i < indexID; i++) {
				std::cout << id[i] << std::endl;
			}
		}
		else {
			indexID++;
		}
	}
}