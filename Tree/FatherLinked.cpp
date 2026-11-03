#include<iostream>
#include<vector>

class Node{
private:
    int val_;
    Node* fa_;
public:
    Node(int v,Node* fa=nullptr):val_(v),fa_(fa){}
    int Value()const{return val_;}
    Node* Father()const{return fa_;}
    void SetValue(int v){val_=v;}
    void SetFather(Node* f){fa_=f;}
};

class Tree{
private:
    std::vector<Node*> nodes;
    Node* root_;
public:
    Tree(){
        root_=nullptr;
    }
    Tree(int v){
        nodes.push_back(new Node(v));
        root_=nodes.front();
    }
    ~Tree(){
        for(auto &x:nodes){
            delete x;
        }
        root_=nullptr;
    }
    void addNode(int v,int pos){
        if(pos<nodes.size()){
            nodes.push_back(new Node(v,nodes[pos]));
        }
        else return;
    }
    void addNode(int v,Node* p){
        nodes.push_back(new Node(v,p));
    }
};

int main(int argc,char * argv[]){
    
}