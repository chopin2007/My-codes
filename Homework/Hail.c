#include<stdio.h>

int count=1;

int hail(int n){
    if(n==1) {printf("%d",n);return 0;}
    printf("%d ",n);
    if(n%2==0){
        n=n/2;
        count++;
        hail(n);
    }
    else{
        n=n*3+1;
        count++;
        hail(n);
    }
    return 0;
}

int main(){
    int w;
    int ret = scanf("%d", &w);
    if (ret != 1) {
        return 0;
    }
    hail(w);
    printf("\ncount = %d",count);
}