#include<iostream>

class animal {
public:
	int age;
};

class people:public animal {
public:
	int money;
};

#include<iostream>
//基类
class moveobj {
public:
    int x;
    int y;

    virtual void move() {  //虚函数：在基类中使用 virtual 关键字声明，允许派生类重写，实现运行时多态性。
        x++;
        y++;
    }
};

//派生类
class NPCobj :public moveobj {
public:
    void move() {
        y++;
        x++;
        std::cout << "im NPC" << std::endl;
    }
};

class Monsterobj :public moveobj {
public:
    void move() {
        x++;
        y++;
        std::cout << "im monster" << std::endl;
    }
};

void move(moveobj* obj) {  //只能用基类指针实现
    obj->move();
}  //此时什么都不显示，因为是编译器确定好的


//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!这里已经是对象在使用了而不是指针在使用   如果使用对象，就表明其实是内存切片后
//! 变成了一个真正的moveobj，如果是在要用 obj.move，那么使用引用 moveobj& obj
//void move(moveobj obj) { 
//    obj.move();
//}

int main() {
    Monsterobj snake;
    NPCobj king;

    move(&snake);
    move(&king);
}
