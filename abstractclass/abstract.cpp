#include<iostream>

/*
纯虚函数
抽象类
接口类


virtual void move() = 0;    这个就是纯虚函数


有纯虚函数的类叫抽象类   不能创建实例   但是可以创建指针，用于函数的参数或者返回


*/

class animal {
	//一般构造函数写成protcted
	void virtual move() = 0;  //纯虚函数
};

class dog :public animal {
	void virtual move() {

	}
};

class cat :public animal {
	void virtual move() {

	}
};