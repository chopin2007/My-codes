#include<iostream>
#include<algorithm>
#include<vector>

class Tree{
private:
    class Node{
    private:
        char val_;
        int fa_;
    public:
        Node(char v,int f):val_(v),fa_(f){}
        char Value()const{return val_;}
        int Father()const{return fa_;}
        void SetValue(char v){val_=v;}
        void SetFather(int f){fa_=f;}
    };
    std::vector<Node*> nodes;
public:
    Tree(){nodes.clear();}
    Tree(char v,int fa=-1){
        nodes.push_back(new Node(v,fa));
    }
    void addNode(char v,int fa){
        nodes.push_back(new Node(v,fa));
    }
    int LCA(int& x,int& y)const{
        int tx=x;
        int ty=y;
        while(tx>=0 && ty>=0){
            tx=nodes[tx]->Father();
            ty=nodes[ty]->Father();
        }
        if(ty<0){
            std::swap(x,y);
            std::swap(tx,ty);
        }
        while(ty>=0){
            ty=nodes[ty]->Father();
            y=nodes[y]->Father();
        }
        while(x!=y){
            x=nodes[x]->Father();
            y=nodes[y]->Father();
        }
        return x;
    }
};

int main(int argc,char * argv[]){
    Tree t1('A',-1);
    t1.addNode('B',0);
    t1.addNode('C',0);
    t1.addNode('D',0);
    t1.addNode('E',1);
    t1.addNode('F',1);
    t1.addNode('G',1);
    t1.addNode('H',2);
    t1.addNode('I',3);
    t1.addNode('J',3);
    t1.addNode('K',5);
    t1.addNode('L',5);
    t1.addNode('M',9);
    int a;
    std::cin >> a;
    int b;
    std::cin >> b;
    std::cout << t1.LCA(a,b) << std::endl;
    return 0;
}