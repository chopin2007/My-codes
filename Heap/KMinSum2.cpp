#include<iostream>
#include<vector>
#include<string>

//maxheap
void down(std::vector<int>& a,int pos){
    int elem=a[pos];
    while(2*pos<a.size()){
        int child=2*pos;
        if(child<a.size()-1 && a[child]<a[child+1]){
            child++;
        }
        if(elem<a[child]){
            a[pos]=a[child];
            pos=child;
        }
        else break;
    }
    a[pos]=elem;
}

void up(std::vector<int>& a,int pos){
    int elem=a[pos];
    while(pos>1 && elem<a[pos/2]){
        a[pos]=a[pos/2];
        pos/=2;
    }
    a[pos]=elem;
}

void MakeHeapDown(std::vector<int>& a){
    for(int i=(a.size()-1)/2;i>0;i--){
        down(a,i);
    }
}

int main(){
    int n,k;
    std::cin >> n >> k;
    std::vector<int> arr(n+1,0);
    int e;
    for(int i=1;i<n+1;i++){
        std::cin >> e;
        arr[i]=e;
    }
    std::vector<int> res(k+1,0);
    for(int i=1;i<k+1;i++){
        res[i]=arr[i];
    }
    MakeHeapDown(res);
    for(int i=k+1;i<n+1;i++){
        res.push_back(arr[i]);
        up(res,k+1);
        std::swap(res[1],res[k+1]);
        res.pop_back();
        down(res,1);
    }
    int sum=0;
    for(int i=1;i<k+1;i++){
        sum+=res[i];
    }
    std::cout << sum << std::endl;
    return 0;
}