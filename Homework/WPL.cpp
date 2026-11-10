#include<iostream>
#include<vector>
#include<algorithm>

int main(){
    int wpl=0;
    int n;
    std::cin >> n;
    std::vector<int> arr;
    int e;
    for(int i=0;i<n;i++){
        std::cin >> e;
        arr.push_back(e);
    }
    while(arr.size()!=1){
        std::sort(arr.rbegin(),arr.rend());
        int a=arr.back();
        arr.pop_back();
        int b=arr.back();
        arr.pop_back();
        arr.push_back(a+b);
        wpl+=a+b;
    }
    std::cout << wpl << std::endl;
    return 0;
}