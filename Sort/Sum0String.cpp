#include<iostream>
#include<vector>
#include<unordered_map>

//哈希
class Solution1{
public:
    std::vector<int> Maxstring(const std::vector<int>& a){
        if(a.empty()) return {};
        std::unordered_map<int,int> hp;
        int max_len=0;
        int max_index=0;
        int sum=0;
        hp[0]=-1;
        for(int i=0;i<a.size();i++){
            int temp=sum+a[i];
            if(hp.count(temp) && (max_len<i-hp[temp] || max_len==0)){
                max_len=i-hp[temp];
                max_index=hp[temp]+1;
            }
            hp[temp]=i;
            sum=temp;
        }
        std::vector<int> r;
        for(int i=0;i<max_len;i++){
            r.push_back(a[max_index+i]);
        }
        return r;
    }
};

//计数
class Solution2{
public:
    std::vector<int> Maxstring(const std::vector<int>& a){
        if(a.empty()) return {};
        std::vector<int> sums(a.size(),0);
        int upper=a[0];
        int lower=a[0];
        sums[0]=a[0];
        for(int i=1;i<a.size();i++){
            sums[i]=sums[i-1]+a[i];
            upper=std::max(upper,sums[i]);
            lower=std::min(lower,sums[i]);
        }
        std::vector<int> temp(upper-lower+1,-1);
        int max_len=0;
        int max_index=0;
        for(int i=0;i<sums.size();i++){
            if(temp[sums[i]-lower]<0){
                temp[sums[i]-lower]=i;
            }
            else{
                if(max_len<i-temp[sums[i]-lower]){
                    max_len=i-temp[sums[i]-lower];
                    max_index=temp[sums[i]-lower]+1;
                }
            }
        }
        std::vector<int> r;
        for(int i=0;i<max_len;i++){
            r.push_back(a[max_index+i]);
        }
        return r;
    }
};

int main(){
    std::vector<int> arr={5,-1,-2,3,4,0,-6,1,5,1,-3,1,2,1};
    Solution1 sol1;
    Solution2 sol2;
    std::vector<int> res1=sol1.Maxstring(arr);
    std::vector<int> res2=sol2.Maxstring(arr);
    for(int i=0;i<res1.size()-1;i++){
        std::cout << res1[i] << ",";
    }
    std::cout << res1.back() << std::endl;
    for(int i=0;i<res2.size()-1;i++){
        std::cout << res2[i] << ",";
    }
    std::cout << res2.back() << std::endl;
    return 0;
}