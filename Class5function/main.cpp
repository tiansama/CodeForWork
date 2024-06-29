#include<iostream>
#include<string>
#include<sstream>


//函数
//指针参数

struct role {
	int hp;
	int mp;
};

int add(int* a, int* b) {
	int c;
	c = *a + *b;
	return c;
}

int exp(role* rl) {
	return rl->hp + rl->mp;
}


//数组参数
void sort(int a[], int count) {

	for (int i = 1; i < count; i++){
		for (int i = 1; i < count; i++){
			if (a[i] > a[i - 1])
			{
				int tmp = a[i];
				a[i] = a[i - 1];
				a[i - 1] = tmp;
			}
		}
	}
}


//引用参数   阉割指针
//int a = 5;
//int& b = a;
//区别：！！！！！指针可以传入nullptr，但是引用不行！！！！！


bool act(const role& user) {  //常量引用
	return 1;
}

//默认实参
//只有几个选项 e.g bool bigsort = true;  注意默认参数只能放在最后

//不定量参数
//参数个数，程序的路径及文件名   最后的一个是空指针
int main(int argcount,char* c_arg[]) {
	int x = 100;
	int y = 1000;
	int result = add(&x, &y);
	std::cout << result << std::endl;

	role rl{ 1,2 };
	int d = exp(&rl);
	std::cout << d << std::endl;


	int a[]{ 64, 34, 25, 12, 22, 11};
	sort(a,6);
	for (auto x : a)
		std::cout << x << std::endl;


	role user{ 1,2 };
	act(user);



	return 0;
}