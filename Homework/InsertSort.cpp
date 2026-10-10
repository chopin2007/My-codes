#include<iostream>
#include<vector>

void traversal(std::vector<int> v){
    for(int i=0;i<v.size()-1;i++){
        std::cout << v[i] << " ";
    }
    std::cout << v.back() << std::endl;
}

int main(int argc,char ** argv){
    int n=0;
    std::cin >> n;
    std::vector<int> nums;
    int x;
    for(int i=0;i<n;i++){
        std::cin >> x;
        nums.push_back(x);
    }
    for(int i=1;i<nums.size();i++){
        int temp=nums[i];
        int j;
        for(j=i-1;j>=0;j--){
            if(temp<nums[j]){
                nums[j+1]=nums[j];
            }
            else{
                break;
            }
        }
        nums[j+1]=temp;
        traversal(nums);
    }
    return 0;
}