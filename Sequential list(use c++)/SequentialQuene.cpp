#include<iostream>

class Quene{
private:
    int* data;
    int front;
    int rear;
    int size;
public:
    Quene(int n){
        data=new int[n+1];
        front=rear=0;
        size=n+1;
    }
    ~Quene(){delete [] data;}
    bool IsEmpty(){return front==rear;}
    bool IsFull(){return (rear+1)%size==front;}
    void GetFront(){
        if(IsEmpty()){
            std::cout << "错误：队列为空。" << std::endl;
            std::cout << -1 << std::endl;            
        }
        else std::cout << data[front] << std::endl;
    }
    void add(int d){
        if(IsFull()) std::cout << "错误：队列已满。" << std::endl;
        else{
            data[rear]=d;
            rear=(rear+1)%size;
        }
    }
    void del(){
        if(IsEmpty()) std::cout << "错误：队列为空。" << std::endl;
        else{
            front=(front+1)%size;
        }
    }
};

int main(int argc,char ** argv){
    int len;
    std::cin >> len;
    int *list=new int[len+1]; 
    Quene q=Quene(len);
    for(int i=0;i<len+1;i++){
        std::cin >> list[i];
    }
    for(int i=0;i<len+1;i++){
        q.add(list[i]);
    }
    for(int i=0;i<len+1;i++){
        q.GetFront();
        q.del();
    }
    return 0;
}