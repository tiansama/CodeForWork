#include<iostream>
#include<string>
#include<locale>

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



	// unique_ptr
	// make_unique<int>(5)    make_unique<int[]>(5){1,2,3,4,5}  创建
	// get  必须用裸指针接收  因为get返回的是它的裸指针    //通过修改裸指针从而达到修改unique的目的
	// move 是将这个unique的所有权分享给另一个unique，所以需要用智能指针接收
	// release是把当前内存空间分给另外一个裸指针，用裸指针来接收
	// reset则是释放内存，并且把指针置空
	int* a = new int{ 5 };
	delete a;
	std::unique_ptr<int> testptr{new int(5)};
	//std::unique_ptr<int[]> testptr{ std::make_unique<int[]>(5) };
	std::cout << *testptr << std::endl; 

	a = testptr.get();  //返回个原始指针(裸指针）  所有权不变，但是值可以修改

	*a = 10;
	std::cout << *testptr << std::endl;

	//testptr.reset(); //释放内存，地址指向0
	//release 把指针设为一个空值，但是不释放内存空间
	std::cout << testptr << std::endl;
	std::unique_ptr<int> testptr2{};
	testptr2 = std::move(testptr);
	//std::cout << testptr << std::endl;
	std::cout << testptr << std::endl;
	//std::cout << *testptr << std::endl; //undefined behavior
	std::cout << &testptr2 << std::endl;
	std::cout << testptr2 << std::endl;
	std::cout << *testptr2 << std::endl;

	int* testrelease = testptr2.release(); //此时ptr2的内存分给了testrelease，本身设为nullptr
	std::cout << "testrelease's address" << testrelease << std::endl;
	std::cout << "testrelease value(should be 10)" << *testrelease << std::endl;

	std::cout << &testptr2 << std::endl;  //所占的内存没有释放，但是内部已经为00000000

	delete testrelease;
	testrelease = nullptr;


	std::unique_ptr<int> testptr3{ std::make_unique<int>(5)};
	testptr3.reset();
	std::cout << testptr3 << std::endl;




	//test release   take care dont use it !!!!!!
	// 
	//std::unique_ptr<int> ptr4 = std::make_unique<int>(42);
	//int* rawPtr = ptr4.release();
	//std::unique_ptr<int> ptr5(rawPtr);
	//*rawPtr = 44;
	//std::cout << *ptr5 << std::endl;

}


void sharedpoint() {
	//method
	//recording how many pointer are using this memory    .use_count()
	//return a bool value->if this pointer is the only owner, return true ,or return false  ！！！！！！！！！！C++17取消了！！！！！！！
	//reset 只有是最后一个释放才会真正释放内存，否则只是把这个指针变成nullptr
	std::shared_ptr<int> sptr{std::make_shared<int>(5)};    //make_shared不支持数组类型生成

	std::shared_ptr<int[]> sptr1{ new int[5] {1,2,3,4,5} };


	std::shared_ptr<int> sptrb{ sptr };

	std::cout << sptr1[1] << std::endl;
	std::cout << *sptr << std::endl;
	std::cout << *sptrb << std::endl;
	//最后一个释放才会释放内存空间
	//可以记录有多少个指针指向这个内存空间
	std::cout << sptr.use_count() << std::endl;

	sptr.reset();
	std::cout << sptrb.use_count() << std::endl;
	std::cout << sptr << std::endl;
}

void teststring() {
	//连续的内存空间
	//std::string str;
	//getline(std::cin, str);
	//std::cout << str << std::endl;

	char str[0xFF]{ "Hello" };
	std::cout << str << std::endl;
	char* stra = (char*)"Hello";
	std::cout << stra << std::endl;

	char* strb = new char[255] {"hello"}; //一定要设定char里的大小

	//std::cout << "张三" << std::endl;
	//宽体	
	setlocale(LC_ALL, "chs");
	wchar_t wstr[0xFF]{ L"hello张三" };
	std::wcout.imbue(std::locale("chs"));
	std::wcout << wstr << std::endl;
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
	//smartpoint();
	//sharedpoint();
	teststring();
	return 0;
}