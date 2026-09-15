#include<stdio.h>
#include<stdlib.h>

int main(){
    typedef struct student{
        char name[20];
        int age;
        float weight;
        int score;
    }stu,*stup;
    stup b=(stup)malloc(sizeof(stu));
    free(b);
}