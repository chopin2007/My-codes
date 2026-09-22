#include<iostream>
#include<stdexcept>

//顺序栈
template <typename T>
class astack{
private:
    T* data;
    int size;
    int top;
public:
    astack(int k){
        size=k;
        top=-1;
        data=new T[k];
    }
    ~astack(){
        delete [] data;
    }
    void clear(){top=-1;}
    bool IsEmpty(){return top==-1;}
    bool IsFull(){return top==size-1;}
    void push(T d){
        if(IsFull()) throw std::out_of_range("错误，上溢。");
        else{
            top++;
            data[top]=d;
        }
    }
    const T& Top()const{
        if(IsEmpty()) throw std::out_of_range("错误，空表。");
        else return data[top];
    }
    void pop(){
        if(IsEmpty()) throw std::out_of_range("错误，空表。");
        else top--;
    }
};

//链表栈
template <typename T>
class lstack{
private:
    class node(){
    private:
        T data;
        node* next;
    public:
        node(T d,node* n): data(d),next(n) {}
        const T& data()const{return data;}
        node* next(){return next;}
    };
    int top;
    int size;
    void destroyStack(){
        while(top!=nullptr){
            node *temp=top;
            top=top->next();
            delete temp;
        }
    }
public:
    lstack(){
        top=nullptr;
        size=0;
    }
    ~lstack(){destroyStack();}
    //困了，写到这:)
};

template <typename T>
void Popout(astack<T>& a){
    while(!a.IsEmpty()){
        std::cout << a.Top() << " ";
        a.pop();
    }
    std::cout << std::endl;
}

int main(int argc,char **argv){
    int a[]={1,2,3,4,5,6};
    astack<int> al(10);
    for(int i=0;i<6;i++){
        al.push(a[i]);
    }
    Popout(al);
    return 0;
}