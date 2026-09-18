#include<stdio.h>

int main(int argc,char **argv){
    int size;
    int res1=scanf("%d",&size);
    if(res1!=1){
        return 0;
    }
    int list[size];
    for(int i=0;i<size;i++){
        if(scanf("%d",&list[i])!=1){
            return 0;
        }
    }
    int xy[2];
    int res3=scanf("%d %d",&xy[0],&xy[1]);
    if(res3!=2){
        return 0;
    }
    int sum=0;
    for(int i=0;i<size;i++){
        if(list[i]>=xy[0] && list[i]<=xy[1]){
            sum+=list[i];
        }
    }
    printf("%d",sum);
}