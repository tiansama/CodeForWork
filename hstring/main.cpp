#include<iostream>
#include<cstring>

class hstring {
private:
	char* c_str;
	unsigned short len;
	
	unsigned short lenth(const char* str) {
		unsigned short len{};
		while (str[len++]);
		return len;
	};
public:
	hstring() {
		len = 1;
		c_str = new char[1] {0};
	}

	hstring(const hstring& hstr):hstring(hstr.showstr()) {  //副本构造函数

	}

	hstring(const char* str) {
		len = lenth(str);
		c_str = new char[len];
		memcpy(c_str, str, len);
	}

	char* showstr() const{
		return c_str;
	}

	~hstring() {
		std::cout << "bye" << std::endl;
		delete[] c_str;
	}
};

//功能
//hstring str("你好！"）; //构造函数
//hstring strA（str); //副本构造函数

int main() {
	hstring str{"hello"};
	hstring strA(str);
	std::cout << str.showstr() << std::endl;
	std::cout << strA.showstr() << std::endl;
}