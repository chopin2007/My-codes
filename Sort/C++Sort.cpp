#include<iostream>
#include<cmath>
#include<vector>
#include<string>
#include<sstream>

class Sort{
private:
    std::vector<int> a;
    int kThrLen=16;
public:
    Sort(const std::vector<int>& a):a(a){
        int maxDepth=2*log2(a.size());
        IntroSort(0,a.size()-1,maxDepth);
    }

    int median(int x1,int x2,int x3){
        if(a[x1]>a[x2]){
            if(a[x2]>a[x3]) return x2;
            else if(a[x3]>a[x1]) return x1;
            else return x3;
        }
        else{
            if(a[x3]<a[x1]) return x1;
            else if(a[x2]<a[x3]) return x2;
            else return x3;
        }
    }
    int partition(int l,int r){
        int i=l;
        int j=r-1;
        int p=median(l,l+(r-l)/2,r);
        std::swap(a[p],a[r]);
        p=r;
        while(i<j){
            while(i<j && a[i]<a[p]) i++;
            while(i<j && a[j]>a[p]) j--;
            if(i<j) std::swap(a[i++],a[j--]);
        }
        std::swap(a[i],a[p]);
        return i;
    }

    void InsertSort(int l,int r){
        for(int i=l+1;i<=r;i++){
            int temp=a[i];
            int j=i;
            while(j>l && a[j-1]>temp){
                a[j]=a[j-1];
                j--;
            }
            a[j]=temp;
        }
    }

    void DownAdjust(std::vector<int>& t,int i,int n){
        int j=2*i;
        while(j<=n){
            if(j+1<=n && t[j+1]>t[j]) j++;
            if(t[i]<t[j]){
                std::swap(t[i],t[j]);
                i=j;
                j=i*2;
            }
            else break;
        }
    }
    void HeapSort(int l,int r){
        int n=(r-l)/2;
        std::vector<int> tree(n+1,0);
        for(int i=0;i<n;i++){
            tree[i+1]=a[l+i];
        }
        for(int i=n/2;i>=1;i--){
            DownAdjust(tree,i,n);
        }
        for(int i=n;i>1;i--){
            std::swap(tree[1],tree[i]);
            DownAdjust(tree,1,i-1);
        }
        for(int i=0;i<n;i++){
            a[l+i]=tree[i+1];
        }
    }

    void IntroSort(int l,int r,int d){
        if(r-l+1<kThrLen){
            InsertSort(l,r);
        }
        else if(d==0){
            HeapSort(l,r);
        }
        else{
            int m=partition(l,r);
            IntroSort(l,m-1,d-1);
            IntroSort(m+1,r,d-1);
        }
    }

    std::vector<int> Sorted(){return a;}
};

int main(){
    std::string in;
    std::getline(std::cin,in);
    std::stringstream nums(in);
    std::vector<int> arr;
    std::string element;
    while(std::getline(nums,element,',')){
        arr.push_back(std::stoi(element));
    }
    Sort s(arr);
    std::vector<int> res=s.Sorted();
    for(int i=0;i<res.size()-1;i++){
        std::cout << res[i] << ",";
    }
    std::cout << res.back() << std::endl;
    return 0;
}