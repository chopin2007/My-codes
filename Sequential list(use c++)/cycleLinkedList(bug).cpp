#include<iostream>
using namespace std;
//这是有问题的，还需要修改，在这里我把头结点的前驱默认为了nullptr，导致这个双向链表反向遍历是不可行的
typedef int ElemType;
typedef struct node{
    ElemType data;
    struct node *next;
    struct node *prior;
}Node;

class cycleList{
private:
    Node *head;
public:
    cycleList(){
        head=nullptr;
    }
    cycleList(ElemType e){
        Node *newNode=new Node;
        newNode->data=e;
        newNode->next=newNode;
        newNode->prior=nullptr;
        head=newNode;
    }
    ~cycleList(){
        Node *p=head;
        while(p!=nullptr){
            Node *temp=p;
            p=p->next;
            delete temp;
            temp=nullptr;
        }
        head=nullptr;
    }
    //头插法
    int insertHead(ElemType e){
        Node *newNode=new Node;
        newNode->data=e;
        newNode->prior=nullptr;
        if(head==nullptr){
            newNode->next=newNode;
            head=newNode;
            return 1;
        }
        Node *p=head;
        while(p->next->prior!=nullptr){
            p=p->next;
        }
        p->next=newNode;
        newNode->next=head;
        head=newNode;
        newNode->next->prior=head;
        return 1;
    }
    //尾插法
    int insertTail(ElemType e){
        //cout << ""
        Node *newNode=new Node;
        newNode->data=e;
        if(head==nullptr){
            newNode->prior=nullptr;
            newNode->next=newNode;
            head=newNode;
            return 1;
        }
        Node *p=head;
        while(p->next->prior!=nullptr){
            p=p->next;
        }
        newNode->prior=p;
        newNode->next=p->next;
        p->next=newNode;
        return 1;
    }
    //指定位置插入
    int insertNode(int n,ElemType e){
        if(n==0) return 0;
        if(n==1) {insertHead(e);return 1;}
        if(head==nullptr){
            Node *newNode=new Node;
            newNode->data=e;
            newNode->prior=nullptr;
            newNode->next=newNode;
            head=newNode;
            return 1;
        }
        Node *ptr=head;
        for(int i=1;i<n-1;i++){
            if(ptr->next->prior!=nullptr && i!=n-2) ptr=ptr->next;
            else if(ptr->next->prior!=nullptr && i==n-2) {insertTail(e);return 1;}
            else break;
        }
        if(ptr->next->prior==nullptr) return 0;
        Node *newNode=new Node;
        newNode->data=e;
        newNode->next=ptr->next;
        ptr->next->prior=newNode;
        newNode->prior=ptr;
        ptr->next=newNode;
        return 1;
    }
    int listNode(){
        if(head==nullptr) return 0;
        Node *p=head;
        cout << p->data << " ";
        p=p->next;
        while(p!=head){
            cout << p->data << " ";
            p=p->next;
        }
        cout << endl;
        return 1;
    }
};

int main(int argc,char **argv){
    cycleList list(3);
    list.insertHead(5);
    list.insertHead(6);
    list.insertHead(9);
    list.insertTail(2);
    list.insertTail(1);
    list.insertNode(2,7);
    list.insertNode(1,10);
    list.insertNode(9,0);
    list.listNode();
    //cin.get()
}