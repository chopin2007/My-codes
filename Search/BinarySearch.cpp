#include<iostream>
#include<vector>

int BinarySearch(const std::vector<int>& a,int left,int right,int key){
    while(left<=right){
        int mid=(left+right)/2;
        if(a[mid]==key){
            return mid;
        }
        else if(a[mid]<key){
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
    return -1;
}

int main(){
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for(int i=0;i<n;i++){
        std::cin >> arr[i];
    }
    int target;
    std::cin >> target;
    int index=BinarySearch(arr,0,n-1,target);
    std::cout << "Index: " << index << "\n";
    return 0;
}