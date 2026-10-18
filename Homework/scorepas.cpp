#include<iostream>
#include<algorithm>

int main(){
    int n;
    std::cin >> n;
    int t1;
    std::cin >> t1;
    int t2=t1*3/2;
    int m[n][2];
    for(int i=0;i<n;i++){
        std::cin >> m[i][0];
        std::cin >> m[i][1];
    }
    for(int i=0;i<n;i++){
        for(int j=n-1;j>i;j--){
            if(m[j][1]>m[j-1][1] || (m[j][1]==m[j-1][1] && m[j][0]<m[j-1][0])){
                std::swap(m[j],m[j-1]);
            }
        }
    }
    int tscore=m[t2-1][1];
    int ddl=n-1;
    for(int i=0;i<n;i++){
        if(tscore>m[i][1]){
            ddl=i;
            break;
        }
    }
    std::cout << tscore << " " << ddl << std::endl;
    for(int i=0;i<ddl;i++){
        std::cout << m[i][0] << " " << m[i][1] << std::endl;
    }
    return 0;
}