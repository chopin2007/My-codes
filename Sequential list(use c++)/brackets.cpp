#include<iostream>

bool flag=true;

class stack{
private:
    char *data;
    int size;
    int top;
public:
    stack(int n){
        data=new char[n];
        size=n;
        top=-1;
    }
    ~stack(){
        delete [] data;
    }
    bool IsEmpty(){return top==-1;}
    bool IsFull(){return top==size-1;}
    char Top(){
        if(IsEmpty()) throw;
        else return data[top];
    }
    void push(char a){
        if(IsFull()) throw;
        else{
            top++;
            data[top]=a;   
        }
    }
    void pop(){
        if(IsEmpty()) throw;
        else top--;
    }
};

bool IsMatch(char a,char b){
    if(a=='(' && b==')' || a==')' && b=='('){
        return true;
    }
    if(a=='[' && b==']' || a==']' && b=='['){
        return true;
    }
    if(a=='{' && b=='}' || a=='}' && b=='{'){
        return true;
    }
    return false;
}

int main(int argc,char **argv){
    char string[100]="";
    std::cin >> string;
    stack st=stack(100);
    int i=0;
    while(string[i]!=0){
        if(string[i]=='(' || string[i]=='[' || string[i]=='{'){
            st.push(string[i]);
        }
        else{
            if(!st.IsEmpty() && IsMatch(string[i],st.Top())){
                st.pop();
            }
            else{
                flag=false;
            }
        }
        i++;
    }
    if(flag && !st.IsEmpty()){
        flag=false;
    }
    std::cout << flag << std::endl;
    return 0;
}