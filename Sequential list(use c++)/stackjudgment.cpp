#include<iostream>

class stack{
private:
    class node{
    private:
        int data_;
        node *next_;
    public:
        node(int d,node* p):data_(d),next_(p){}
        int data(){return data_;}
        node* next(){return next_;}
        void setNext(node* p){
            next_=p;
        }
    };
    node *top;
    int size;
    void destroy(){
        while(top!=nullptr){
            node* temp=top;
            top=top->next();
            delete temp;
        }
    }
public:
    stack(){
        top=nullptr;
        size=0;
    }
    ~stack(){
        destroy();
        size=0;
    }
    bool IsEmpty(){return top==nullptr;}
    void push(int d){
        node* newNode=new node(d,top);
        top=newNode;
        size++;
    }
    int Top(){
        if(IsEmpty()) return -1;
        else{
            return top->data();
        }
    }
    void pop(){
        if(IsEmpty()) return;
        else{
            node *temp=top;
            top=top->next();
            size--;
            delete temp;
        }
    }
};

void check(int* nu1,int* nu2,int n){
    stack s;
    char *doin=new char[n*2];
    int i=0;
    int j=0;
    int c=0;
    while(i<n){
        s.push(nu1[i]);
        doin[c]='P';
        c++;
        while(!s.IsEmpty() && s.Top()==nu2[j]){
            j++;
            s.pop();
            doin[c]='O';
            c++;
        }
        i++;
    }
    doin[c]='\0';
    if(j==n){
        std::cout << "right" << std::endl;
        std::cout << doin;
    }
    else{
        std::cout << "wrong" << std::endl;
        int remaining[10];
        int k = 0;
        while (!s.IsEmpty()) {
            remaining[k++] = s.Top();
            s.pop();
        }
        for (int m = k - 1; m >= 0; m--) {
            std::cout << remaining[m];
        }
        //std::cout << std::endl;
    }
}

int main(int argc,char **argv){
    char l1[11];
    char l2[11];
    std::cin >> l1;
    std::cin >> l2;
    int count=0;
    for(int i=0;l1[i]!='\0';i++){
        count++;
    }
    int *n1=new int[count];
    int *n2=new int[count];
    for(int i=0;l1[i]!='\0';i++){
        int num1=l1[i]-'0';
        int num2=l2[i]-'0';
        n1[i]=num1;
        n2[i]=num2;
    }
    check(n1,n2,count);
    delete [] n1;
    delete [] n2;
    return 0;
}