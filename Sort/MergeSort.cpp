#include<iostream>
#include<string>
#include<sstream>
#include<vector>

class MergeSort{
private:
    static std::vector<int> v;
    static std::vector<int> temp;
public:
    static void initial(const std::vector<int>& i){
        v=i;
        temp.resize(v.size());
    }
    static void TwoWayMerge(int lx,int rx,int ly,int ry){
        int i=lx;
        int j=ly;
        int k=lx;
        while(i<=rx || j<=ry){
            if(j>ry || (i<=rx && v[i]<=v[j])) temp[k++]=v[i++];
            else temp[k++]=v[j++];
        }
        for(int i=lx;i<=ry;i++){
            v[i]=temp[i];
        }
    }
    static void sort(int l,int r){
        if(l<r){
            int m=(l+r)/2;
            sort(l,m);
            sort(m+1,r);
            TwoWayMerge(l,m,m+1,r);
        }
    }
    static void SortBottomUp(int l,int r){
        int sorted_len=1;
        while(sorted_len<r-l+1){
            int lx=l;
            while(lx<=r-sorted_len){
                int rx=lx+sorted_len-1;
                int ly=rx+1;
                int ry=std::min(r,ly+sorted_len-1);
                TwoWayMerge(lx,rx,ly,ry);
                lx=ry+1;
            }
            sorted_len*=2;
        }
    }
    static void print(){
        for(int i=0;i<v.size()-1;i++){
            std::cout << v[i] << ",";
        }
        std::cout << v.back() << std::endl;
    }
};

std::vector<int> MergeSort::v;
std::vector<int> MergeSort::temp;

int main(int argc,char ** argv){
    std::string input;
    std::getline(std::cin,input);
    std::stringstream numstream(input);
    std::vector<int> arr;
    std::string element;
    while(std::getline(numstream,element,',')){
        arr.push_back(std::stoi(element));
    }
    MergeSort::initial(arr);
    MergeSort::SortBottomUp(0,arr.size()-1);
    MergeSort::print();
    return 0;
}