#include<iostream>
#include<sstream>
#include<vector>
#include<string>

void checkout(std::vector<std::vector<int>>& r,int& next,const int& nn){
    bool flag=true;
    while(flag){
        flag=false;
        for(int j=0;j<nn;j++){
            if(!r[j].empty() && r[j].front()==next){
                r[j].erase(r[j].begin());
                next++;
                flag=true;
                break;
            }
        }
    }
}

int main(int argc,char **argv){
    std::string input;
    std::getline(std::cin,input);
    int n;
    std::cin >> n;
    std::string numlist=input.substr(input.find('[')+1,input.find(']')-input.find('[')-1);
    std::stringstream ss(numlist);
    std::string element;
    std::vector<int> arr;
    while(std::getline(ss,element,',')){
        arr.push_back(std::stoi(element));
    }
    std::vector<std::vector<int>> rail(n);
    int next_out=1;
    for(int i=0;i<arr.size();i++){
        int pos=0;
        if(arr[i]==next_out){
            next_out++;
            checkout(rail,next_out,n);
            continue;
        }
        while(pos<n && !rail[pos].empty()){
            if(rail[pos].back()>arr[i]){
                pos++;
            }
            else break;
        }
        if(pos<n) rail[pos].push_back(arr[i]);
        else{
            std::cout << "轨道不足，无法重排。" << std::endl;
            return 0;
        }
        checkout(rail,next_out,n);
    }
    for(int i=0;i<n;i++){
        if(!rail[i].empty()){
            std::cout << "重排失败" << std::endl;
            return 0;
        }
    }
    std::cout << "重排成功！" << std::endl;
    return 0;
}