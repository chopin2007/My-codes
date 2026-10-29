#include<iostream>
#include<queue>

template <typename T>
class BinaryTree{
private:
    class LinkedNode{
    private:
        T value_;
        LinkedNode* left_;
        LinkedNode* right_;
    public:
        LinkedNode(T v,LinkedNode* l=nullptr,LinkedNode* r=nullptr):value_(v),left_(l),right_(r){}
        T Value()const{return value_;}
        LinkedNode* Left()const{return left_;}
        LinkedNode* Right()const{return right_;}
        void SetLeft(LinkedNode* p){left_=p;}
        void SetRight(LinkedNode* p){right_=p;}
    };
    LinkedNode* root_;
    void destroy(LinkedNode* n){
        if(n==nullptr) return;
        destroy(n->Left);
        destroy(n->Right);
        delete n;
    }
    void preOrder(LinkedNode* n)const{
        if(n==nullptr) return;
        std::cout << n->Value() << ",";
        preOrder(n->Left());
        preOrder(n->Right());
    }
    void inOrder(LinkedNode* n)const{
        if(n==nullptr) return;
        inOrder(n->Left());
        std::cout << n->Value() << ",";
        inOrder(n->right());
    }
    void postOrder(LinkedNode* n)const{
        if(n==nullptr) return;
        postOrder(n->Left());
        postOrder(n->Right());
        std::cout << n->Value() << ",";
    }
    int getHeight(LinkedNode* n)const{
        if(n==nullptr) return 0;
        int lh=getHeight(n->Left());
        int rh=getHeight(n->Right());
        return std::max(lh,rh)+1;
    }
    int countNode(LinkedNode* n)const{
        if(n==nullptr) return 0;
        return countNode(n->Left())+count(n->Right())+1;
    }
    int countLeaf(linkedNode* n)const{
        if(n==nullptr) return 0;
        if(n->Left()==nullptr && n->Right()==nullptr) return 1;
        return countLeaf(n->Left())+countLeaf(n->Right())
    }
public:
    BinaryTree(T v,LinkedNode* l=nullptr,LinkedNode* r=nullptr){
        root_=new LinkedNode(v,left,right);
    }
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
    int CountRight()const{
        return countNode(root_);
    }
    void LevelOrder()const{
        std::queue<LinkedNode*> q;
        q.push(root_);
        while(!q.empty()){
            LinkedNode* ptr=q.front();
            q.pop();
            if(ptr!=nullptr){
                std::cout << ptr->Value() << ",";
                q.push(ptr->Left());
                q.push(ptr->Right());
            }
        }
        std::cout << std::endl;
    }
};

int main(int argc,char * argv[]){
    return 0;
}