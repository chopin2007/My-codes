#include<iostream>
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
    std::vector<int> Arr(){return a;}
};

int main(){
    int n;
    std::cin >> n;
    std::vector<int> arr;
    for(int i=0;i<n;i++){
        int item;
        std::cin >> item;
        arr.push_back(item);
    }
    MergeSort* x=new MergeSort(arr);
    int res=x->sort(0,arr.size()-1);
    std::cout << "count = " << res << std::endl;
    std::vector<int> list=x->Arr();
    for(int i=0;i<n;i++){
        std::cout << list[i] << " ";
    }
    std::cout << std::endl;
    delete x;
    return 0;
}