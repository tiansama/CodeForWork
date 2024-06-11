#include<iostream>
#include"checksource.h"

using namespace std;

int checksource() {
	auto testvalue{ 200 };
	cout<<typeid(testvalue).name()<<endl;
	return 0;
}