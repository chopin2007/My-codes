#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;

typedef struct node{
    ElemType data;
    struct node *next;
}Node;

//初始化
Node* initlist(){
    Node *head=(Node*)malloc(sizeof(Node));
    head->data=0;
    head->next=NULL;
    return head;
}

//头插法
int insertHead(Node *l,ElemType e){
    Node *p=(Node*)malloc(sizeof(Node));
    p->data=e;
    p->next=l->next;
    l->next=p;
}

//找到尾节点
Node* get_tail(Node *l){
    Node *p=l;
    while(p->next!=NULL){
        p=p->next;
    }
    return p;
}

//尾插法
Node* insertTail(Node *tail,ElemType e){
    Node *p=(Node*)malloc(sizeof(Node));
    p->data=e;
    p->next=NULL;
    tail->next=p;
    return p;//返回尾结点，以便递归
}

//指定位置插入
int insertNode(Node *l,int n,ElemType e){
    Node *head=l;
    for(int i=1;i<n;i++){
        if(head!=NULL) head=head->next;
        else return 0;
    }
    Node *p=(Node*)malloc(sizeof(Node));
    p->data=e;
    p->next=head->next;
    head->next=p;
    return 1;
}

//指定位置删除
int deleteNode(Node *l,int n){
    Node *head=l;
    for(int i=1;i<n;i++){
        if (head!=NULL) head=head->next;
        else return 0;
    }
    if(head->next==NULL){
        return 0;
    }
    Node *p=head->next;
    head->next=p->next;
    free(p);
    return 1;
}

//获取列表长度
int listLength(Node *l){
    Node *p=l;
    int n=0;
    while(p->next!=NULL){
        p=p->next;
        n++;
    }
    return n;
}

//查找倒数第k个结点，输出data域的值
ElemType kthlast(Node *l,int k){
    Node *p=l->next;
    for(int i=1;i<k;i++){
        if(p->next!=NULL) p=p->next;
        else return 0;
    }
    Node *q=l->next;
    while(p->next!=NULL){
        p=p->next;
        q=q->next;
    }
    printf("%d\n",q->data);
    return 1;
}

//遍历
void listNode(Node *l){
    Node *p=l->next;
    while(p!=NULL){
        printf("%d\n",p->data);
        p=p->next;
    }
    printf("\n");
}

//释放链表
void listfree(Node *l){
    Node *p=l->next;
    Node *q;
    while(p!=NULL){
        q=p->next;
        free(p);
        p=q;
    }
    l->next=NULL;
}

int main(int argc,char const argv[]){
    Node *list=initlist();
    insertTail(get_tail(list),10);
    insertTail(get_tail(list),20);
    insertTail(get_tail(list),30);
    insertTail(get_tail(list),40);
    insertTail(get_tail(list),50);
    insertNode(list,2,15);
    insertNode(list,2,12);
    deleteNode(list,3);
    printf("%d\n",listLength(list));
    listNode(list);
    kthlast(list,5);
    listfree(list);
    printf("%d\n",listLength(list));
    return 0;
}