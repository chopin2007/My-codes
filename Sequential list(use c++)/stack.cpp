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
    bool IsEmpty()const{return top==-1;}
    bool IsFull()const{return top==size-1;}
    void push(const T& d){
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
    void Popout(){
        while(!IsEmpty()){
            std::cout << Top() << " ";
            pop();
        }
        std::cout << std::endl;
    }
};

//链表栈
template <typename T>
class lstack{
private:
    class node{
    private:
        T data_;
        node* next_;
    public:
        node(T d,node* n): data_(d),next_(n) {}
        const T& data()const{return data_;}
        node* next(){return next_;}
    };
    node *top;
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
    void clear(){
        destroyStack();
        size=0;
    }
    bool IsEmpty(){return size==0;}
    bool IsFull(){return false;}
    void push(const T& d){
        top=new node(d,top);
        size++;
    }
    const T& Top(){
        if(IsEmpty()) throw std::out_of_range("错误，空表。");
        else return top->data();
    }
    void pop(){
        if(IsEmpty()) throw std::out_of_range("错误，空表。");
        else{
            node *temp=top;
            top=top->next();
            size--;
            delete temp;
        }
    }
    void Popout(){
        while(!IsEmpty()){
            std::cout << Top() << " ";
            pop();
        }
        std::cout << std::endl;
    }
};

int main(int argc,char **argv){
    int a[]={1,2,3,4,5,6};
    astack<int> al(10);
    lstack<int> ll;
    for(int i=0;i<6;i++){
        al.push(a[i]);
        ll.push(a[i]);
    }
    al.Popout();
    ll.Popout();
    return 0;
}