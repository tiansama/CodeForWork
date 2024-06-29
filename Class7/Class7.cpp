#include<cstdarg>
#include<iostream>


float average(int count,...) {
	va_list  arg;     //本质是char类型的指针  char*
	va_start(arg, count);  //这一步是内存分配
	int sum = 0;
	for (int i = 0; i < count; i++) {
		int x = va_arg(arg, int);
		sum += x;
	}
	va_end(arg);
	float result = (float)sum / count;
	return result;
}

void main() {
	float x = average(5, 1, 2, 3, 4, 5);
	std::cout << x << std::endl;
}