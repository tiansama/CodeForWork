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



声明





