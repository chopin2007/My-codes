#include<iostream>
#include<cstring>

class String{
private:
    char* s_;
    unsigned size_;
public:
    String(const char* string){
        size_=strlen(string);
        s_=new char[size_+1];
        memcpy(s_,string,size_);
        s_[size_]=0;
    }
    friend std::ostream& operator<<(std::ostream& stream,const String& string);
};

std::ostream& operator<<(std::ostream& stream,const String& string){
    stream << string.s_;
    return stream;
}

int main(){
    String string="Chopin";
    std::cout << string << std::endl;
    return 0;
}