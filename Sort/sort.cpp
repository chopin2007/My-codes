#include<iostream>
#include<sstream>
#include<string>
#include<vector>


void traversal(std::vector<int>& list){
    for(int i=0;i<list.size();i++){
        std::cout << list[i] << ' ';
    }
    std::cout << std::endl;
}

void InsertionSort(std::vector<int>& list){
    for(int i=1;i<list.size();i++){
        int e=list[i];
        int j=i;
        while(j>0 && list[j-1]>e){
            list[j]=list[j-1];
            j--;
        }
        list[j]=e;
        traversal(list);
    }
    traversal(list);
}

void BubbleSort(std::vector<int>& list){
    for(int i=0;i<list.size();i++){
        for(int j=list.size()-1;j>i;j--){
            if(list[j]<list[j-1]){
                int temp=list[j-1];
                list[j-1]=list[j];
                list[j]=temp;
            }
        }
        traversal(list);
    }
    traversal(list);
}

void SelectionSort(std::vector<int>& list){
    for(int i=0;i<list.size();i++){
        int minindex=i;
        for(int j=i;j<list.size();j++){
            if(list[j]<list[minindex]){
                minindex=j;
            }
        }
        std::swap(list[minindex],list[i]);
        traversal(list);
    }
    traversal(list);
}

void PancakeSort(std::vector<int>& list){
    for(int i=0;i<list.size();i++){
        int maxindex=0;
        for(int j=0;j<list.size()-i;j++){
            if(list[j]>list[maxindex]){
                maxindex=j;
            }
        }
        for(int j=0;j<=maxindex/2;j++){
            std::swap(list[j],list[maxindex-j]);
        }
        for(int j=0;j<=(list.size()-i-1)/2;j++){
            std::swap(list[j],list[list.size()-i-1-j]);
        }
        traversal(list);
    }
    traversal(list);
}

int main(int argc,char **argv){
    std::string in;
    std::getline(std::cin,in);
    std::stringstream numlist(in);
    std::vector<int> arr;
    std::string element;
    while(std::getline(numlist,element,',')){
        arr.push_back(std::stoi(element));
    }
    int choice;
    std::cin >> choice;
    switch(choice){
        case 0:
            InsertionSort(arr);
            break;
        case 1:
            BubbleSort(arr);
            break;
        case 2:
            SelectionSort(arr);
            break;
        case 3:
            PancakeSort(arr);
            break;
    }
    return 0;
}