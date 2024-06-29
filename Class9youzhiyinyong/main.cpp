#include<iostream>

void add(int&& a) {
	std::cout << a << std::endl;;
}


struct role {
	int hp;
	int mp;
};

role create() {
	role rl{ 1,2 };
	return rl;  //生命周期
}

void show(role&& rl) {
	std::cout << rl.hp << std::endl;   //
}


//函数的本质




int main() {

	int c = 1 + 2;
	//右值引用
	//int&& b = c;
	int&& b = 320+300;  //目的指向临时的数 但是不能写入

	add(c + 320 + 300);

	//临时用 可以用右值引用
	show(create());
	return 0;
}