#include<iostream>

class moveobj {
public:
	int x;

	virtual void test() {};//动态类型转换需要虚函数
};

class monsterobj :public moveobj {

};


class npcobj :public moveobj {

};


class wolf :public monsterobj {

};

class man :public monsterobj {

};

class wolfman :public wolf, public man {

};

int main() {
	//monsterobj monster;
	//moveobj* _move = (moveobj*) & monster;  //隐式类型转换 向上转型

	//monsterobj* _pmonster = _move;  //  不可以转换，如果向下转型可能出现问题  向下转型不允许

	//monsterobj* _pmonster = (monsterobj*)_move;  //强制类型转换  可以

	//monsterobj* _pmonster = static_cast<monsterobj*> (_move);   //条件：基类必须是可以访问的   如果是虚基类，也不行


	//wolfman wm;
	//void* ptr = &wm;
	//wolf* pw = (wolf*)ptr;
	//man* pm = (man*)ptr;
	//结果不一样，前面三个是一样的
	//wolf* pw = (wolf*)&wm;
	//man* pm = (man*)&wm;  //后面两个不一样
	//多重继承不能强制类型转换



	//wm.wolf::monsterobj::moveobj::x = 2500;

	//_move = static_cast<moveobj*>(&wm);
	monsterobj monster;
	moveobj* _move = (moveobj*)&monster;  //隐式类型转换 向上转型
	//_move = new moveobj();
	monsterobj* _pmonsterA = dynamic_cast<monsterobj*>(_move);
	if (_pmonsterA == nullptr) {
		std::cout << "fail\n";
	}
	else {
		std::cout << "success";
	}

}