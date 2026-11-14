#include<iostream>
#include<string>
#include<cmath>

int main(){
    std::string s;
    std::cin >> s;
    s=" "+s;
    int n=s.size();
    char e1,e2;
    int e1i=-1,e2i=-1;
    std::cin >> e1 >> e2;
    for(int i=1;i<n;i++){
        if(s[i]==e1) e1i=i;
        if(s[i]==e2) e2i=i;
    }
    if(e1i==-1 || e2i==-1){
        std::cout << "结点未找到" << std::endl;
        return 0;
    }
    int level1=floor(log(e1i)/log(2))+1;
    int level2=floor(log(e2i)/log(2))+1;
    if(level1==level2){
        while(e1i!=e2i){
            if(e1i==e2i){
                break;
            }
            e1i/=2;
            e2i/=2;
        }
        if(e1i==e2i){
            std::cout << s[e1i] << std::endl;
            return 0;
        }
        else{
            std::cout << "结点未找到" << std::endl;
            return 0;
        }
    }
    else if(level1>level2){
        int t=level1-level2;
        for(int i=0;i<t;i++){
            e1i/=2;
        }
        while(e1i!=e2i){
            if(e1i==e2i){
                break;
            }
            e1i/=2;
            e2i/=2;
        }
        if(e1i==e2i){
            std::cout << s[e1i] << std::endl;
            return 0;
        }
        else{
            std::cout << "结点未找到" << std::endl;
            return 0;
        }
    }
    else{
        int t=level2-level1;
        for(int i=0;i<t;i++){
            e2i/=2;
        }
        while(e1i!=e2i){
            if(e1i==e2i){
                break;
            }
            e1i/=2;
            e2i/=2;
        }
        if(e1i==e2i){
            std::cout << s[e1i] << std::endl;
            return 0;
        }
        else{
            std::cout << "结点未找到" << std::endl;
            return 0;
        }
    }
    return 0;
}