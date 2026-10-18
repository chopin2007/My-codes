#include<iostream>
#include<sstream>
#include<string>
#include<vector>

class Solution{
public:
    void traversal(std::vector<int>& nums){
        for(int i=0;i<nums.size();i++){
            std::cout << nums[i] << ' ';
        }
        std::cout << std::endl;
    }

    void InsertionSort(std::vector<int>& nums){
        for(int i=1;i<nums.size();i++){
            int e=nums[i];
            int j=i;
            while(j>0 && nums[j-1]>e){
                nums[j]=nums[j-1];
                j--;
            }
            nums[j]=e;
            traversal(nums);
        }
    }

    void ShellSort(std::vector<int>& nums){
        int d=nums.size()/2;
        while(d!=0){
            for(int i=d;i<nums.size();i++){
                int e=nums[i];
                int j=i;
                while(j>=d && nums[j-d]>e){
                    nums[j]=nums[j-d];
                    j-=d;
                }
                nums[j]=e;
            }
            traversal(nums);
            d/=2;
        }
    }

    void BubbleSort(std::vector<int>& nums){
        for(int i=0;i<nums.size();i++){
            for(int j=nums.size()-1;j>i;j--){
                if(nums[j]<nums[j-1]){
                    int temp=nums[j-1];
                    nums[j-1]=nums[j];
                    nums[j]=temp;
                }
            }
            traversal(nums);
        }
    }

    void BubbleSortPlus(std::vector<int>& nums){
        for(int i=0;i<nums.size();i++){
            bool flag=true;
            for(int j=nums.size()-1-i;j>0;j--){
                if(nums[j]<nums[j-1]){
                    flag=false;
                    int temp=nums[j-1];
                    nums[j-1]=nums[j];
                    nums[j]=temp;
                }
            }
            if(flag) break;
            traversal(nums);
        }
    }

    void KBubbleSort(std::vector<int>& nums,int& k){
        for(int i=0;i<nums.size() && k>0;i++){
            int min_index=i;
            for(int j=i;j<std::min((int)nums.size(),i+k+1);j++){
                if(nums[min_index]>nums[j]) min_index=j;
            }
            for(int j=min_index;j>i && k>0;j--){
                std::swap(nums[j],nums[j-1]);
                k--;
                traversal(nums);
            }
        }
    }

    void WiggleSort(std::vector<int>& nums){
        for(int i=0;i<nums.size()-1;i++){
            if(i%2==0 && nums[i]<nums[i+1]){
                std::swap(nums[i],nums[i+1]);
            }
            if(i%2==1 && nums[i]>nums[i+1]){
                std::swap(nums[i],nums[i+1]);
            }
            traversal(nums);
        }
    }

    void SelectionSort(std::vector<int>& nums){
        for(int i=0;i<nums.size();i++){
            int minindex=i;
            for(int j=i;j<nums.size();j++){
                if(nums[j]<nums[minindex]){
                    minindex=j;
                }
            }
            std::swap(nums[minindex],nums[i]);
            traversal(nums);
        }
    }

    void PancakeSort(std::vector<int>& nums){
        for(int i=0;i<nums.size();i++){
            int maxindex=0;
            for(int j=0;j<nums.size()-i;j++){
                if(nums[j]>nums[maxindex]){
                    maxindex=j;
                }
            }
            for(int j=0;j<=maxindex/2;j++){
                std::swap(nums[j],nums[maxindex-j]);
            }
            for(int j=0;j<=(nums.size()-i-1)/2;j++){
                std::swap(nums[j],nums[nums.size()-i-1-j]);
            }
            traversal(nums);
        }
    }

    int partition(std::vector<int>& nums,int l,int r){
        int i=l;
        int j=r-1;
        int m=nums[r];
        while(i<=j){
            while(i<=j && nums[i]<m){i++;}
            while(i<=j && nums[j]>m){j--;}
            if(i<=j){
                int temp=nums[i];
                nums[i++]=nums[j];
                nums[j--]=temp;
            }
        }
        int temp=nums[i];
        nums[i]=nums[r];
        nums[r]=temp;
        return i;
    }

    void QuickSort(std::vector<int>& nums,int l,int r){
        if(l<r){
            int i=partition(nums,l,r);
            QuickSort(nums,l,i-1);
            QuickSort(nums,i+1,r);
        }
    }
};

int main(int argc,char **argv){
    std::string in;
    std::getline(std::cin,in);
    std::stringstream numlist(in);
    std::vector<int> arr;
    std::string element;
    while(std::getline(numlist,element,',')){
        arr.push_back(std::stoi(element));
    }
    int choice;
    std::cin >> choice;
    Solution sol;
    switch(choice){
        case 0:
            sol.InsertionSort(arr);
            break;
        case 1:
            sol.ShellSort(arr);
            break;
        case 2:
            sol.BubbleSort(arr);
            break;
        case 3:
            sol.SelectionSort(arr);
            break;
        case 4:
            sol.PancakeSort(arr);
            break;
        case 5:
            sol.BubbleSortPlus(arr);
            break;
        case 6:
            sol.QuickSort(arr,0,arr.size()-1);
            sol.traversal(arr);
            break;
        case 7:
            sol.WiggleSort(arr);
            break;
        case 8:
            int key;
            std::cout << "k的值是：";
            std::cin >> key;
            sol.KBubbleSort(arr,key); 
            break;
        }
    return 0;
}