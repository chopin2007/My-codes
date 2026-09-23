#include<iostream>

class stack{
private:
    int* data;
    int size;
    int top;
public:
    stack(int n){
        data=new int[n];
        size=n;
        top=-1;
    }
    ~stack(){
        delete [] data;
    }
    bool IsEmpty(){return top==-1;}
    bool IsFull(){return top==size-1;}
    int Top(){
        if(IsEmpty()) return 0;
        else return data[top];
    }
    void push(int n){
        if(IsFull()) return;
        else{
            top++;
            data[top]=n;
        }
    }
    void pop(){
        if(IsEmpty()) return;
        else{
            top--;
        }
    }
    void Popout(){
        while(!IsEmpty()){
            std::cout << data[top];
            top--;
        }
        std::cout << std::endl;
    }
};

int main(int argc,char **argv){
    stack l=stack(100);
    int c,num,per;
    std::cin >> c;
    std::cin >> num;
    while(num>0){
        per=num%c;
        num=num/c;
        l.push(per);
    }
    l.Popout();
    return 0;
}