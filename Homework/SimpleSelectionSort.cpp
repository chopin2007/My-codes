#include<iostream>
#include<vector>
#include<algorithm>

void traversal(std::vector<int> v){
    for(int x:v){
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

int main(int argc,char ** argv){
    int n;
    std::cin >> n;
    std::vector<int> nums;
    int element;
    for(int i=0;i<n;i++){
        std::cin >> element;
        nums.push_back(element);
    }
    for(int i=0;i<3;i++){
        int max_index=0;
        int j;
        for(j=0;j<nums.size()-i-1;j++){
            if(nums[max_index]<nums[j]){
                max_index=j;
            }
        }
        std::swap(nums[max_index],nums[j]);
        traversal(nums);
    }
    return 0;
}