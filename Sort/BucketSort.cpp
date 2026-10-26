#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<climits>

class BucketSort{
private:
    std::vector<int> a;
    std::vector<std::vector<int>> b=std::vector<std::vector<int>>(10);
public:
    BucketSort(const std::vector<int>& arr):a(arr){}
    void ISort(std::vector<int>& bucket){
        if(bucket.size()<1) return;
        for(int i=1;i<bucket.size();i++){
            int temp=bucket[i];
            for(int j=i;j>0;j--){
                if(temp<bucket[j-1]){
                    bucket[j]=bucket[j-1];
                }
                else{
                    bucket[j]=temp;
                    break;
                }
            }
        }
    }
    std::vector<int> BSort(){
        if(a.empty()) return {};
        int maxnum=0;
        int minnum=INT_MAX;
        for(const int &x:a){
            maxnum=std::max(maxnum,x);
            minnum=std::min(minnum,x);
        }
        int total=maxnum-minnum;
        int e=total/10;
        for(const int &x:a){
            int pos=(x-minnum)/e;
            pos=std::min(pos,9);
            b[pos].push_back(x);
        }
        std::vector<int> res;
        for(int i=0;i<10;i++){
            ISort(b[i]);
            for(int j=0;j<b[i].size();j++){
                res.push_back(b[i][j]);
            }
        }
        return res;
    }
    void print(const std::vector<int>& a){
        for(int i=0;i<a.size()-1;i++){
            std::cout << a[i] << ",";
        }
        std::cout << a.back() << std::endl;
    }
};

int main(){
    std::string input;
    std::getline(std::cin,input);
    std::stringstream nums(input);
    std::vector<int> arr;
    std::string element;
    while(std::getline(nums,element,',')){
        arr.push_back(std::stoi(element));
    }
    BucketSort* bucket=new BucketSort(arr);
    std::vector<int> ans=bucket->BSort();
    bucket->print(ans);
    return 0;
}