#include<iostream>
#include<vector>

void RadixSort(std::vector<int>& a){
    int times=0;
    int exp=1;
    std::vector<int>* Digit=new std::vector<int>[10];
    while(times<3){
        for(int x:a){
            int digit=(x/exp)%10;
            Digit[digit].push_back(x);
        }
        a.clear();
        for(int i=0;i<10;i++){
            for(int num:Digit[i]){
                a.push_back(num);
            }
            Digit[i].clear();
        }
        for(int x:a){
            std::cout << x << " ";
        }
        std::cout << std::endl;
        times++;
        exp*=10;
    }
    delete[] Digit;
}

int main(){
    int n;
    std::cin >> n;
    std::vector<int> arr;
    for(int i=0;i<n;i++){
        int item;
        std::cin >> item;
        arr.push_back(item);
    }
    RadixSort(arr);
    return 0;
}