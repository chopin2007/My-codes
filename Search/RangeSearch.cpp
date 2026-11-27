#include<iostream>
#include<vector>
#include<utility>

std::pair<int,int> RangeSearch(const std::vector<int>& a,int key){
    int left=-1;
    int right=a.size();
    while(right-left>1){
        int mid=(left+right)/2;
        if(key<=a[mid]){
            right=mid;
        }
        else{
            left=mid;
        }
    }
    return {left,right};
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
    std::pair<int,int> range=RangeSearch(arr,target);
    std::cout << ">=k有: " << n-range.second << "\n";
    std::cout << "<k有: " << range.first+1 << "\n";  
    return 0;
}