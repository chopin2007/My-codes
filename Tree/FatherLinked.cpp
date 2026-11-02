#include<iostream>

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
    Node* root_;
public:
    Tree(Node* r):root_(r){}
    ~Tree()
};

int main(int argc,char * argv[]){

}