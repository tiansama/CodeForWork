#include<iostream>

class Role {
public:
	int hp;
	int mp;
	//编译器默认
	Role& operator=(const Role& role); /*{
		hp = role.hp;
		mp = role.mp;
		return *this;
	};*/
	//Role& operator=(const Role& role) = delete;
};

Role& Role::operator=(const Role& role) {
	hp = role.hp;
	mp = role.mp;
	return *this;
}

//为什么需要返回*this
//避免x=y=z无法实现  而且内存开销比较小

class hstring {
	unsigned short usmlen; //用于记录内存长度，缓冲区

	unsigned short uslen;  //字符串长度
	char* cstr;  //字符串的内容  当你的成员变量有指针的时候


	unsigned short getlength(const char* str) const; //获取长度

	void copystrs(char* dest, const char* source); //代码复用问题
public:
	char* c_str() {
		return cstr;
	}
	hstring();
	hstring(const char* str);  //利用c字符来构造hstring
	hstring(const hstring& str); //副本构造函数

	hstring& operator=(const hstring& str); //声明
};
//done  缓冲区
hstring::hstring() {
	usmlen = 0x32;
	uslen = 0;
	cstr = new char[usmlen];
}

unsigned short hstring::getlength(const char* str) const {
	unsigned short len = 0;
	for (; str[len++];);
	return len;
}

void hstring::copystrs(char* dest, const char* source) {
	unsigned short len = getlength(source);
	if (len > usmlen) {
		cstr = new char[len];
		usmlen = len;
	}
	memcpy(cstr, source, len);
	uslen = len; //字符串长度修正

}
//复制操作
hstring::hstring(const char* str) :hstring() {   //强制类型转换
	copystrs(cstr, str);
}

hstring::hstring(const hstring& str) :hstring() {
	copystrs(cstr, str.cstr);
}

hstring& hstring::operator=(const hstring& str) {  //不需要写char* str，会有强制类型转换
	copystrs(cstr, str.cstr);
	return *this;
}

int main() {
	char strA[]{ "abbbbbbcccc" };
	hstring str{ strA }; //此时调用的副本构造函数
	hstring str1{ str };
	hstring str2{ "hello" };
	strA[0] = 0;
	std::cout << str.c_str() << std::endl;;
	std::cout << str1.c_str();

	str1 = str2;
	std::cout << str1.c_str();

	return 0;
}