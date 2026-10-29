#include<iostream>

template<typename T>
class LinkedNode{
private:
    T val;
    LinkedNode* left_;
    LinkedNode* right_;
public:
    LinkedNode(T v,LinkedNode* l=nullptr,LinkedNode* r=nullptr):val(v),left_(l),right_(r){}
    T Value()const{return val;}
    LinkedNode* LChild()const{return left_;}
    LinkedNode* RChild()const{return right_;}
    void SetLeft(LinkedNode* n){left_=n;}
    void SetRight(LinkedNode* n){right_=n;}
};

template<typename T>
class BinaryTree{
private:
    LinkedNode<T>* root_;
public:
    BinaryTree(T v,LinkedNode<T>* l=nullptr,LinkedNode<T>* r=nullptr):root_(new LinkedNode<T>(v,l,r)){}
    BinaryTree(LinkedNode<T>* root):root_(root){}
    ~BinaryTree(){
        
    }
};

int main(int argc,char *argv[]){
    return 0;
}