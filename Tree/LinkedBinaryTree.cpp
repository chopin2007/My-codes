#include<iostream>
#include<queue>
#include<vector>

template <typename T>
class LinkedNode{
private:
    T value_;
    LinkedNode* left_;
    LinkedNode* right_;
public:
    LinkedNode(T v,LinkedNode* l=nullptr,LinkedNode* r=nullptr):value_(v),left_(l),right_(r){}
    T Value()const{return value_;}
    LinkedNode* LChild()const{return left_;}
    LinkedNode* RChild()const{return right_;}
    void SetLeft(LinkedNode* p){left_=p;}
    void SetRight(LinkedNode* p){right_=p;}
};

template <typename T>
class BinaryTree{
private:
    LinkedNode<T>* root_;
    void destroy(LinkedNode<T>* n){
        if(n==nullptr) return;
        destroy(n->LChild());
        destroy(n->RChild());
        delete n;
    }
    void preOrder(LinkedNode<T>* n)const{
        if(n==nullptr) return;
        std::cout << n->Value() << " ";
        preOrder(n->LChild());
        preOrder(n->RChild());
    }
    void inOrder(LinkedNode<T>* n)const{
        if(n==nullptr) return;
        inOrder(n->LChild());
        std::cout << n->Value() << " ";  
        inOrder(n->RChild());
    }
    void postOrder(LinkedNode<T>* n)const{
        if(n==nullptr) return;
        postOrder(n->LChild());
        postOrder(n->RChild());
        std::cout << n->Value() << " ";
    }
    int getHeight(LinkedNode<T>* n)const{
        if(n==nullptr) return 0;
        int lh=getHeight(n->LChild());
        int rh=getHeight(n->RChild());
        return std::max(lh,rh)+1;
    }
    int countNode(LinkedNode<T>* n)const{
        if(n==nullptr) return 0;
        return countNode(n->LChild())+countNode(n->RChild())+1;
    }
    int countLeaf(LinkedNode<T>* n)const{
        if(n==nullptr) return 0;
        if(n->LChild()==nullptr && n->RChild()==nullptr) return 1;
        return countLeaf(n->LChild())+countLeaf(n->RChild());
    }
public:
    BinaryTree(T v,LinkedNode<T>* l=nullptr,LinkedNode<T>* r=nullptr){
        root_=new LinkedNode<T>(v,l,r);
    }
    BinaryTree(LinkedNode<T>* root):root_(root){}
    BinaryTree():root_(nullptr){}
    ~BinaryTree(){
        destroy(root_);
    }
    void PreOrder()const{
        preOrder(root_);
        std::cout << std::endl;
    }
    void InOrder()const{
        inOrder(root_);
        std::cout << std::endl;
    }
    void PostOrder()const{
        postOrder(root_);
        std::cout << std::endl;
    }
    int GetHeight()const{
        return getHeight(root_);
    }
    int CountNode()const{
        return countNode(root_);
    }
    int CountLeaf()const{
        return countLeaf(root_);
    }
    void LevelOrder()const{
        std::queue<LinkedNode<T>*> q;
        q.push(root_);
        while(!q.empty()){
            LinkedNode<T>* ptr=q.front();
            q.pop();
            if(ptr!=nullptr){
                std::cout << ptr->Value() << " ";
                q.push(ptr->LChild());
                q.push(ptr->RChild());
            }
        }
        std::cout << std::endl;
    }
};

template <typename T>
BinaryTree<T> CompleteBinaryTree(const std::vector<T>& a){
    if(a.empty()) return BinaryTree<T>();
    int n=a.size();
    std::vector<LinkedNode<T>*> nodes(n+1);
    for(int i=1;i<=n;i++){
        nodes[i]=new LinkedNode<T>(a[i-1]);
    }
    for(int i=1;i<=n;i++){
        if(2*i<=n) nodes[i]->SetLeft(nodes[2*i]);
        if(2*i+1<=n) nodes[i]->SetRight(nodes[2*i+1]);
    }
    return BinaryTree<T>(nodes[1]);
}

int main(int argc,char * argv[]){
    LinkedNode<int>* n1=new LinkedNode<int>(1);
    LinkedNode<int>* n2=new LinkedNode<int>(2);
    LinkedNode<int>* n3=new LinkedNode<int>(3,n1,n2);
    LinkedNode<int>* n4=new LinkedNode<int>(4);
    LinkedNode<int>* n5=new LinkedNode<int>(5,n4,nullptr);
    BinaryTree<int> tree1(6,n5,n3);
    std::cout << "前序:";
    tree1.PreOrder();
    std::cout << "中序:";
    tree1.InOrder();
    std::cout << "后序:";
    tree1.PostOrder();
    std::cout << "层序:";
    tree1.LevelOrder();
    std::cout << "树的高：" << tree1.GetHeight() << std::endl;
    std::cout << "结点数量：" << tree1.CountNode() << std::endl;
    std::cout << "叶子结点数量：" << tree1. CountLeaf() << std::endl;
    std::cout << "----------------------------" << std::endl;
    std::vector<int> arr={1,2,3,4,5,6,7,8,9,10};
    BinaryTree<int> tree2=CompleteBinaryTree(arr);
    std::cout << "前序:";
    tree2.PreOrder();
    std::cout << "中序:";
    tree2.InOrder();
    std::cout << "后序:";
    tree2.PostOrder();
    std::cout << "层序:";
    tree2.LevelOrder();
    std::cout << "树的高：" << tree2.GetHeight() << std::endl;
    std::cout << "结点数量：" << tree2.CountNode() << std::endl;
    std::cout << "叶子结点数量：" << tree2. CountLeaf() << std::endl;
    return 0;
}