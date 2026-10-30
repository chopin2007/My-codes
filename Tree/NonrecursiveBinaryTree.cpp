#include<iostream>
#include<stack>
#include<vector>
#include<queue>

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
    void LevelOrder()const{
        if(root_==nullptr) return;
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
    int GetHeightBFS()const{
        if(root_==nullptr) return 0;
        std::queue<LinkedNode<T>*> q;
        int h=0;
        q.push(root_);
        while(!q.empty()){
            int levelsize=q.size();
            for(int i=0;i<levelsize;i++){
                LinkedNode<T>* ptr=q.front();
                q.pop();
                if(ptr->LChild()) q.push(ptr->LChild());
                if(ptr->RChild()) q.push(ptr->RChild());
            }
            h++;
        }
        return h;
    }
    int GetHeightDFS()const{
        if(root_==nullptr) return 0;
        std::stack<LinkedNode<T>*> s;
        LinkedNode<T>* p=root_;
        int h=0;
        int maxh=0;
        while(p!=nullptr || !s.empty()){
            while(p!=nullptr){
                s.push(p);
                p=p->LChild();
                h++;
            }
            maxh=std::max(maxh,h);
            p=s.top();
            s.pop();
            h--;
            p=p->RChild();
        }
        return maxh;
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
    int n=30;
    std::vector<int> arr;
    for(int i=1;i<=n;i++){
        arr.push_back(i);
    }
    BinaryTree<int> tree1=CompleteBinaryTree(arr);
    std::cout << "前序：";
    tree1.PreOrder();
    std::cout << "中序：";
    tree1.InOrder();
    std::cout << "后序：";
    tree1.PostOrder();
    std::cout << "层序：";
    tree1.LevelOrder();
    std::cout << "树的高度(BFS):" << tree1.GetHeightBFS() << std::endl;
    std::cout << "树的高度(DFS):" << tree1.GetHeightDFS() << std::endl;
    return 0;
}