#include<iostream>

class stack{
private:
    char *data;
    int top;
    int size;
public:
    stack(int k){
        size=k;
        top=-1;
        data=new char[k];
    }
    ~stack(){delete [] data;}
    bool IsEmpty()const{return top==-1;}
    bool IsFull()const{return top==size-1;}
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

int judge(char a){
    if(a>='0' && a<='9') return 1;
    if(a=='(') return 2;
    if(a==')') return 3;
    if(a=='+' || a=='-' || a=='*' || a=='/') return 4;
    return 0;
}

int main(int argc,char ** argv){
    stack s(100);
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
    count=0;
    std::cout << y << std::endl;
    return 0;
}