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