#include<iostream>

int add(int a, int b) {  //其实在这里就是一个指针
	return a + b;
}
//using release mode

typedef char(*p)(int, int);   //声明一个函数指针类型
using pfadd = char(*)(int, int);

int main() {
	int c = add(3, 4);
	std::cout << c << std::endl;


	char* str = (char*)add;
	for (int i = 0; i < 30; i++) {
		printf("%02X\n", (unsigned char)str[i]);   //前两位是控制程序的运行   函数本质上是存给CPU的指令  存内存地址
	}

	//函数指针

	int (*padd)(int a, int b) = add; //本质是一个指针
	
	char (*tadd)(int, int) = (char(*)(int, int))add;  //这里可以用p代替，因为已经声明过了 tadd也可以用p tadd来代替

	std::cout << padd(1, 2) << std::endl;

}