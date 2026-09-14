#include<stdio.h>

void selection_sort(int *a,int n){
    for(int i=n-1;i>0;i--){
        int maxnum=i;
        for(int j=0;j<i;j++){
            if(a[maxnum]<a[j]) maxnum=j;
        }
        int swap=a[maxnum];
        a[maxnum]=a[i];
        a[i]=swap;
    }
}

void buttle_sort(int *a,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]<a[j+1]){
                int swap=a[j];
                a[j]=a[j+1];
                a[j+1]=swap;
            }
        }
    }
}

void insert_sort(int *a,int n){
    int swap;
    for(int i=1;i<n;i++){
        int key=a[i];
        for(int j=0;j<i;j++){
            if(key<a[j]){
                swap=a[j];
                a[j]=key;
                key=swap;
            }
        }
        a[i]=key;
    }
}

int main(){
    int k;
    printf("Type your members:");
    scanf("%d",&k);
    int l[k];
    for(int i=0;i<k;i++){
        scanf("%d",&l[i]);
    }
    //selection_sort(l,k);
    //buttle_sort(l,k);
    insert_sort(l,k);
    for(int i=0;i<k-1;i++){
        printf("%d,",l[i]);
    }
    printf("%d",l[k-1]);
}