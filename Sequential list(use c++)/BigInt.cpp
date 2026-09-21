#include<iostream>
#include<math.h>
#include<stdexcept>
#define MAXSIZE 100

class List{
private:
    int *data;
    int last;
public:
    List(){
        data=new int[MAXSIZE];
        last=0;
        for(int i=0;i<MAXSIZE;i++) data[i]=0;
    }
    ~List(){
        delete[] data;
    }
    int length(){
        return last+1;
    }
    int Data(int n){
        return data[n];
    }
    int Last(){
        return last;
    }
    bool IsEmpty(){
        return last==0 && data[0]==0;
    }
    void Insert(const int& d){
        if(IsEmpty()){
            data[0]=d;
            last=0;
            return;
        }
        if(last<MAXSIZE-1){
            data[last+1]=d;
            last++;
            return;
        }
        else throw std::out_of_range("错误，原因：顺序表超出最大范围。");
    }
    void setData(int p,int n){
        data[p]=n;
    }
    void setLast(int n){
        last=n;
    }
    void copy(List* L){
        last=L->length()-1;
        for(int i=0;i<L->length();i++) data[i]=L->Data(i);
    }
};

void printList(List* l){
    if(l->IsEmpty()) std::cout << 0 << std::endl;
    else{
        for(int i=l->length()-1;i>=0;i--){
            std::cout << l->Data(i);
        }
        std::cout << std::endl;
    }
}

List* plus(List* l1,List* l2){
    List* l3=new List();
    if(l1->IsEmpty()){
        if(!l2->IsEmpty())
            l3->copy(l2);
    }
    else if(l2->IsEmpty()){
        l3->copy(l1);
    }
    else{
        int n=std::max(l1->length(),l2->length());
        bool count=false;
        for(int i=0;i<=n;i++){
            l3->setData(i,l1->Data(i)+l2->Data(i));
            if(count) l3->setData(i,l3->Data(i)+1);
            if(l3->Data(i)%10!=l3->Data(i)){
                l3->setData(i,l3->Data(i)%10);
                count=true;
            }
            else count=false;
        }
        if(l3->Data(n)!=0) l3->setLast(n);
        else l3->setLast(n-1);
    }
    return l3;
}

int main(int argc,char **argv){
    List* l1=new List();
    List* l2=new List();
    int a[]={1,3,2,0,3,5};
    int b[]={0,3,0,3,2,6};
    l1->setLast(l1->Last()-1);
    l2->setLast(l2->Last()-1);
    for(int i=0;i<sizeof(a)/sizeof(int);i++) {l1->setData(i,a[i]);l1->setLast(l1->Last()+1);}
    for(int i=0;i<sizeof(b)/sizeof(int);i++) {l2->setData(i,b[i]);l2->setLast(l2->Last()+1);}
    printList(l1);
    printList(l2);
    List* l3=plus(l1,l2);
    printList(l3);
    return 0;
}