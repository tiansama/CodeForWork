#include<iostream>

int ave(int a, int b) {
	return (a + b) / 2;
}

int ave(int a, int b, int c) {
	return(a + b + c) / 3;
}

float ave(float a, float b, float c) {
	return (a + b + c) / 3;
}

auto aaa(int a, int b) {
	return a + b;
}


int main() {
	std::cout << ave(1, 2) << std::endl;
	std::cout << ave(1, 3, 5) << std::endl;
	std::cout << ave(1.1f, 1.2f, 1.3f) << std::endl;

	int a{ 1 }, b{ 2 };
	decltype(aaa(1, 2)) x;
	return 0;
}

//需要不同的参数列表
//不能通过返回类型判断