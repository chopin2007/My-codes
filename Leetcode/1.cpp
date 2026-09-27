#include<iostream>
#include<sstream>
#include<string>
#include<vector>

int main(int argc,char **argv){
    std::string s;
    std::getline(std::cin,s);
    std::string numlist=s.substr(s.find('[')+1,s.find(']')-s.find('[')-1);
    std::stringstream ss1(numlist);
    std::vector<int> arr;
    std::string element;
    while(std::getline(ss1,element,',')){
        arr.push_back(std::stoi(element));
    }
    size_t k=s.find("target")+9;
    std::string chara;
    while(k!=s.size()){
        chara+=s[k];
        k++;
    }
    int target=std::stoi(chara);
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr.size();j++){
            if(arr[i]+arr[j]==target){
                printf("[%zu,%zu]",i,j);
                return 0;
            }
        }
    }
}