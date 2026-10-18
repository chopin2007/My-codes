#include<iostream>

void traversal(int *a,int t){
    for(int i=0;i<t;i++){
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}

int main(){
    int n;
    std::cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        std::cin >> arr[i];
    }
    for(int i=0;i<3;i++){
        for(int j=n-1;j>i;j--){
            if(arr[j]<arr[j-1]){
                std::swap(arr[j],arr[j-1]);
            }
        }
        traversal(arr,n);
    }
    return 0;
}