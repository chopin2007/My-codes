#include<iostream>
#include<vector>

//minheap
void down(std::vector<int>& a,int pos){
    int elem=a[pos];
    while(2*pos<a.size()){
        int child=2*pos;
        if(child+1<a.size() && a[child]>a[child+1]){
            child++;
        }
        if(elem>a[child]){
            a[pos]=a[child];
            pos=child;
        }
        else break;
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
    std::vector<int> arr={0};
    for(int i=0;i<n;i++){
        int e;
        std::cin >> e;
        arr.push_back(e);
    }
    MakeHeapDown(arr);
    int i=0;
    int sum=0;
    while(i<k){
        sum+=arr[1];
        std::swap(arr[1],arr[arr.size()-1]);
        arr.pop_back();
        down(arr,1);
        i++;
    }
    std::cout << sum << std::endl;
    return 0;
}