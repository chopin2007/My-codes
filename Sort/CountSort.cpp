#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<algorithm>

class CountSort{
private:
    std::vector<int> a;
public:
    CountSort(const std::vector<int>& x):a(x){}
    void sort(){
        int maxn=a[0];
        int minn=a[0];
        for(int &x:a){
            maxn=std::max(maxn,x);
            minn=std::min(minn,x);
        }
        int n=maxn-minn+1;
        std::vector<int> t(n,0);
        for(int &x:a){
            t[x-minn]++;
        }
        for(int i=1;i<n;i++){
            t[i]+=t[i-1];
        }
        std::vector<int> res(a.size(),0);
        for(int i=a.size()-1;i>=0;i--){
            res[t[a[i]-minn]-1]=a[i];
            t[a[i]-minn]--;
        }
        a=res;
    }
    void print(){
        for(int i=0;i<a.size()-1;i++){
            std::cout << a[i] << ",";
        }
        std::cout << a.back() << std::endl;
    }
};

int main(int argc,char ** argv){
    std::string input;
    std::getline(std::cin,input);
    std::stringstream nums(input);
    std::vector<int> arr;
    std::string element;
    while(std::getline(nums,element,',')){
        arr.push_back(std::stoi(element));
    }
    CountSort* l=new CountSort(arr);
    l->sort();
    l->print();
    return 0;
}