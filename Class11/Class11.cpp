#include<iostream>

int ave(int a, int b) {
	a += 250;
	return a + b;
}

int add(int a, int b) {
	int c = 250;
	int d = ave(a, b);
	c = c + d;
	return c;
}

int main() {
	std::cout << add;
	int x = add(250, 100);
	return 0;
}
//eax 栈顶 ebp 栈底
//push指令分两步-》第一步先地址-4，再放入
//call指令 还是先地址-4，再把下一条指令的地址放入当前位置

//堆栈溢出攻击