#include<iostream>
#include<string>

class Node{
private:
    char val_;
    Node* lchild_;
    Node* rchild_;
public:
    Node(char c,Node* l=nullptr,Node* r=nullptr):val_(c),lchild_(l),rchild_(r){}
    char Val()const{return val_;}
    Node* Lchild()const{return lchild_;}
    Node* Rchild()const{return rchild_;}
    void SetLchild(Node* l){lchild_=l;}
    void SetRchild(Node* r){rchild_=r;}
};

class Tree{
private:
    Node* root_;
    void postOrder(Node* n)const{
        if(n==nullptr) return;
        if(n->Lchild()!=nullptr) postOrder(n->Lchild());
        if(n->Rchild()!=nullptr) postOrder(n->Rchild());
        std::cout << n->Val();
    }
    void destroy(Node* n){
        if(n==nullptr) return;
        destroy(n->Lchild());
        destroy(n->Rchild());
        delete n;
    }
public:
    Tree(Node* r):root_(r){}
    ~Tree(){
        destroy(root_);
    }
    void PostOrder()const{
        postOrder(root_);
        std::cout << "\n";
    }
    bool Empty()const{
        return root_==nullptr;
    }
};

Node* Build(const std::string& pre,const std::string& in,int lp,int rp,int lin,int rin,bool& invalid){
    if(invalid || lp > rp) return nullptr;
    Node* node=nullptr;
    if(lp<=rp){
        node=new Node(pre[lp]);
        int j=lin;
        while(in[j]!=pre[lp] && j<=rin){
            j++;
        }
        if(j>rin){
            invalid = true;
            return nullptr;
        }
        node->SetLchild(Build(pre,in,lp+1,lp+j-lin,lin,j-1,invalid));
        node->SetRchild(Build(pre,in,lp+j-lin+1,rp,j+1,rin,invalid));
    }
    return node;
}

int main(){
    std::string pre,in;
    std::cin >> pre >> in;
    bool invalid = false;
    if(pre.size()!=in.size()){
        std::cout << "0" << std::endl;
        return 0;
    }
    Node* root=Build(pre,in,0,pre.size()-1,0,in.size()-1,invalid);
    if(invalid){
        std::cout << "0\n";
    }
    else{
        Tree t(root);
        t.PostOrder();
    }
    return 0;
}