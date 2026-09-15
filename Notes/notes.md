# C语言
## 编译与运行
手动：\
gcc hello.c -o hello.exe\
.\hello.exe\
自动：ctrl+alt+n
## 数据类型：int,float,double,char.long
### int(整型)
**长度4字节**\
取值范围：-2147483648~2147483647\
占位符：%d

### float(单浮点)
**长度在32位中4字节，64位中8字节**\
占位符：%f

### double(双浮点)
**长度8字节**\
占位符：%If

### long
**长度在32位是4个字节，在64位是8个字节**

### char(字符型)
**长度1字节**\
占位符：%c

### bool(布尔型)
**长度1字节**\
只有true和false

### 无符号数
unsighed int\
unsighed short\
unsigned char\
unsighed long

### 指针大小：32位4个字节，64位8个字节

## 常量
```c
#define PI 3.14//定义常量PI
```
## 输入输出
### 输入(scanf)
```c
int a=0;
scanf("%d",&a);
```
### 输出(printf)
```c
int a=1;
printf("One is %d.",a);
```
```c
int a=2,b=3;
printf("Two is %d.\nThree is %d.",a.b);
```
## 逻辑运算符
&&:与\
||:或\
！:非
### 1？2：3；
条件运算符 真执行2，假执行3
```c
int a=5,b=3;
int max;
a>b?(max=a):(max=b);
```
## switch语句
```c
int main(){
    int a;
    scanf("%d",a);
    switch(a){
        case 1:
            printf("1");
            break;
        case 2:
            printf("2");
            break;
        default:
            printf("none");
    }
}
```
## ***指针（pointer）***
示例：
```c
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int a=0;
    char *p=NULL;
    p=(char *)malloc(1);
    *p='a';
    printf("%c\n",*p);
    free(p);
    char *A=(char *)malloc(sizeof(char)*10);
    A[0]='k',A[1]='s',A[2]='k',A[3]='b',A[4]='l';
    int b[10];
    for(int i=0;i<5;i++)
    {
        printf("%c",A[i]);
        b[i]=i;
    }
    free(A);
    return 0;
}
```
指针就是地址
```c
int age=100;
int *p=&a;
```
