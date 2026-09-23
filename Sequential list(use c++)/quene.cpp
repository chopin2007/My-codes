#include<iostream>

//统一使用虚指
template <typename T>
class quene{
public:
    virtual void clear()=0;
    virtual bool IsEmpty()=0;
    virtual bool IsFull()=0;
    virtual const T& getFront()=0;
    virtual void en(const T& x)=0;
    virtual void de()=0;
};

//顺序队列
template <typename T>
class Aquene:public quene<T>{
private:
    T *data;
    int size;
    int front;
    int rear;
public:
    Aquene(int n):size(n+1){
        data=new T[n+1];
        clear();
    }
    ~Aquene(){delete [] data;}
    void clear(){
        front=0;
        rear=0;
    }
    bool IsEmpty(){return front==rear;}
    bool IsFull(){return (rear+1)%size==front;}
    const T& getFront(){
        if(IsEmpty()) throw;
        else return data[front];
    }
    void en(const T& d){
        if(IsFull()) throw;
        else{
            data[rear]=d;
            rear=(rear+1)%size;
        }
    }
    void de(){
        if(IsEmpty()) throw;
        else{
            front=(front+1)%size;
        }
    }
};

//链式队列
template <typename T>
class Lquene:public quene<T>{
private:
    class node{
    private:
        T data_;
        node *next_;
    public:
        node(const T& d,node* p):data_(d),next_(p){}
        const T& data(){return data_;}
        node* next(){return next_;}
        void setNext(node* p){
            next_=p;
        }
    };
    node *front;
    node *rear;
    int size;
    void destroy(){
        while(front!=nullptr){
            node *temp=front;
            front=front->next();
            delete temp;
        }
    }
public:
    Lquene(){
        front=nullptr;
        rear=nullptr;
        size=0;
    }
    ~Lquene(){destroy();}
    void clear(){
        destroy();
        rear=nullptr;
        size=0;
    }
    bool IsEmpty(){return size==0;}
    bool IsFull(){return false;}
    const T& getFront(){
        if(IsEmpty()) throw;
        else return front->data();
    }
    void en(const T& d){
        node *p=new node(d,nullptr);
        if(IsEmpty()) front=rear=p;
        else{
            rear->setNext(p);
            rear=p;
        }
        size++;
    }
    void de(){
        if(IsEmpty()) throw;
        else{
            node*temp=front;
            front=front->next();
            size--;
            if(IsEmpty()) rear=nullptr;
            delete temp;
        }
    }
};

template <typename T>
void output(quene<T>& q){
    while(!q.IsEmpty()){
        std::cout << q.getFront() << " ";
        q.de();
    }
    std::cout << std::endl;
}

int main(int argc,char **argv){
    int a[]={1,2,3,4,5,6};
    Aquene<int> al(10);
    Lquene<int> ll;
    for(int i=0;i<6;i++){
        al.en(a[i]);
        ll.en(a[i]);
    }
    output(al);
    output(ll);
    return 0;
}