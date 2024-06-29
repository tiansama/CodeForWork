#include<iostream>



int clen(const char* str) {
	int i;
	for (i = 0; str[i]; i++) {
	}
	return ++i;  //包含\0的字符串长度
}


char* cstr(const char* str) {
	//apply a string
	int len = clen(str);
	char* str_test = new char[len]; //局部变量到cstr就结束了   这一段在堆区所以不会释放
	//指针千万不要返回局部变量
	memcpy(str_test, str, len);
	return str_test;
}

typedef struct Role{
	char* name;
	int HP;
	int MP;
}*PROLE,ROLE;


ROLE createmonster(const char* str,int hp,int mp) {
	Role rt{ cstr(str), hp, mp };
	return rt;
}


PROLE createhero(const char* str, int hp, int mp) {
	PROLE hero = new Role{ cstr(str), hp, mp };
	return hero;
}

ROLE& createtest(const char* str, int hp, int mp) {
	PROLE testt = new Role{ cstr(str), hp, mp };
	return *testt;
}


void ave(int(&b)[100]) {
	std::cout << sizeof(b) << std::endl;
	//可以用auto
}
int main() {
	//!!!!!!!!!!!!!!!!!!!指针不能返回局部变量!!!!!!!!!!!!!!!!!!!
	char* str;  //字符指针
	str = cstr("123123");
	std::cout << str << std::endl;

	ROLE role1 = createmonster("automan", 100, 1000);  //一般来说不用实体，内存开销过大
	std::cout << role1.HP << std::endl;
	std::cout << role1.MP << std::endl;


	PROLE hero = createhero("mm", 1000, 100);
	std::cout << hero->HP << std::endl;

	//利用引用   利用引用传递参数，必须要确定传递的类型（隐式的类型转换
	ROLE& test = createtest("aaa", 123, 321);
	std::cout << test.HP << std::endl;
	std::cout << test.MP << std::endl;

	//数组的引用
	int a[100];
	int(&b)[100] = a;  //!!!!!!!!!!!
	b[0] = 1000;
	ave(a);
	std::cout << a[0]<< std::endl;
	return 0;
}