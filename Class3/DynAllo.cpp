//动态分配
#include<iostream>
#include"dynalloc.h"
void dynallo() {
	unsigned x;
	std::cin >> x;
	//void * malloc(size_t size);
	int* ptr = (int*)malloc(x * sizeof(int));  //malloc返回的只是个void*
	int* pc{};
	pc = (int*)calloc(x, sizeof(int));

	std::cout << pc[0] << std::endl;


	ptr[0] = 9;
	ptr[1] = 10;
	ptr[2] = ptr[0] * ptr[1];
	std::cout << ptr << std::endl;
	std::cout << ptr[1] << " " << ptr[2] << std::endl;

	ptr = (int*)realloc(ptr, 1000);
	std::cout << ptr << std::endl;
	
	free(ptr);

	ptr = nullptr;
	

	int* pa = new int[10];
	pa[0] = 100;
	std::cout << pa[0] << std::endl;
	delete[] pa;
	pa = nullptr;
	//频繁申请释放可能会导致内存碎片

	//复制内存
	/* memcpy 
	void* memcpy(dst,const src ,size_t)   把src复制给dst，长度为size
	*/
	int a[5]{ 1,2,3,4,5 };
	int* b = new int[5];

	memset(b, 0, 5 * sizeof(int)); //字节  第二个位置是把每个字节设为某一个值
	std::cout << b[0] << std::endl;
	memcpy(b, a, 5*sizeof(int)); //字节
	std::cout << b[0] << std::endl;
}