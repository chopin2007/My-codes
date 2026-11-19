#include<iostream>
#include<vector>

class Minheap{
private:
    std::vector<int> h;
    void up(int i){
        int elem=h[i];
        while(i>1 && elem<h[i/2]){
            h[i]=h[i/2];
            i/=2;
        }
        h[i]=elem;
    }
    void down(int i){
        int last=h.size()-1;
        int elem=h[i];
        while(i*2<=last){
            int child=2*i;
            if(child<last && h[child]>h[child+1]){
                child++;
            }
            if(h[child]<elem){
                h[i]=h[child];
                i=child;
            }
            else break;
        }
        h[i]=elem;
    }
public:
    Minheap(const std::vector<int>& h){
        this->h.push_back(0);
        this->h.insert(this->h.end(),h.begin(),h.end());
        MakeHeapDown();
    }
    void Insert(int e){
        h.push_back(e);
        up(h.size()-1);
    }
    void Delete(){
        std::swap(h[1],h.back());
        h.pop_back();
        down(1);
    }
    void MakeHeapUp(){
        for(int i=2;i<h.size();i++){
            up(i);
        }
    }
    void MakeHeapDown(){
        for(int i=(h.size()-1)/2;i>0;i--){
            down(i);
        }
    }
    int Top()const{return h[1];}
    void traversal()const{
        for(int i=1;i<h.size();i++){
            std::cout << h[i] << " ";
        }
        std::cout << "\n";
    }
};

int main(){
    std::vector<int> arr={3,7,2,6,9,4,8,5,1};
    Minheap h(arr);
    h.traversal();
    return 0;
}