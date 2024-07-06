#include<iostream>

class moveobj {
	virtual void test(){}
};

class monster :public moveobj {

};
int main() {
	//int a;
	//std::cout << typeid(a).name();

	moveobj* _move = new moveobj();
	_move = new monster();

	std::cout << typeid(*_move).name();
}