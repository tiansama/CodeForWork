#include<iostream>

//基类
class moveobj {
public:
    int x;
    int y;
    virtual void move() {
        std::cout << "moveobj\n";
    }

    virtual void automove(int step = 2) {
        std::cout << "auto move" << step << std::endl;
    }

    void test() {
        this->move();   //this->move();
    }

    virtual ~moveobj() {
        std::cout << "~obj\n";
        this->move();
    }
};

//派生类
class NPCobj :public moveobj {
private:
    void move() override{
        std::cout << "im NPC" << std::endl;
    }
};

class Monsterobj :public moveobj {
public:
    void move() override{
        std::cout << "im monster" << std::endl;
    }

    void automove(int step = 1010) override{
        std::cout << "monster auto move" << step << std::endl;
    }
public:
    ~Monsterobj() {
        std::cout << "~monster\n";
        move();
    }
};

//void move(moveobj* obj) {
//    obj->move();
//}



int main() {
    //Monsterobj snake;
    //snake.test();
    moveobj* p = new Monsterobj();
    p->automove();
    delete p; //!!!!!!!!!!!很有问题，只会释放基类，并没有释放派生类   所以需要虚析构


}
