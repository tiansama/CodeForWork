#include<iostream>
#include<cstring>

class hstring {
private:
	char* buffer; //用做缓冲区
	size_t capa;  //capacity 记录缓冲区大小
 
	size_t size; //字符串大小

	size_t GetLength(const char* str) const{  //判断输入字符串的长度
		size_t length = 0;
		while (str[length] != '\0') {
			length++;
		}
		return length;
	}

	void IsExceedBuffer(size_t curlength) {
		if ( curlength>= capa) {  //此处要等于，因为加上的位置还没有计算\0
			size_t new_capa = 2 * capa > curlength ? 2 * capa : curlength * 2;
			char* new_buffer = new char[new_capa];
			std::memcpy(new_buffer, buffer, size);
			delete[] buffer;
			buffer = new_buffer;
			capa = new_capa;
			//此处没改length
		}
	}

public:
	//如果没有输入，只是初始化一个实例
	hstring() :buffer(new char[1]), capa(1), size(0) {
		buffer[0] = '\0';
	}

	//有输入，构造函数，先分配一定大小的空间给缓冲区
	hstring(const char* str){
		//先计算输入的长度
		size = GetLength(str); //记录字符串长度
		capa = 2 * size; //初始化为输入的两倍，避免过多调用new开辟空间
		buffer = new char[capa];
		std::memcpy(buffer, str, size);  //拷贝字符串
		buffer[size] = '\0'; //字符串末尾为0
	}

	~hstring() {
		delete[] buffer; //析构 释放空间
	}

	//重载+运算符
	hstring& operator+(const char* str2) {
		//new之前需要判断是否超过缓冲区
		size_t str2length = GetLength(str2); //获取加入的字符串长度
		IsExceedBuffer(size + str2length); //此时加入成功需要更新新的length
		//append
		std::memcpy(buffer + size, str2, str2length);
		size += str2length;
		buffer[size] = '\0';
		return *this;
	}

	//重载-运算符
	hstring& operator-(const char* str3) {
		size_t str3length = GetLength(str3);
		if (size < str3length) {
			std::cout << "Illegal string operation" << std::endl;
			return *this;
		}
		int index = -1;
		for (size_t i = 0; i + str3length <= size; i++) {
			bool test = true;
			for (size_t j = 0; j < str3length; j++) {
				if (buffer[i + j] != str3[j]) {
					test = false;
				}
			}
			if (test) {
				index = i;
				break; //找到了起始位置
			}
		}
		if (index != -1) {
			for (size_t i = index; i + str3length < size; ++i) {
				buffer[i] = buffer[i + str3length];
			}
			size -= str3length;
			buffer[size] = '\0';
		}else {
			std::cout << "Substring not found." << std::endl;
		}
		return *this;
	}

	//replace
	void replace(const char* target, const char* rstr) {  //需要被替换的和替换字符串
		//第一步找到target的位置
		size_t tlength = GetLength(target);
		if (size < tlength) {
			std::cout << "Illegal string operation" << std::endl;
			return;
		}
		int index = -1;
		for (size_t i = 0; i + tlength <= size; i++) {
			bool test = true;
			for (size_t j = 0; j < tlength; j++) {
				if (buffer[i + j] != target[j]) {
					test = false;
					break;
				}
			}
			if (test) {
				index = i;
				break; //找到起始位置
			}
		}
		//替换
		size_t rlength = GetLength(rstr);
		size_t newsize = size - tlength + rlength;
		if (index != -1) {
			IsExceedBuffer(newsize);
			//如果两者长度不一样需要
			if (rlength != tlength) {
				for (size_t i = size; i >= index + tlength; i++) {
					buffer[i + rlength - tlength] = buffer[i];
				}
			}
			//补齐
			for (size_t i = 0; i < rlength; i++) {
				buffer[index + i] = rstr[i];
			}
			size = newsize;
			buffer[size] = '\0';
		}
		else {
			std::cout << "Substring not found." << std::endl;
		}
	}

	//find 
	int find(const char* fstr) const { //此处没有更改内容
		size_t flength = GetLength(fstr);
		if (size < flength) {
			std::cout << "Substring not found" << std::endl;
		}
		int index = -1;
		for (size_t i = 0; i + flength <= size; i++) {
			bool test = true;
			for (size_t j = 0; j < flength; j++) {
				if (buffer[i + j] != fstr[j]) {
					test = false;
					break;
				}
			}
			if (test) {
				index = i;
				std::cout << "The starting position of the string you want to find is " << index << std::endl;
				break;
			}
		}
		return index;
	}

	//int->string
	hstring& operator=(int value) {
		char temp[12];
		int vlength = 0;
		bool  PoN = value < 0;
		if (PoN) {
			value *= -1;
		}
		do {
			temp[vlength++] = '0' + (value % 10);
			value /= 10;
		} while (value > 0);

		if (PoN) {
			temp[vlength++] = '-';
		} //如果为符号得加上-

		IsExceedBuffer(vlength);

		for (int i = 0; i < vlength; ++i) {
			buffer[i] = temp[vlength - 1 - i];
		}

		size = vlength;
		buffer[vlength] = '\0';

		return *this;

	}
	void print() const {
		if (buffer) {
			std::cout << buffer << std::endl;
		}
		else {
			std::cout << "(empty)" << std::endl;
		}
	}
};



int main() {

	hstring str1("123456789");
	str1 + "abc";
	str1.print();  

	str1 - "456";
	str1.print();  

	str1.replace("789", "XYZ");
	str1.print();  

	int pos = str1.find("XYZ");

	hstring str4;
	str4 = 12345;
	str4.print();  

	hstring str5;
	str5 = -6789;
	str5.print();  

	return 0;
}