#include <iostream>

class Outer {
public:
    class Nested {
    public:
        Nested(int val) : privateVar(val), publicVar(val) {}

        void display() {
            std::cout << "Nested::display called" << std::endl;
        }

    private:
        int privateVar;
    protected:
        int protectedVar;
    public:
        int publicVar;
    };

    void accessNestedMembers(Nested& nested) {
        // 可以访问嵌套类的所有成员 不可以！！！！！！！
        //std::cout << "Nested::privateVar = " << nested.privateVar << std::endl;
        //std::cout << "Nested::protectedVar = " << nested.protectedVar << std::endl;
        std::cout << "Nested::publicVar = " << nested.publicVar << std::endl;
        nested.display();
    }
};

int main() {
    Outer::Nested nested(42);
    Outer outer;
    outer.accessNestedMembers(nested);

    return 0;
}