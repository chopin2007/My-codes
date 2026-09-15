# 数据结构
## 一、复习
### 1.转义字符
输出到终端时：\
```c
printf("abc\ndef");
```
显示：
```text
abc
def
```
因为 \n 让光标下移一行。\
而：
```c
printf("abc\rdef");
```
很多终端里会显示成：
```text
def
```
因为 \r 让光标回到行首，然后 def 覆盖了 abc。\
所以 \r 常用来做进度条、刷新同一行输出。
### 2.字符串
字符：'a'\
字符串："a"\
#### 字符串初始化
```c
char str[]="HelloWorld";//数组形式
```
占位符 %zu 是用来打印 size_t 类型值的格式说明符。
%lu----strlen
### *虚拟内存地址

内存条、显卡、各种适配卡都有其各自的存储地址空间。

操作系统将这些设备的存储地址空间抽象成一个巨大的一维数组空间。

对于内存的每一个字节会分配一个32位或64位的编号,这个编号称为内存地址。
### 3.数组

相同数据类型的集合。

数组的长度一旦定义就不能改变。

数组中的每一个元素可以用下标表示位置,如果一个为数组中有n个元素,
那么下标的取值范围是0~n-1。

数组名可以直接当指针（地址）来用
### 4.指针
间接引用操作符*\
也是解引用指针
```c
int a=5;
int *p=&a;
printf("%d\n",*p);
*p=100;
printf("%d\n",a);
```
#### 指针与数组
```c
int a[]={15,22,67,43,76};//a就代表首地址
int *p;//*p是15
p=a;
printf("%p\n",a);
printf("%p\n",p);
printf("%d\n",*p);
```

```c
#include<stdio.h>

int main(){
    int a[]={11,22,33,44,55};
    int *p;
    for(int i=0;i<sizeof(a)/sizeof(a[0]);i++){
        printf("%d\n",a[i]);
    }
    for(int i=0;sizeof[a]<sizeof[a[0]];i++){
        printf("%d\n",*(p+i));
    }
    return 0;
}
```
指针做算术运算\
给指针加上一个整数,实际上加的是这个整数和指针数据类型对应字节数的乘积。
```c
int a=5;
int *p=&a;
printf("%p\n",p);
p++;
printf("%p\n",p);
```
p++->p = p +1->p= p + 1 x 4
#### 指针与函数
```c
void swap(int a,int b){
    int temp;
    temp=a;
    a=b;
    b=temp;
    printf("a=%d,b=%d\n",a,b);
}
```
交换地址的值
```c
void swap(int *a,int *b){
    // a=101,b=105
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
    printf("a=%d,b=%d\n",*a,*b);
}
调用：
```c
swap(&m,&n);
```
这种方法直接交换了m和n
### 5.结构体
struct 类型 变量名;
```c
struct student{
    char stuname[20];
};

int main(){
    int a;
    struct student b;
    //b.stuname = "小明";
    strcpy(b.stuname,"小明");
    return 0;
}
```
#### 类型定义
typedef
```c
#include<stdio.h>
#include<string.h>
typedef struct{
    char stuId[10];
    char stuName[30];
    int age;
}student;
void initialStu(student *p){
    strcpy((*p).stuId,"GS114514");
    strcpy((*p).stuName,"小明");
    (*p).age=25;
}
```
为什么用指针？省内存\
一种简化表示方法
```c
pp->x=1;
pp->y=2;
```
### 6.内存分类

C程序编译后,会以三种形式使用内存:
#### 静态/全局内存
静态声明的变量和全局变量使用这部分内存,这些变量在程序开始运行时分配,直到程序终才消失。
#### 自动内存(栈内存)
函数内部声明的变量使用这部分内存,在函数被调用时才创建。
#### 动态内存(堆内存)
根据需求编写代码动态分配内存,可以编写代码释放,内存中的内容直到释放才消失。
### 7.动态内存分配
void* 万能指针，需要强制转换

下面这个例子，是动态分配堆内存结构体：
```c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    char stuId[10];
    char stuName[30];
    int age;
}student;

void initialStu(student *p){
    strcpy((*p).stuId,"GS114514");
    strcpy((*p).stuName,"小明");
    (*p).age=25;
}

int main(int argc,char const *argv[]){
    int a;
    student *s=(student*)malloc(sizeof(student));//注意s现在已经是个指针了，当然它也可以被看作是一个首地址
    initialStu(s);
    printf("%s-%s-%d\n",s->stuId,s->stuName,s->age);//所以这里是指针->sth.
    free(s);
    return 0;
}
```
记得free()

## 二、算法分析
### 1.算法的特性
有穷性，确定性，可行性，输入，输出
### 2.算法的效率
#### 时间复杂度
也称渐近时间复杂度,T(n)=O(f(n))

随着问题规模n的增大,算法执行时间的增长率和f(n)的增长率相同
#### 程序运行的总时间主要和执行每条语句的耗时和每条语句的执行频率有关。
#### 关注语句频度

由于语句的执行要由源程序翻译成目标代码,目标代码经装配再执行,因此语句执行一次实际所需的具体时间是与机器的软、硬件环境(如机器速度、编译程序质量等)密切相关的。所以,所谓的算法分析并非实际执行所需时间,而是针对算法中语句的执行次数做出估计,从中得到算法执行时间的信息。
```c
for(int i=1;i<=n;i++){//频度为n+1
    
}
```
因为执行完n次还要再判断一次for里的表达式