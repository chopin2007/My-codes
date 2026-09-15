#include<stdio.h>

int* sort_ch(int a[5]){   //选择排序
    int swap;
    for(int i=0;i<5-1;i++){
        int minnum=i;
        for(int j=i;j<5;j++){
            if(a[minnum]>a[j]){
                minnum=j;
            }
        }
        swap=a[minnum];
        a[minnum]=a[i];
        a[i]=swap;
    }
    return a;
}

int* sort_bub(int a[5]){    //冒泡排序
    for(int i=0;i<5;i++){
        for(int j=0;j<5-i-1;j++){
            if(a[j]<a[j+1]){
                int swap=a[j];
                a[j]=a[j+1];
                a[j+1]=swap;
            }
        }
    }
    return a;
}


int main(){
    int l[5];
    for(int i=0;i<5;i++){
        scanf("%d",&l[i]);
    }
    int *l1=sort_ch(l);
    for(int i=0;i<5;i++){
        printf("%d,",l1[i]);
    }
    printf("/n");
    int *l2=sort_bub(l);
    for(int i=0;i<5;i++){
        printf("%d,",l2[i]);
    }
    printf("/n");
    return 0;
}