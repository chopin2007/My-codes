#include <stdio.h>

int main(){
    int senpei=114514,a=1919810;
    int max;
    senpei>a?(max=senpei):(max=a);
    printf("%d\n",max);
    printf("There are %d numbers.\n",sizeof(senpei));
    printf("But There are %d senpeis.\n",sizeof(int)-2);
}