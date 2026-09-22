#include<iostream>

struct sth{
    static int x,y;
    static void print(){
        std::cout << x << " " << y << std::endl;
    }
};

int sth::x;
int sth::y;

int main(int argc,char **argv){
    sth::x=4;
    sth::y=8;
    sth::print();
    return 0;
}