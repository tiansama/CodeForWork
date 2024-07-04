#include<iostream>

/*
角色类
属性：
生命值
最大生命值
方法：
吃药


药物类
属性：
能够恢复的生命值
*/
class medical {
	int heal{ 2000 };
	friend class Role;
};


class Role {
	int Hp;
	int MaxHp;
public:
	Role() {
		Hp = 1500;
		MaxHp = 3000;
	}
	void healing(medical& medi) {
		std::cout << "Hp:" << Hp << std::endl;
		Hp += medi.heal;
		if (Hp > MaxHp) {
			Hp = MaxHp;
		}
		std::cout <<"Hp after healing:"<< Hp << std::endl;
	}
};


class Person {
	friend bool operator<(Person& p1, Person& p2);
	unsigned short Age;
public:
	Person(unsigned short _Age) :Age{ _Age } {};

	bool operator>(Person& p3);
	//{
	//	return Age > p3.Age;
	//}
};
//写在类外需要加上作用域
bool Person::operator>(Person& p3) {
	return Age > p3.Age;
}

//bool IsSmaller(Person& p1, Person& p2) {
//	return p1.Age < p2.Age;
//}


//重载运算符
//非类的成员函数实现
bool operator<(Person& p1, Person& p2) {
	return p1.Age < p2.Age;
}

int main() {
	Role user;
	medical lingyao;
	user.healing(lingyao);

	Person man(50);
	Person woman(20);
	//if man is younger than woman
	if (man<woman) std::cout << "yes1" << std::endl;
	if(man>woman) std::cout << "yes2" << std::endl;
	return 0;
}