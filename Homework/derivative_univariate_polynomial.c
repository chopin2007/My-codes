#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int coe;
    int degree;
    struct node *next;
}Node;

Node* initNode(){
    Node *head=(Node*)malloc(sizeof(Node));
    head->next=NULL;
    return head;
}

Node* get_tail(Node *l){
    Node *p=l;
    while(p->next!=NULL){
        p=p->next;
    }
    return p;
}

Node* insertTail(Node *tail,int e1,int e2){
    Node *p=(Node*)malloc(sizeof(Node));
    p->coe=e1;
    p->degree=e2;
    p->next=NULL;
    tail->next=p;
    return p;
}

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

int diff(Node *l){
    Node *pre=l;
    Node *p=l->next;
    while(p!=NULL){
        p->coe=p->coe*p->degree;
        p->degree=p->degree-1;
        if(p->degree<0){
            pre->next=NULL;
            Node *temp;
            while(p!=NULL){
                temp=p->next;
                free(p);
                p=temp;
            }
            break;
        }
        pre=p;
        p=p->next;
    }
    if(l->next==NULL) insertTail(l,0,0);
    return 1;
}

void listNode(Node *l){
    Node *p=l->next;
    while(p!=NULL){
        printf("%d %d ",p->coe,p->degree);
        p=p->next;
    }
}

int main(int argc,char *argv[]){
    int n;
    Node *list=initNode();
    if(scanf("%d",&n)!=1){
        return 0;
    }
    int num[n*2];
    for(int i=0;i<n*2;i++){
        if(scanf("%d",&num[i])!=1){
            return 0;
        }
    }
    for(int i=0;i<n*2;i+=2){
        insertTail(get_tail(list),num[i],num[i+1]);
    }
    diff(list);
    listNode(list);
}