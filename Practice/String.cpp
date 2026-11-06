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
    String(const String& other):size_(other.size_){
        s_=new char[size_+1];
        memcpy(s_,other.s_,size_+1);
    }
    ~String(){
        delete[] s_;
    }
    char& operator[](unsigned int index){
        return s_[index];
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