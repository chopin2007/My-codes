#include<iostream>
#include<sstream>
#include<vector>
#include<string>
//
int maxup(std::vector<int> a){
    int max=0;
    for(int i=0;i<a.size();i++){
        int k=0;
        for(int j=i;j<a.size();j++){
            if(a[i]>a[j]) k++;
        }
        if(max<k) max=k;
    }
    return max;
}

int main(int argc,char **argv){
    std::string input;
    std::getline(std::cin,input);
    std::string numlist=input.substr(input.find('[')+1,input.find(']')-input.find('[')-1);
    std::stringstream ss(input);
    std::string element;
    std::vector<int> arr;
    while(std::getline(ss,element,',')){
        arr.push_back(std::stoi(element));
    }
    
}