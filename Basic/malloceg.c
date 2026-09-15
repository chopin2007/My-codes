#include<stdio.h>
#include<stdlib.h>

int main(int argc,char const *argv[]){
    //栈内存
    int a=5;
    //堆内存
    int *b=(int*)malloc(sizeof(int));
    *b=10;
    printf("%d-%p\n",a,&a);
    printf("%d-%p\n",*b,b);
    return 0;
}