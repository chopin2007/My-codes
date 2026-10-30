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
    LinkedNode<T>* preOrderDeSerialize(const std::vector<T>& a,int& idx,const T& nullmark){
        if(idx>=a.size() || a[idx]==nullmark){
            idx++;
            return nullptr;
        }
        LinkedNode<T>* node=new LinkedNode<T>(a[idx++]);
        node->SetLeft(preOrderDeSerialize(a,idx,nullmark));
        node->SetRight(preOrderDeSerialize(a,idx,nullmark));
        return node;
    }
public:
    BinaryTree(T v,LinkedNode<T>* l=nullptr,LinkedNode<T>* r=nullptr){
        root_=new LinkedNode<T>(v,l,r);
    }
    BinaryTree(const std::vector<T>& a,const T& nm){
        if(a.empty()) root_=nullptr;
        int idx=0;
        root_=preOrderDeSerialize(a,idx,nm);
    }
    BinaryTree(LinkedNode<T>* root=nullptr):root_(root){}
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

template<typename T>
LinkedNode<T>* PreInTravDeSerialize(const std::vector<T>& pre,const std::vector<T>& in,int lp,int rp,int lin,int rin){
    LinkedNode<T>* root=nullptr;
    if(lp<=rp){
        root=new LinkedNode<T>(pre[lp]);
        int i=lin;
        while(in[i]!=pre[lp]){
            i++;
        }
        root->SetLeft(PreInTravDeSerialize(pre,in,lp+1,lp+i-lin,lin,i-1));
        root->SetRight(PreInTravDeSerialize(pre,in,lp+i-lin+1,rp,i+1,rin));
    }
    return root;
}

int main(int argc,char * argv[]){
    //建树
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
    //快速建完全二叉树
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
    std::cout << "----------------------------" << std::endl;
    //前序序列反序列化
    std::vector<char> arr2={'A','B','D','H','#','#','I','#','#','E','#','J','#','#','C','F','#','K','#','#','#'};
    BinaryTree<char> tree3(arr2,'#');
    std::cout << "前序:";
    tree3.PreOrder();
    std::cout << "中序:";
    tree3.InOrder();
    std::cout << "后序:";
    tree3.PostOrder();
    std::cout << "层序:";
    tree3.LevelOrder();
    std::cout << "树的高：" << tree3.GetHeight() << std::endl;
    std::cout << "结点数量：" << tree3.CountNode() << std::endl;
    std::cout << "叶子结点数量：" << tree3. CountLeaf() << std::endl;
    std::cout << "----------------------------" << std::endl;
    //根据前序遍历和中序遍历建树（反序列化）
    std::vector<char> pre={'A','B','D','H','I','E','J','C','F','K'};
    std::vector<char> in={'H','D','I','B','E','J','A','F','K','C'};
    BinaryTree<char> tree4(PreInTravDeSerialize(pre,in,0,pre.size()-1,0,in.size()-1));
    std::cout << "前序:";
    tree4.PreOrder();
    std::cout << "中序:";
    tree4.InOrder();
    std::cout << "后序:";
    tree4.PostOrder();
    std::cout << "层序:";
    tree4.LevelOrder();
    std::cout << "树的高：" << tree4.GetHeight() << std::endl;
    std::cout << "结点数量：" << tree4.CountNode() << std::endl;
    std::cout << "叶子结点数量：" << tree4. CountLeaf() << std::endl;
    return 0;
}