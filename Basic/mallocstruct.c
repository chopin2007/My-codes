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
    student *s=(student*)malloc(sizeof(student));
    initialStu(s);
    printf("%s-%s-%d\n",s->stuId,s->stuName,s->age);
    free(s);
    return 0;
}