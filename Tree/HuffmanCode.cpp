#include<iostream>
#include<string>
#include<unordered_map>
#include<algorithm>
#include<vector>
#include<stack>

std::unordered_map<std::string,int> hp;

class Node{
private:
    std::string val_;
    Node* lchild_;
    Node* rchild_;
public:
    Node(const std::string& v,Node* l=nullptr,Node* r=nullptr):val_(v),lchild_(l),rchild_(r){}
    int Value()const{
        if(hp.count(val_)) return hp[val_];
        else return std::stoi(val_);
    }
    Node* Lchild()const{return lchild_;}
    Node* Rchild()const{return rchild_;}
    void SetValue(const std::string& v){val_=v;}
    void SetLchild(Node* l){lchild_=l;}
    void SetRchild(Node* r){rchild_=r;}
};

class Tree{
private:
    Node* root_;
public:
    Tree(const std::string& v,Node* l=nullptr,Node* r=nullptr):root_(new Node(v,l,r)){}
    Tree(Node* r):root_(r){}
    ~Tree(){
        if(root_==nullptr) return;
        std::stack<Node*> s1,s2;
        s1.push(root_);
        while(!s1.empty()){
            Node* p=s1.top();
            s1.pop();
            s2.push(p);
            if(p->Rchild()) s1.push(p->Rchild());
            if(p->Lchild()) s1.push(p->Lchild());
        }
        while(!s2.empty()){
            delete s2.top();
            s2.pop();
        }
        root_=nullptr;
    }
    Node* Root()const{return root_;}
};

Tree CreatHuffmanTree(const std::vector<std::string>& a){
    int n=a.size();
    std::vector<Node*> nodes;
    for(int i=0;i<n;i++){
        nodes.push_back(new Node(a[i]));
    }
    for(int i=0;i<n-1;i++){
        Node* p=new Node("#");
        std::sort(nodes.begin(),nodes.end(),[](const Node* a,const Node* b){
            return a->Value()>b->Value();
        });
        p->SetLchild(nodes.back());
        nodes.pop_back();
        p->SetRchild(nodes.back());
        nodes.pop_back();
        p->SetValue(std::to_string(p->Lchild()->Value()+p->Rchild()->Value()));
        nodes.push_back(p);
    }
    return Tree(nodes.front());
}

void Decoding(const Tree& t,std::string s){
    Node* p=t.Root();
    int n=s.size();
    for(int i=0;i<n-1;i++){
        
    }
}

int main(int argc,char * argv[]){
    std::string input;
    std::cin >> input;
    std::vector<std::string> sa;
    for(int i=0;i<input.size();i++){
        std::string p=std::to_string(input[i]);
        if(!hp.count(p)){
            sa.push_back(p);
        }
        hp[p]++;
    }
    Tree t1=CreatHuffmanTree(sa);
    Decoding(t1,input);
    return 0;
}