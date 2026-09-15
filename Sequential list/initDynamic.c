#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef int ElemType;

typedef struct{
    ElemType *data;
    int length;
}Seqlist;

Seqlist* initlist(){
    Seqlist *L=(Seqlist*)malloc(sizeof(Seqlist));
    L->data=(ElemType*)malloc(sizeof(ElemType)*MAXSIZE);
    L->length=0;
    return L;
}
//在尾部添加元素
int appendElem(Seqlist *l,ElemType e){
    if(l->length>=MAXSIZE){
        printf("已满！\n");
        return 0;
    }
    l->data[l->length]=e;
    l->length++;
    return 1;
}

//遍历
void listElem(Seqlist *l){
    for (int i=0;i<l->length;i++){
        printf("%d ",l->data[i]);
    }
    printf("\n");
}

//插入
int insertElem(Seqlist *l,int pos,ElemType e){
    if(l->length>=MAXSIZE){
        printf("已满！\n");
        return 0;
    }
    if(pos<1 || pos>l->length){
        printf("位置错误，此处无法插入。\n");
        return 0;
    }
    if(pos<=l->length){
        for(int i=l->length-1;i>=pos-1;i--){
            l->data[i+1]=l->data[i];
        }
        l->data[pos-1]=e;
        l->length++;
        return 1;
    }
}

//删除
int deleteElem(Seqlist *l,int pos,ElemType *e){
    if(l->length==0){
        printf("空表！\n");
        return 0;
    }
    if(pos<1 || pos>l->length){
        printf("位置错误，此处无法删除。\n");
        return 0;
    }
    else{
        *e=l->data[pos-1];
        for(int i=pos-1;i<=l->length-2;i++){
            l->data[i]=l->data[i+1];
        }
        l->length--;
        return 1;
    }
}

//查找
int findElem(Seqlist *l,ElemType e){
    for(int i=0;i<l->length;i++){
        if(l->data[i]==e){
            return i+1;
        }
    }
    return 0;
}

int main(int argc,char const *argv[]){
    //声明并初始化
    Seqlist *list=initlist();
    printf("初始化成功，长度占用%d\n",list->length);
    printf("占用内存%d字节\n",sizeof(list->data));
    appendElem(list,48);
    appendElem(list,65);
    appendElem(list,97);
    listElem(list);
    insertElem(list,2,18);
    listElem(list);
    ElemType delData;
    deleteElem(list,3,&delData);
    listElem(list);
    printf("被删除的数据是：%d\n",delData);
    printf("%d\n",findElem(list,18));
    return 0;
}