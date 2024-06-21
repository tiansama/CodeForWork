#include<iostream>
#include<string>
#include<sstream>
void teststring() {
	std::string teststr;
	teststr = "hello world";

	teststr = teststr.substr(1);
	std::cout << teststr << std::endl;


	//to_string
	std::string tstr2 = teststr + std::to_string(123);

	std::cout << tstr2 << std::endl;
	//+运算优先级大于+=
	//如果前面define也可以   #define 某某某 “123”
	//append 拼接 str.append("123"); 可以嵌套到循环,可以在append里截取 str.append("123",1);
	//substr(1) 初始位置全部截取   substr(1,3); 从1开始截取3位
	//本质像一个数组->str[0]  不支持中文


	//compare  返回一个int类型的值
	std::string stra = { "abcd efg" };
	int a = stra.compare(4, 3, " ef");
	std::cout << a << std::endl;
	

	//字符串的搜索
	std::string strs{ "student56" };
	std::string student;
	student = strs.substr(strs.find("student")+strlen("student"));
	std::cout << student;
	//搜索内容，起始位置，搜索长度  没搜到会返回-1（npos）
	//str.find("....")  搜索的内容
	//str.find("...",int)  搜索的内容和开始位置
	//stt.find("...",int,int)   搜索的内容 开始位置 截取的长度

	//insert 插入
	//insert(插入的位置，个数，字符）
	std::string stri = { "abcd" };
	stri.insert(2,6,'e');
	stri.insert(2, 6, 'f');
	std::cout << stri << std::endl;
	//insert(插入位置，插入的字符串，要插入字符串从哪截取，截取多长）
	//insert(插入位置，插入的字符串，截取多长）从开头截取
	stri.insert(2, "abcdefghijk", 1, 3);
	std::cout << stri << std::endl;

}


void teststring1(){
	std::string str{ "abc" };
	std::cout << (int)&str << " " << (int)&str[1] << std::endl;;   //能动态分配的   //str跟数组不一样
	//str.c_str()返回的是常量指针  也就是说&str里存的是第一位的地址

	//data的方法 str.data()   C++17更新，data返回的不是常量指针了，正常读写
	//replace
	//replace（要替换内容起始位置，要替换长度，替换后内容）
	//replace(起始位置，替换长度，替换后的字符长度，替换的字符）！！！！！！注意是’字符‘
	str.replace(1, 2, "cccc");
	str.replace(1, 3, 6, '*');
	std::cout << str << std::endl;
	str.erase(3, 2);
	std::cout << str << std::endl;

	//字符-》编码表-》二进制

}

void testinput() {
	//std::string str;
	//std::cin >> str;

	//int length{ 0 };
	//for (int i = 0; str[i]; i++) {
	//	if (str[i] < 0) {
	//		i++;
	//	}
	//	length++;
	//}
	//std::cout << length << std::endl;

	//std::to_string(num) 数字变字符
	//std::stoi(string)-> 字符变成数字  .str是提取里面的内容返回一个string
	std::stringstream str1;
	str1 << "你好" << 123;
	std::string str3 = str1.str();
	std::cout << str3 << std::endl;
}


int main() {
	//char str[0xFF] = "123";
	//char str2[0xFF] = "456";
	//char str3[0xFF];
	//memcpy(str3, str, strlen(str));
	//memcpy(str3 + strlen(str), str2, strlen(str2)+1);  //这个+1很重要，不加1则会没有\0导致后续乱码
	//std::cout << str3;
	std::string str{ "test string 你好" };
	std::cout << str << std::endl;   

	//teststring();
	//teststring1();
	testinput();
	return 0;
}