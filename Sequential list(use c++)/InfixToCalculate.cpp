#include<iostream>
#include<string>

class stack{
protected:
    int top;
    int size;
public:
    bool IsEmpty()const{return top==-1;}
    bool IsFull()const{return top==size-1;}
};

class cstack:public stack{
private:
    char *data;
public:
    cstack(int k){
        size=k;
        top=-1;
        data=new char[k];
    }
    ~cstack(){delete [] data;}
    char Top(){
        if(IsEmpty()) return 0;
        else return data[top];
    }
    void push(char a){
        if(IsFull()) return;
        else{
            top++;
            data[top]=a;
        }
    }
    void pop(){
        if(IsEmpty()) return;
        else{top--;}
    }
};

class istack:public stack{
private:
    int *data;
public:
    istack(int n){
        data=new int[n];
        size=n;
        top=-1;
    }
    ~istack(){delete [] data;} 
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

int judge(char a){
    if(a>='0' && a<='9') return 1;
    if(a=='(') return 2;
    if(a==')') return 3;
    if(a=='+' || a=='-' || a=='*' || a=='/') return 4;
    return 0;
}

int main(int argc,char ** argv){
    cstack s(100);
    char x[51],y[101];
    int count=0;
    std::cin.getline(x,51);
    int i=0;
    while(x[i]!='\0'){
        switch(judge(x[i])){
            case 0:return 0;
            case 1:
                while(x[i] >= '0' && x[i] <= '9'){
                    y[count++] = x[i];
                    i++;
                }
                y[count++] = ' ';
                i--;
                break;
            case 2:
                s.push(x[i]);
                break;
            case 3:
                if(s.IsEmpty()) return 0;
                while(!s.IsEmpty() && s.Top()!='('){
                    y[count++]=s.Top();
                    y[count++]=' ';
                    s.pop();
                }
                if(!s.IsEmpty() && s.Top()=='(') s.pop();
                else return 0;
                break;
            case 4:
                while(!s.IsEmpty() && s.Top()!='(' && ((s.Top()=='*' || s.Top()=='/') || ((x[i]=='+' || x[i]=='-') && (s.Top()=='+' || s.Top()=='-')))){
                    y[count++]=s.Top();
                    y[count++]=' ';
                    s.pop();
                }
                s.push(x[i]);
                break;
        }
        i++;
    }
    while(!s.IsEmpty() && s.Top()!='('){
        y[count++]=s.Top();
        y[count++]=' ';
        s.pop();
    }
    if(!s.IsEmpty()) return 0;
    y[count]='\0';
    istack result(100);
    i=0;
    while(y[i]!='\0'){
        if(y[i]>='0' && y[i]<='9'){
            char num[51];
            int j=0;
            while(y[i]>='0' && y[i]<='9'){
                num[j++]=y[i];
                i++;
            }
            num[j]='\0';
            result.push(std::atoi(num));
        }
        else if(y[i]=='+'){
            int num1=result.Top();
            result.pop();
            int num2=result.Top();
            result.pop();
            result.push(num1+num2);
        }
        else if(y[i]=='-'){
            int num1=result.Top();
            result.pop();
            int num2=result.Top();
            result.pop();
            result.push(num2-num1);
        }
        else if(y[i]=='*'){
            int num1=result.Top();
            result.pop();
            int num2=result.Top();
            result.pop();
            result.push(num1*num2);
        }
        else if(y[i]=='/'){
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