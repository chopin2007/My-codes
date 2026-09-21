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
    Node<T>* Search(const T& d)const{
        Node<T> *p=head->next();
        while(p!=nullptr && d!=p->data()){
            p=p->next();
        }
        if(p!=nullptr) return p;
        else throw std::runtime_error("错误，原因：空表或未查询到指定元素。");
    }
    void Insert(int n,const T& d){
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
            head=head->next();
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
    DNode<T>* Search(const T& d)const{
        DNode<T> *p=head;
        while(p!=nullptr && d!=p->data()){
            p=p->next();
        }
        if(p!=nullptr) return p;
        else throw std::runtime_error("错误，原因：空表或未查询到指定元素。");
    }
    void Insert(int n,const T& d){
        if(n<1) throw std::out_of_range("错误，原因：位置不合法。");
        if(head==nullptr){
            if(n!=1) throw std::out_of_range("错误，原因：位置不合法。");
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
        int i;
        for(i=1;i<n-1 && p->next()!=nullptr;i++){
            p=p->next();
        }
        if(i<n-1) throw std::out_of_range("错误，原因：位置不合法。");
        DNode<T> *newNode=new DNode<T>(d,p,p->next());
        if(p->next()!=nullptr) p->next()->setPrior(newNode);
        p->setNext(newNode);
    }
    void Remove(int n){
        if(n<1 || IsEmpty()) throw std::out_of_range("错误，原因：空表或位置不合法。");
        if(n==1){
            DNode<T> *temp=head;
            head=head->next();
            if(head!=nullptr) head->setPrior(nullptr);
            delete temp;
            return;
        }
        DNode<T> *p=head;
        int i;
        for(i=1;i<n-1;i++){
            if(p->next()==nullptr) throw std::out_of_range("错误，原因：位置不合法");
            p=p->next();
        }
        DNode<T> *temp=p->next();
        if(temp==nullptr) throw std::out_of_range("错误，原因：位置不合法。");
        p->setNext(temp->next());
        if(temp->next()!=nullptr) temp->next()->setPrior(p);
        delete p;
    }
    DNode<T>* Reset(){
        current=head;
        return current;
    }
    bool hasNext(){
        return current!=nullptr && current->next()!=nullptr;
    }
    DNode<T>* next(){
        if(current!=nullptr) {current=current->next();return current;}
        else throw std::out_of_range("错误，原因：空姐带你无后继");
    }
};

//循环双向链表
template<typename T>
class CycleLinkedList{
private:
    DNode<T>* head;
    DNode<T>* current;
public:
    CycleLinkedList(){
        head=nullptr;
        current=nullptr;
    }
    ~CycleLinkedList(){
        while(head!=nullptr){
            DNode<T> temp=head;
            head=head->next();
            delete temp;
        }
    }
    bool IsEmpty(){
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
        if(n<1 || IsEmpty()) throw std::out_of_range("错误，原因：空表或位置不合法。");
        DNode<T> *p=head;
        int j=n;
        while(j>length()){
            j=j%length();
        }
        for(int i=0;i<j-1;i++){
            p=p->next();
        }
        return p->data();
    }
    //T Get()
    DNode<T>* Search(const T& d)const{
        if(IsEmpty()) throw std::out_of_range("错误，原因：空表。");
        DNode<T> *p=head;
        for(int i=0;i<length();i++){
            if(p->data==d) break;
            p=p->next();
        }
        if(p->data==d) return p;
        else throw std::runtime_error("错误，原因：未查询到指定元素。");
    }
    void Insert(int n,const T& d){
        if(n<1 || n>length()+1) throw std::out_of_range("错误，原因：位置不合法。");
        if(IsEmpty()){
            DNode<T> *p=new DNode<T>(d);
            p->setPrior(p);
            p->setNext(p);
            head=p;
            return;
        }
        DNode<T> *p=head;
        for(int i=0;i<n && p->next();i++){
            p=p->next();
        }
        DNode<T> *newNode=new DNode<T>(d);
        newNode->setNext(p);
        newNode->setPrior(p->prior);
        p->prior()->setNext(newNode);
        p->prior(newNode);
        if(n==1) head==newNode;
    }
    //void Remove()
    //DNode<T>* Reset()
    //DNode<T>* next()
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

void ListSLL(DoubleLinkedList<int>& l,int n){
    if(!l.IsEmpty()){
        DNode<int> *p=l.Reset();
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
    SinglyLinkedList<int> list1;
    for(int i=0; i<7; i++) {
        list1.Insert(1, a[i]);
    }
    ListSLL(list1,list1.length());
    list1.Remove(3);
    ListSLL(list1,list1.length());
    int b[] = {1,2,3,4,5,6,7};
    DoubleLinkedList<int> list2;
    for(int i=0; i<7; i++) {
        list2.Insert(1, a[i]);
    }
    ListSLL(list2,list2.length());
    list2.Remove(3);
    ListSLL(list2,list2.length());
    return 0;
}