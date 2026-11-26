#include<iostream>
#include<stack>
#include<vector>
#include<queue>

int n,m;
std::priority_queue<int,std::vector<int>,std::greater<int>> minheap;
std::priority_queue<int> maxheap;

bool IsFull(const std::stack<int>& s){
    return s.size()==m;
}

bool IsEmpty(const std::stack<int>& s){
    return s.size()==0;
}

void push(std::vector<std::stack<int>>& s,int id){
    if(minheap.empty()) return;
    s[minheap.top()].push(id);
    if(IsFull(s[minheap.top()])) minheap.pop();
    else if(s[minheap.top()].size()==1) maxheap.push(minheap.top());
}

int pop(std::vector<std::stack<int>>& s){
    if(maxheap.empty()) return -1;
    int e=s[maxheap.top()].top();
    s[maxheap.top()].pop();
    if(IsEmpty(s[maxheap.top()])) maxheap.pop();
    else if(s[maxheap.top()].size()==m-1) minheap.push(maxheap.top());
    return e;
}

int popAt(std::vector<std::stack<int>>& s,int k){
    if(s[k].empty()) return -1;
    else return s[k].top();
}

int main(){
    std::cin >> n >> m;
    std::vector<std::stack<int>> s(n);
    for(int i=0;i<n;i++){
        minheap.push(i);
    }
    push(s,1);
    push(s,2);
    push(s,3);
    push(s,4);
    push(s,5);
    push(s,6);
    push(s,7);
    push(s,8);
    push(s,9);
    pop(s);
    pop(s);
    std::cout << popAt(s,1) << std::endl;
    return 0;
}