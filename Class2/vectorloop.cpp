#include<iostream>
#include"vectorloop.h"
void vectorloop() {
	int fortest[]{ 1,2,3,4,5,6 };
	for (auto a : fortest) {
		std::cout << a << std::endl;
	}
}