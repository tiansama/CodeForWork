#include<iostream>

class wolf {
public:
	//构造函数
	wolf() {

	}

	void growup1() {
		std::cout << "lv1\n";
	}
	void growup2() {
		std::cout << "lv2\n";
	}
	void growup3() {
		std::cout << "lv3\n";
	}
};


typedef void(wolf::*pgrow)();  //声明作用域

int main() {
	pgrow p = &wolf::growup1;
	
	wolf* pwolf = new wolf();
	(pwolf->*p)();
}