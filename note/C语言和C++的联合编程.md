# C语言和C++的联合编程

# static和inline

static 静态   静态变量

inline 内联函数（<font color='red'>基本被淘汰</font>）

```c++
static int a;

int add(int a,int b){
    static int count;
    count++;
    //......
    return a;
}

```

变量初始化为0（<font color='cornflowerblue'>如果不指定的话</font>）且只被初始化一次

static生命周期非常长，程序结束才会结束，<font color='cornflowerblue'>可以用于统计</font>



内联函数

```c++
inline int add(int a,int b){
    return a+b;
}//有可能是直接c=1+2；
```

<font color='cornflowerblue'>已经被弃用了</font>



## 从编译器的角度理解定义和声明

定义

和计算机之间的事情

声明 可以提前声明  <font color='cornflowerblue'>声明可以声明多次</font>



声明放在前面，是告知编译器我们有这个函数

```c++
extern int all;  //针对全局变量，函数不加extern是因为默认extern

int all{250};  //extern是声明，下面是定义
```



## 头文件和源文件

头文件一般来说是放声明

<img src="C:\Users\liqui\AppData\Roaming\Typora\typora-user-images\image-20240629161211970.png" alt="image-20240629161211970" style="zoom:50%;" />

各种obj组合成目标程序

```c++
#include"aaa.h"
```

本质是把这个头文件的内容放入cpp， .h文件只有在被调用时才会被编译



在一个工程中，定义只能有一次，所以函数最好不要放在.h中



！！！！！声明有n次但是定义只有一次！！！！！！！！！！！！！！！！！！！！！



变量可以在.h文件中用extern来声明，达到公用的目的



静态函数可以定义在 **头文件**中，只在include了.h的源文件中有效



**内联函数**也可以



**static**定义静态变量但是只在各自的函数里有效**！！！！！！！！！！！**





#ifndef  依赖于开关名字

#pragma once 依赖于文件的名字



## extern的用法（模块化的一部分）

C++支持函数重载

在C中使用 extern ”C“ 就可以在CPP中使用



```C++
extern "C"{
	int ave();
	int test();
}
```

在**头文件**中声明一群



还可以

```c++
extern "C"{
	#include "e.h"    //也可以把C转到C++中使用
}
```

<img src="C:\Users\liqui\AppData\Roaming\Typora\typora-user-images\image-20240629171824960.png" alt="image-20240629171824960" style="zoom:50%;" />

**默认宏**

```c++
#ifdef __cplusplus
extern "C" {
#endif

// 这里放置C函数声明或定义
void myFunction(int arg);

#ifdef __cplusplus
}
#endif
```

但是一旦编译成C风格的函数，就不再支持函数的重载了

## LNK4042

同名问题

## 创建自己的sdk

SDK（Software Development Kit，软件开发工具包）是为特定的软件包、软件框架、硬件平台、操作系统等提供的开发工具集合。SDK通常包含一些软件开发中必需的工具、库、文档、代码示例和相关帮助文件，旨在帮助开发者创建应用程序。



1. **库（Libraries）**：预编译的代码库，开发者可以直接使用这些库中的函数和方法来实现某些功能，而不必从头开始编写代码。
2. **工具（Tools）**：包括编译器、调试器、构建工具等，可以帮助开发者编写、测试和部署应用程序。
3. **文档（Documentation）**：详细的API文档、开发指南和参考手册，帮助开发者了解如何使用SDK中的功能和接口。
4. **代码示例（Code Examples）**：一些示例程序和代码片段，展示如何使用SDK中的各种功能，帮助开发者更快地上手。
5. **开发环境（Development Environment）**：某些SDK可能会包含一个集成开发环境（IDE），如Android SDK中的Android Studio，方便开发者进行开发工作。
6. **头文件（Header Files）**：在C/C++开发中，SDK会包含头文件，这些文件声明了库函数和数据结构，开发者需要在自己的代码中包含这些头文件。





```c++
#include <iostream>

// 定义一个命名空间
namespace MyNamespace {
    void myFunction() {
        std::cout << "Hello from MyNamespace!" << std::endl;
    }
}

int main() {
    // 调用命名空间中的函数
    MyNamespace::myFunction();

    return 0;
}

```

`MyNamespace` 是一个命名空间，其中包含了一个名为 `myFunction` 的函数。通过使用 `MyNamespace::myFunction()` 语法，我们可以调用该命名空间中的函数。





属性->配置属性->常规->配置类型：静态库lib



右键生成



.lib是库文件

.h 类似于说明书



最后的安装包叫sdk



属性页面  **VC++目录** 包含目录 里放入     .h

库目录里放入.lib

![image-20240629190902969](C:\Users\liqui\AppData\Roaming\Typora\typora-user-images\image-20240629190902969.png)



```c++
#include<aaa.h>
#pragma comment(lib,"aaa.lib") //链接库文件
```

如果不用pragma

**属性 链接器 输入 附加依赖项 加入想要的lib**

？？？？

## 创建项目类型



## 函数调用约定

日常从右往左传，支持不定量  只支持__cedel  函数本身会负责恢复栈平衡



stdcall  不负责恢复栈平衡

**winapi callback** 都是stdcall的宏



fastcall 优先通过**寄存器**传参 也是从右到左，但是如果参数超过寄存器数量，

只有没有存在寄存器的参数由函数本身恢复栈平衡   **主要是fastcall**

__thiscall  类的



nakedcall 偏底层



## 递归函数

递归函数可能崩溃

内联函数不能递归
