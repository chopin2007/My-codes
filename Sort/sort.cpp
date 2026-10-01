#include<iostream>
#include<sstream>
#include<string>
#include<vector>

void InsertionSort(std::vector<int>& list){
    for(int i=1;i<list.size();i++){
        int e=list[i];
        int j=i;
        while(j>0 && list[j-1]>e){
            list[j]=list[j-1];
            j--;
        }
        list[j]=e;
    }
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
    }
}

void SelectionSort(std::vector<int>& list){
    for(int i=0;i<list.size();i++){
        int min=list[i];
        int index=i;
        for(int j=i;j<list.size();j++){
            if(list[j]<min){
                min=list[j];
                index=j;
            }
        }
        int temp=list[i];
        list[i]=min;
        list[index]=temp;
    }
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
        case 1:
            BubbleSort(arr);
        case 2:
            SelectionSort(arr);
    }
    for(int i=0;i<arr.size();i++){
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
    return 0;
}