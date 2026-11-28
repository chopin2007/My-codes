#include<iostream>
#include<vector>
#include<stack>

class Node{
private:
    int val_;
    Node* lchild_;
    Node* rchild_;
public:
    Node(int v,Node* l=nullptr,Node* r=nullptr):val_(v),lchild_(l),rchild_(r){}
    int Val()const{return val_;}
    Node* Lchild()const{return lchild_;}
    Node* Rchild()const{return rchild_;}
    void SetVal(int v){val_=v;}
    void SetLchild(Node* l){lchild_=l;}
    void SetRchild(Node* r){rchild_=r;}
};

class BST{
private:
    Node* root_;
public:
    BST(Node* r=nullptr):root_(r){}
    void Insert(int v){
        Node* newNode=new Node(v);
        Node* fa=nullptr;
        Node* p=root_;
        while(p!=nullptr){
            fa=p;
            if(p->Val()>v){
                p=p->Lchild();
            }
            else{
                p=p->Rchild();
            }
        }
        if(fa!=nullptr){
            if(v<fa->Val()){
                fa->SetLchild(newNode);
            }
            else{
                fa->SetRchild(newNode);
            }
        }
        else root_=newNode;
    }
    void preorder()const{
        if(root_==nullptr) return;
        std::stack<Node*> s;
        s.push(root_);
        while(!s.empty()){
            Node* p=s.top();
            s.pop();
            std::cout << p->Val() << " ";
            if(p->Rchild()) s.push(p->Rchild());
            if(p->Lchild()) s.push(p->Lchild());
        }
    }
};

int main(){
    int n;
    std::cin >> n;
    int a;
    BST bst;
    for(int i=0;i<n;i++){
        std::cin >> a;
        bst.Insert(a);
    }
    bst.preorder();
    return 0;
}