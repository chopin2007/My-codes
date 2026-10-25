#include<iostream>

void TwoWayMerge(int* a,int* t,int lx,int rx,int ly,int ry){
    int i=lx;
    int j=ly;
    int k=i;
    while(i<=rx || j<=ry){
        if(j>ry || (i<=rx && a[i]<=a[j])){
            t[k++]=a[i++];
        }
        else{
            t[k++]=a[j++];
        }
    }
    for(int i=lx;i<=ry;i++){
        a[i]=t[i];
    }
}

void Sort(int* a,int n){
    int* t=new int[n];
    int sortedlen=1;
    int count=0;
    while(sortedlen<n && count<3){
        int lx=0;
        while(lx<=n-1-sortedlen){
            int rx=lx+sortedlen-1;
            int ly=rx+1;
            int ry=std::min(n-1,ly+sortedlen-1);
            TwoWayMerge(a,t,lx,rx,ly,ry);
            lx=ry+1;
        }
        sortedlen*=2;
        for(int i=0;i<n;i++){
            std::cout << a[i] << " ";
        }
        std::cout << std::endl;
        count++;
    }
    delete[] t;
}

int main(){
    int n;
    std::cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        std::cin >> arr[i];
    }
    Sort(arr,n);
    return 0;
}