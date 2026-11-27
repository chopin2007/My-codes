#include<iostream>

long Power(int a,int n){
    if(n==0) return 1;
    long pow=Power(a,n/2);
    pow*=pow;
    if(n%2==1){
        pow*=a;
    }
    return pow;
}

int main(){
    int a,n;
    std::cin >> a >> n;
    std::cout << Power(a,n) << "\n";
    return 0;
}