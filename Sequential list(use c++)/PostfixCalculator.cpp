#include<iostream>
#include<string>

class stack{
private:
    int *data;
    int size;
    int top;
public:
    stack(int n){
        data=new int[n];
        size=n;
        top=-1;
    }
    ~stack(){delete [] data;} 
    bool IsEmpty(){return top==-1;}
    bool IsFull(){return top==size-1;}
    int Top(){
        if(IsEmpty()) return -1;
        else return data[top];
    }
    void push(int d){
        if(IsFull()) return;
        else data[++top]=d;
    }
    void pop(){
        if(IsEmpty()) return;
        else top--;
    }
};

int main(int argc,char **argv){
    char x[51];
    stack result(100);
    std::cin.getline(x,51);
    int i=0;
    while(x[i]!='\0'){
        if(x[i]>='0' && x[i]<='9'){
            char num[51];
            int j=0;
            while(x[i]>='0' && x[i]<='9'){
                num[j++]=x[i];
                i++;
            }
            num[j]='\0';
            result.push(std::atoi(num));
        }
        else if(x[i]=='+'){
            int num1=result.Top();
            result.pop();
            int num2=result.Top();
            result.pop();
            result.push(num1+num2);
        }
        else if(x[i]=='-'){
            int num1=result.Top();
            result.pop();
            int num2=result.Top();
            result.pop();
            result.push(num2-num1);
        }
        else if(x[i]=='*'){
            int num1=result.Top();
            result.pop();
            int num2=result.Top();
            result.pop();
            result.push(num1*num2);
        }
        else if(x[i]=='/'){
            int num1=result.Top();
            result.pop();
            int num2=result.Top();
            result.pop();
            result.push(num2/num1);
        }
        i++;
    }
    int answer=result.Top();
    result.pop();
    if(!result.IsEmpty()) return 0;
    else std::cout << answer << std::endl;
    return 0;
}