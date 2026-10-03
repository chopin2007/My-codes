#include<iostream>

template<typename T>
class LinkedList{
private:
    class LinkedNode{
    private:
        T data_;
        LinkedNode *next_;
    public:
        LinkedNode(T d,LinkedNode* n):data_(d),next_(n){}
        const T& data()const{return data_;}
        LinkedNode* next()const{return next_;}
        void setNext(LinkedNode* p){next_=p;}
    };
    LinkedNode* head;
    int size;
    void destroy(){
        while(head!=nullptr){
            LinkedNode* temp=head;
            head=head->next();
            delete temp;
        }
        size=0;
    }
public:
    LinkedList(){
        head=nullptr;
        size=0;
    }
    ~LinkedList(){
        destroy();
    }
    bool IsEmpty()const{return head==nullptr && size==0;}
    T Get(int n)const{
        if(n<1 || IsEmpty()) return -1;
        LinkedNode *p=head;
        for(int i=1;i<n && p!=nullptr;i++){
            p=p->next();
        }
        if(p!=nullptr) return p->data();
        else return -1;
    }
    void add(T d,int x){
        if(x<1 || x>size+1) return;
        if(x==1){
            LinkedNode *newNode=new LinkedNode(d,head);
            head=newNode;
            size++;
            return;
        }
        LinkedNode *p=head;
        for(int i=1;i<x-1;i++){
            p=p->next();
        }
        LinkedNode *newNode=new LinkedNode(d,p->next());
        p->setNext(newNode);
        size++;
        return;
    }
    void tailAdd(T d){
        if(IsEmpty()){
            LinkedNode *newNode=new LinkedNode(d,nullptr);
            head=newNode;
            size++;
            return;
        }
        LinkedNode *p=head;
        while(p->next()!=nullptr){
            p=p->next();
        }
        LinkedNode *newNode=new LinkedNode(d,nullptr);
        p->setNext(newNode);
        size++;
        return;
    }
    void Remove(int k){
        if(k<1 || IsEmpty() || k>size) return;
        LinkedNode *p=head;
        if(k==1){
            head=head->next();
            delete p;
            size--;
            return;
        }
        for(int i=1;i<k-1;i++){
            p=p->next();
        }
        LinkedNode *temp=p->next();
        p->setNext(p->next()->next());
        delete temp;
        size--;
        return;
    }
    void Traversal(){
        if(IsEmpty()) return;
        LinkedNode *p=head;
        while(p!=nullptr){
            std::cout << p->data() << " ";
            p=p->next();
        }
        std::cout << std::endl;
        return;
    }
};

int main(int argc,char **argv){
    int arr[]={1,8,4,9,7};
    LinkedList<int> list;
    for(int i=0;i<sizeof(arr)/sizeof(int);i++){
        list.tailAdd(arr[i]);
    }
    list.Traversal();
    list.add(50,6);
    list.Traversal();
    list.Remove(3);
    list.Remove(4);
    list.Traversal();
    return 0;
}