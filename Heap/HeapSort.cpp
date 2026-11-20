#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>

//maxheap
void down(std::vector<int>& a,int size,int pos){
    int e=a[pos];
    while(2*pos<size){
        int child=2*pos;
        if(2*pos+1<size && a[child]<a[child+1]){
            child++;
        }
        if(a[child]>e){
            a[pos]=a[child];
            pos=child;
        }
        else break;
    }
    a[pos]=e;
}

void MakeHeapDown(std::vector<int>& a){
    for(int i=(a.size()-1)/2;i>0;i--){
        down(a,a.size(),i);
    }
}

int main(){
    std::string input;
    std::getline(std::cin,input);
    std::stringstream ss(input);
    std::vector<int> arr={0};
    std::string elem;
    while(std::getline(ss,elem,' ')){
        arr.push_back(std::stoi(elem));
    }
    int a_s=arr.size();
    MakeHeapDown(arr);
    for(int i=0;i<arr.size()-1;i++){
        std::swap(arr[1],arr[a_s-1]);
        a_s--;
        down(arr,a_s,1);
    }
    for(int i=1;i<arr.size();i++){
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
    return 0;
}