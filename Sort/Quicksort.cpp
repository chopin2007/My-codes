#include<iostream>
#include<sstream>
#include<string>
#include<vector>

class QuickSort{
private:
    static std::vector<int> v;
public:
    static void initial(const std::vector<int>& i){
        v=i;
    }
    static int median(int a,int b,int c){
        if(v[a]>v[b]){
            if(v[b]>v[c]) return b;
            else if(v[c]>v[a]) return a;
            else return c;
        }
        else{
            if(v[a]>v[c]) return a;
            else if(v[c]>v[b]) return b;
            else return c;
        }
    }
    static int partition(int l,int r){
        int i=l;
        int j=r-1;
        int p=median(l,l+(r-l)/2,r);
        std::swap(v[p],v[r]);
        p=r;
        while(i<j){
            while(i<j && v[i]<v[p]) i++;
            while(i<j && v[j]>v[p]) j--;
            if(i<j) std::swap(v[i++],v[j--]);
        }
        std::swap(v[i],v[p]);
        return i;
    }
    static void sort(int l,int r){
        if(l<r){
            int t=partition(l,r);
            sort(l,t-1);
            sort(t+1,r);
        }
        else return;
    }
    static void print(){
        if(v.empty()) return;
        for(int i=0;i<v.size()-1;i++){
            std::cout << v[i] << ",";
        }
        std::cout << v.back() << std::endl;
    }
};

std::vector<int> QuickSort::v;

int main(int argc,char ** argv){
    std::string input;
    std::getline(std::cin,input);
    std::stringstream numlist(input);
    std::vector<int> arr;
    std::string element;
    while(std::getline(numlist,element,',')){
        arr.push_back(std::stoi(element));
    }
    QuickSort::initial(arr);
    QuickSort::sort(0,arr.size()-1);
    QuickSort::print();
    return 0;
}