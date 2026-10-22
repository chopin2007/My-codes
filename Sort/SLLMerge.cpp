#include<iostream>

template<typename T>
class Node{
private:
    T val;
    Node<T>* next;
public:
    Node(T v,Node* n=nullptr):val(v),next(n){}
    int Val(){return val;}
    Node<T>* Next()const{return next;}
    void SetNext(Node<T>* x){next=x;}
};

template<typename T>
class Nodelist{
private:
    Node<T>* head;
    Node<T>* tail;
public:
    Nodelist(){head=nullptr;tail=nullptr;}
    Node<T>* Head()const{return head;}
    void SetHead(Node<T>* n){head=n;}
    void pushback(T n){
        Node<T>* newNode=new Node<T>(n);
        if(!tail){
            head=newNode;
            tail=newNode;
        }
        else{
            tail->SetNext(newNode);
            tail=newNode;
        }
    }
    T Get(int t){
        Node<T>* p=head;
        for(int i=0;i<t-1 && p!=nullptr;i++){
            p=p->Next();
        }
        return p->Val();
    }
    void Print(){
        Node<T>* p=head;
        while(p->Next()!=nullptr){
            std::cout << p->Val() << ",";
            p=p->Next();
        }
        std::cout << p->Val() << std::endl;
    }
};

template<typename T>
Nodelist<T>* SLLMerge(Nodelist<T>* x1,Nodelist<T>* x2){
    Node<T>* p1=x1->Head();
    Node<T>* p2=x2->Head();
    Node<T>* pre=nullptr;
    while(p2!=nullptr){
        while(p1!=nullptr && p1->Val()<=p2->Val()){
            pre=p1;
            p1=p1->Next();
        }
        Node<T>* temp=p2;
        p2=p2->Next();
        temp->SetNext(p1);
        if(pre==nullptr){
            x1->SetHead(temp);
        }
        else{
            pre->SetNext(temp);
        }
        pre=temp;
    }
    return x1;
}

int main(int argc,char ** argv){
    int arr1[]={1,3,4,7,18,99};
    int arr2[]={2,5,6,8,101};
    Nodelist<int>* l1=new Nodelist<int>();
    Nodelist<int>* l2=new Nodelist<int>();
    for(int i=0;i<sizeof(arr1)/sizeof(int);i++){
        l1->pushback(arr1[i]);
    }
    for(int i=0;i<sizeof(arr2)/sizeof(int);i++){
        l2->pushback(arr2[i]);
    }
    Nodelist<int>* res=SLLMerge(l1,l2);
    res->Print();
    return 0;
}