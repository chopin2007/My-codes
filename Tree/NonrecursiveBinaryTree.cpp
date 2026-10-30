#include<iostream>
#include<stack>
#include<vector>

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
    BinaryTree(LinkedNode<T>* root=nullptr):root_(root){}
    ~BinaryTree(){
        if(root_==nullptr) return;
        std::stack<LinkedNode<T>*> s1,s2;
        s1.push(root_);
        while(!s1.empty()){
            LinkedNode<T>* p=s1.top();
            s1.pop();
            s2.push(p);
            if(p->RChild()) s1.push(p->RChild());
            if(p->LChild()) s2.push(p->LChild());
        }
        while(!s2.empty()){
            delete s2.top();
            s2.pop();
        }
        root_=nullptr;
    }
    void PreOrder()const{
        if(root_==nullptr) return;
        std::stack<LinkedNode<T>*> s;
        s.push(root_);
        while(!s.empty()){
            LinkedNode<T>* p=s.top();
            s.pop();
            std::cout << p->Value() << " ";
            if(p->RChild()) s.push(p->RChild());
            if(p->LChild()) s.push(p->LChild());
        }
        std::cout << std::endl;
    }
    void InOrder()const{
        std::stack<LinkedNode<T>*> s;
        LinkedNode<T>* p=root_;
        while(p!=nullptr || !s.empty()){
            while(p!=nullptr){
                s.push(p);
                p=p->LChild();
            }
            p=s.top();
            s.pop();
            std::cout << p->Value() << " ";
            p=p->RChild();
        }
        std::cout << std::endl;
    }
    void PostOrder()const{
        if(root_==nullptr) return;
        std::stack<LinkedNode<T>*> s1,s2;
        s1.push(root_);
        while(!s1.empty()){
            LinkedNode<T>* p=s1.top();
            s1.pop();
            s2.push(p);
            if(p->RChild()) s1.push(p->RChild());
            if(p->LChild()) s1.push(p->LChild());
        }
        while(!s2.empty()){
            std::cout << s2.top()->Value() << " ";
            s2.pop();
        }
        std::cout << std::endl;
    }
};

template<typename T>
BinaryTree<T> CompleteBinaryTree(const std::vector<T>& a){
    if(a.empty()) return BinaryTree<T>();
    int n=a.size();
    std::vector<LinkedNode<T>*> nodes(n+1);
    for(int i=1;i<n+1;i++){
        nodes[i]=new LinkedNode<T>(a[i-1]);
    }
    for(int i=1;i<n+1;i++){
        if(2*i<=n) nodes[i]->SetLeft(nodes[2*i]);
        if(2*i+1<=n) nodes[i]->SetRight(nodes[2*i+1]);
    }
    return BinaryTree<T>(nodes[1]);
}

int main(int argc,char *argv[]){
    std::vector<int> arr={1,2,3,4,5,6,7,8,9,10,11};
    BinaryTree<int> tree1=CompleteBinaryTree(arr);
    std::cout << "前序：";
    tree1.PreOrder();
    std::cout << "中序：";
    tree1.InOrder();
    std::cout << "后序：";
    tree1.PostOrder();
    return 0;
}