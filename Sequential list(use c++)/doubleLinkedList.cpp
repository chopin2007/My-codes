#include<iostream>
using namespace std;

typedef int ElemType;
typedef struct node{
    ElemType data;
    struct node *next;
    struct node *prior;
}Node;

class douList{
private:
    Node *head;
public:
    //初始化
    douList(){
        head=nullptr;
    }
    ~douList(){
        Node *p=head;
        while(p!=nullptr){
            Node *temp=p;
            p=p->next;
            delete temp;
        }
        head=nullptr;
    }
    //头插入
    int insertHead(ElemType e){
        Node *p=new Node;
        p->data=e;
        p->prior=nullptr;
        p->next=head;
        head=p;
        return 1;
    }
    //尾插法
    int insertTail(ElemType e){
        Node *p=new Node;
        p->data=e;
        p->next=nullptr;
        if(head==nullptr){
            p->prior=nullptr;
            head=p;
            return 1;
        }
        Node *q=head;
        while(q->next!=nullptr){
            q=q->next;
        }
        p->prior=q;
        q->next=p;
        return 1;
    }
    //找出倒数第k个结点
    Node* kthLast(int k){
        Node *p=head;
        Node *q=head;
        for(int i=1;i<k;i++){
            if(p->next!=nullptr) p=p->next;
            else return 0;
        }
        while(p->next!=nullptr){
            p=p->next;
            q=q->next;
        }
        return q;
    }
    //指定位置插入
    int insertNode(int n,ElemType e){
        if(n<0) return 1;
        if(n==1) {insertHead(e); return 0;}
        Node *p=head;
        for(int i=1;i<n-1;i++){
            if(p->next==nullptr) return 0;
            p=p->next;
        }
        if(p==nullptr) return 0;
        Node *newNode=new Node;
        newNode->data=e;
        newNode->next=p->next;
        newNode->prior=p;
        if(p->next==nullptr) p->next->prior=newNode;
        p->next=newNode;
        return 1;
    }
    //倒装
    int upsidedown(){
        Node *ptr=head;
        head=nullptr;
        while(ptr!=nullptr){
            Node *t_head=ptr;
            ptr=ptr->next;
            t_head->next=head;
            t_head->prior=nullptr;
            if(head!=nullptr) head->prior=t_head;
            head=t_head;
        }
        return 1;
    }
    //遍历
    void listNode(){
        Node *p=head;
        while(p!=nullptr){
            cout << p->data << " ";
            p=p->next;
        }
        cout << endl;
    }
};

int main(int argc,char **argv){
    douList list;
    list.insertHead(10);
    list.insertTail(20);
    list.insertTail(30);
    list.insertTail(40);
    list.insertTail(50);
    list.insertNode(2,19);
    cout << list.kthLast(2)->data << endl;
    list.listNode();
    list.upsidedown();
    list.listNode();
    //cin.get();
}