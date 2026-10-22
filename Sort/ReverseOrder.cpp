#include<iostream>
#include<string>
#include<sstream>
#include<vector>

class MergeSort{
private:
    std::vector<int> a;
    std::vector<int> t;
public:
    MergeSort(const std::vector<int>& v):a(v){t.resize(v.size());}
    int TwoWayCount(int lx,int rx,int ly,int ry){
        int i=lx;
        int j=ly;
        int k=lx;
        int count=0;
        while(i<=rx && j<=ry){
            if(a[i]<=a[j]){
                t[k++]=a[i++];
            }
            else{
                t[k++]=a[j++];
                count+=(ly-i);
            }
        }
        while(i<=rx) t[k++]=a[i++];
        while(j<=ry) t[k++]=a[j++];
        for(int i=lx;i<=ry;i++){
            a[i]=t[i];
        }
        return count;
    }
    int sort(int l,int r){
        if(l<r){
            int m=l+(r-l)/2;
            int left=sort(l,m);
            int right=sort(m+1,r);
            int cross=TwoWayCount(l,m,m+1,r);
            return left+right+cross;
        }
        else return 0;
    }
};

int main(){
    std::string input;
    std::getline(std::cin,input);
    std::stringstream nums(input);
    std::string element;
    std::vector<int> arr;
    while(std::getline(nums,element,',')){
        arr.push_back(std::stoi(element));
    }
    MergeSort* x=new MergeSort(arr);
    int res=x->sort(0,arr.size()-1);
    std::cout << res << std::endl;
    delete x;
    return 0;
}