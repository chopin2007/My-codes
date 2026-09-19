#include<iostream>
#include<stdexcept>

//结点（单向的）
template<typename T>
class Node{
private:
    T perdata;
    Node<T> *pernext;
public:
    Node(){perdata=T();pernext=nullptr;}
    Node(T d,Node<T>* n=nullptr){
        perdata=d;
        pernext=n;
    }
    T data()const{
        return perdata;
    }
    Node<T>* next(){
        return pernext;
    }
    void setNext(Node<T>* n){
        pernext=n;
    }
};

//双向结点
template<typename T>
class DNode{
private:
    T perdata;    
    DNode<T> *perprior;
    DNode<T> *pernext;
public:
    DNode(){perdata=T();perprior=nullptr;pernext=nullptr;}
    DNode(T d,DNode<T>* n1=nullptr,DNode<T>* n2=nullptr){
        perdata=d;
        perprior=n1;
        pernext=n2;
    }
    T data()const{
        return perdata;
    }
    DNode<T>* prior(){
        return perprior;
    }
    DNode<T>* next(){
        return pernext;
    }
    void setNext(DNode<T>* n){
        pernext=n;
    }
    void setPrior(DNode<T>* n){
        perprior=n;
    }
};

//单链表（含哨兵结点）
template<typename T>
class SinglyLinkedList{
private:
    Node<T>* head;
    Node<T>* current;
public:
    SinglyLinkedList(){
        head=new Node<T>;
        head->setNext(nullptr);
        current=nullptr;
    }
    ~SinglyLinkedList(){
        while(head!=nullptr){
            Node<T>* p=head;
            head=head->next();
            delete p;
        }
    }
    bool IsEmpty(){
        return head->next()==nullptr;
    }
    int length(){
        Node<T> *p=head->next();
        int count=0;
        while(p!=nullptr){
            p=p->next();
            count++;
        }
        return count;
    }
    T Get(int n)const{
        if(n<1 || IsEmpty()) throw std::runtime_error("错误，原因：空表或位置不合法。");
        Node<T> *p=head;
        for(int i=0;i<n && p!=nullptr;i++){
            p=p->next();
        }
        if(p!=nullptr) return p->data();
        else throw std::out_of_range("错误，原因：位置不合法。");
    }
    Node<T>* Search(T d)const{
        if(head->pernext==nullptr) throw std::runtime_error("错误，原因：空表无法查询。");
        Node<T> *p=head->next();
        while(p!=nullptr && d==p->data()){
            p=p->next();
        }
        if(d==p->data()) return p;
        else throw std::runtime_error("错误，原因：未查询到指定元素。");
    }
    void Insert(int n,T d){
        if(n<1) throw std::out_of_range("错误，原因：位置不合法。");
        Node<T> *p=head;
        for(int i=0;i<n-1 && p!=nullptr;i++){
            p=p->next();
        }
        if(p!=nullptr) p->setNext(new Node<T>(d,p->next()));
        else throw std::out_of_range("错误，原因：位置不合法。");
    }
    void Remove(int n){
        if(n<1) throw std::out_of_range("错误，原因：位置不合法。");
        Node<T> *p=head;
        for(int i=0;i<n-1 && p!=nullptr;i++){
            p=p->next();
        }
        if(p!=nullptr && p->next()!=nullptr){
            Node<T> *delete_node=p->next();
            p->setNext(delete_node->next());
            delete delete_node;
        }
        else throw std::out_of_range("错误，原因：位置不合法。");
    }
    bool hasNext(){
        return current!=nullptr && current->next()!=nullptr;
    }
    Node<T>* Reset(){
        current=head;
        return current;
    }
    Node<T>* next(){
        if(current!=nullptr){
            current=current->next();
            return current;
        }
        else throw std::out_of_range("错误，原因：空列表无后继。");
    }
};

//双向链表
template<typename T>
class DoubleLinkedList{
private:
    DNode<T> *head;
    DNode<T> *current;
public:
    DoubleLinkedList(){
        head=nullptr;
        current=nullptr;
    }
    ~DoubleLinkedList(){
        while(head!=nullptr){
            DNode<T> *temp=head;
            head=head->pernext;
            delete temp;
        }
    }
    bool IsEmpty()const{
        return head==nullptr;
    }
    int length(){
        DNode<T> *p=head;
        int count=0;
        while(p!=nullptr){
            p=p->next();
            count++;
        }
        return count;
    }
    T Get(int n)const{
        if(n<1 || IsEmpty()) throw std::runtime_error("错误，原因：空表或位置不合法");
        DNode<T> *p=head;
        for(int i=0;i<n-1 && p!=nullptr;i++){
            p=p->next();
        }
        if(p!=nullptr) return p->data();
        else throw std::out_of_range("错误，原因：位置不合法");
    }
    //Dnode<T>* Search()
    void Insert(int n,T d){
        if(n<1) throw std::out_of_range("错误，原因：位置不合法。");
        if(head==nullptr){
            head=new DNode<T>(d,nullptr,nullptr);
            return;
        }
        if(n==1){
            DNode<T>* newNode=new DNode<T>(d,nullptr,head);
            head->setPrior(newNode);
            head=newNode;
            return;
        }
        DNode<T>* p=head;
        for(int i=0;i<n-2 && p->next()!=nullptr;i++){
            p=p->next();
        }
        DNode<T> *newNode=new DNode<T>(d,p,p->next());
        if(p->next()!=nullptr) p->next()->setPrior(newNode);
        p->setNext(newNode);
    }
    //void Remove()
    //Dnode<T>* Reset()
    //bool hasNext()
    //Dndoe<T>* next()
};

void ListSLL(SinglyLinkedList<int>& l,int n){
    if(!l.IsEmpty()){
        Node<int> *p=l.Reset();
        while(l.hasNext()){
            p=l.next();
            std::cout << p->data() << " ";
        }
        std::cout << std::endl;
    }
    else throw std::out_of_range("错误，原因：空表无法打印。");
}

int main(int argc,char **argv){
    int a[] = {1,2,3,4,5,6,7};
    SinglyLinkedList<int> list;
    for(int i=0; i<7; i++) {
        list.Insert(1, a[i]);
    }
    ListSLL(list,list.length());
    list.Remove(3);
    ListSLL(list,list.length());
    return 0;
}