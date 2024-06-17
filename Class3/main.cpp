#include<iostream>
#include"defpoint.h"
#include"testpointsize.h"
#include"testpoint.h"
#include"testpoint2.h"
#include"constpoint.h"
#include"PointAndVector.h"
#include"dynalloc.h"
#include"refer.h"

void sortmethod() {
	int vec[]{ 1,3,5,7,9,11,13 };
	int vec1[]{ 13,11,9,7,5,3,1 };
	int x = 0;
	std::cin >> x;

	int size = sizeof(vec) / sizeof(int);
	int getindex{ size };
	int* vec3 = new int[size + 1];
	if (vec[0] < vec[1]) {   //升序
		for (int i = 0; i < size; i++) {
			if (x < vec[i]) {
				getindex = i;
				break;
			}
		}
	}

	if (vec[0] > vec[1]) {  //降序
		for (int i = 0; i < size; i++) {
			if (x > vec[i]) {
				getindex = i;
				break;
			}
		}
	}
	std::cout << getindex << std::endl;

	memcpy(vec3, vec, getindex * sizeof(int));
	memcpy(vec3 + getindex + 1, vec + getindex, (size - getindex)*sizeof(int));

	vec3[getindex] = x;
	for (int i = 0; i < size + 1; i++) {
		std::cout << vec3[i] << std::endl;
	}
}


void smartpoint() {
	//unique_ptr  唯一智能指针
	//shared_ptr
	//weak_ptr
	int* a = new int{ 5 };
	delete a;
	std::unique_ptr<int> testptr{new int(5)};
	//std::unique_ptr<int[]> testptr{ std::make_unique<int[]>(5) };
	std::cout << *testptr << std::endl; 

	a = testptr.get();  //返回个原始指针  所有权不变，但是值可以修改

	*a = 10;
	std::cout << *testptr << std::endl;

	//testptr.reset(); //释放内存，地址指向0
	//release 把指针设为一个空值，但是不释放内存空间
	std::cout << testptr << std::endl;
	std::unique_ptr<int> testptr2{};
	testptr2 = std::move(testptr);
	//std::cout << testptr << std::endl;
	std::cout << testptr2 << std::endl;
}

int main() {
	//defpoint();
	//testpointsize();
	//testpoint2();
	//constpoint();
	//pointandvector();
	//dynallo();
	//refer();
	//sortmethod();
	smartpoint();
	return 0;
}