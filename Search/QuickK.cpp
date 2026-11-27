#include<iostream>
#include<vector>

int Partition(std::vector<int>& a,int l,int r){
    int i=l;
    int j=r-1;
    int p=a[r];
    while(true){
        while(a[i]<p){
            i++;
        }
        while(a[j]>p && j>l){
            j--;
        }
        if(i>=j) break;
        std::swap(a[i],a[j]);
        i++;
        j--;
    }
    std::swap(a[i],a[r]);
    return i;
}

int QuickSearch(std::vector<int>& a,int l,int r,int k){
    if(l<r){
        int m=Partition(a,l,r);
        if(m==k){
            return a[k];
        }
        else if(m<k){
            return QuickSearch(a,m+1,r,k);
        }
        else{
            return QuickSearch(a,l,m-1,k);
        }
    }
    return a[l];
}

int main(){
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for(int i=0;i<n;i++){
        std::cin >> arr[i];
    }
    int k;
    std::cin >> k;
    int val=QuickSearch(arr,0,n-1,k);
    std::cout << "第k小的值: " << val << "\n";
    return 0;
}