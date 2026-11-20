#include<iostream>
#include<string>
#include<vector>

//minheap
void down(std::vector<int>& a,int pos){
    int e=a[pos];
    while(2*pos<a.size()){
        int child=2*pos;
        if(2*pos+1<a.size() && a[child]>a[child+1]){
            child++;
        }
        if(a[child]<e){
            a[pos]=a[child];
            pos=child;
        }
        else break;
    }
    a[pos]=e;
}

void up(std::vector<int>& a,int pos){
    int e=a[pos];
    while(pos>1 && e<a[pos/2]){
        a[pos]=a[pos/2];
        pos/=2;
    }
    a[pos]=e;
}

void MakeHeapDown(std::vector<int>& a){
    for(int i=(a.size()-1)/2;i>0;i--){
        down(a,i);
    }
}

void Insert(std::vector<int>& a,int e){
    a.push_back(e);
    up(a,a.size()-1);
}

int main(){
    int n;
    std::cin >> n;
    std::vector<int> arr={0};
    arr.push_back(1);
    MakeHeapDown(arr);
    int count=0;
    int prev=0;
    while(count<n){
        int t=arr[1];
        std::swap(arr[1],arr.back());
        arr.pop_back();
        down(arr,1);
        if(t==prev) continue;
        count++;
        Insert(arr,2*t);
        Insert(arr,3*t);
        Insert(arr,5*t);
        prev=t;
    }
    std::cout << prev << "\n";
    return 0;
}