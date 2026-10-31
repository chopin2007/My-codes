#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

class Node{
private:
    int val_;
    Node* lchild_;
    Node* rchild_;
public:
    Node(int v,Node* l=nullptr,Node* r=nullptr):val_(v),lchild_(l),rchild_(r){}
    int Value()const{return val_;}
    Node* Lchild()const{return lchild_;}
    Node* Rchild()const{return rchild_;}
    void SetValue(int v){val_=v;}
    void SetLchild(Node* l){lchild_=l;}
    void SetRchild(Node* r){rchild_=r;}
};

class Tree{
private:
    Node* root_;
public:
    Tree(Node* r):root_(r){}
    Tree(int v):root_(new Node(v)){}
    ~Tree(){
        if(root_==nullptr) return;
        std::stack<Node*> s1,s2;
        s1.push(root_);
        while(!s1.empty()){
            Node* p=s1.top();
            s1.pop();
            s2.push(p);
            if(p->Rchild()) s1.push(p->Rchild());
            if(p->Lchild()) s1.push(p->Lchild());
        }
        while(!s2.empty()){
            delete s2.top();
            s2.pop();
        }
        root_=nullptr;
    }
    void PreOrder()const{
        if(root_==nullptr) return;
        std::stack<Node*> s;
        s.push(root_);
        while(!s.empty()){
            Node* p=s.top();
            s.pop();
            std::cout << p->Value() << " ";
            if(p->Rchild()) s.push(p->Rchild());
            if(p->Lchild()) s.push(p->Lchild());
        }
        std::cout << std::endl;
    }
    void InOrder()const{
        std::stack<Node*> s;
        Node* p=root_;
        while(p!=nullptr || !s.empty()){
            while(p!=nullptr){
                s.push(p);
                p=p->Lchild();
            }
            p=s.top();
            s.pop();
            std::cout << p->Value() << " ";
            p=p->Rchild();
        }
        std::cout << std::endl;
    }
    void PostOrder()const{
        if(root_==nullptr) return;
        std::stack<Node*> s1,s2;
        s1.push(root_);
        while(!s1.empty()){
            Node* p=s1.top();
            s1.pop();
            s2.push(p);
            if(p->Rchild()) s1.push(p->Rchild());
            if(p->Lchild()) s1.push(p->Lchild());
        }
        while(!s2.empty()){
            std::cout << s2.top()->Value() << " ";
            s2.pop();
        }
        std::cout << std::endl;
    }
};

Tree CreatHuffmanTree(const std::vector<int>& a){
    int n=a.size();
    std::vector<Node*> nodes;
    for(int i=0;i<n;i++){
        nodes.push_back(new Node(a[i]));
    }
    for(int i=0;i<n-1;i++){
        Node* p=new Node(-1);
        std::sort(nodes.begin(),nodes.end(),[](const Node* a,const Node* b){
            return a->Value()>b->Value();
        });
        p->SetLchild(nodes.back());
        nodes.pop_back();
        p->SetRchild(nodes.back());
        nodes.pop_back();
        p->SetValue(p->Lchild()->Value()+p->Rchild()->Value());
        nodes.push_back(p);
    }
    return Tree(nodes.front());
}

int main(int argc,char * argv[]){
    std::vector<int> arr1={1,2,3,4,5};
    Tree t1=CreatHuffmanTree(arr1);
    std::cout << "前序：";
    t1.PreOrder();
    std::cout << "中序：";
    t1.InOrder();
    std::cout << "后序：";
    t1.PostOrder();
    return 0;
}