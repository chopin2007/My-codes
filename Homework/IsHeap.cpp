#include<iostream>
#include<vector>

class Heap{
private:
    std::vector<int> val;
    int type=-1;//-1:not 0:max 1:min
    bool IsMax()const{
        for(int i=1;i<val.size();i++){
            if(2*i<val.size() && val[i]<val[2*i]) return false;
            if(2*i+1<val.size() && val[i]<val[2*i+1]) return false;
        }
        return true;
    }
    bool IsMin()const{
        for(int i=1;i<val.size();i++){
            if(2*i<val.size() && val[i]>val[2*i]) return false;
            if(2*i+1<val.size() && val[i]>val[2*i+1]) return false;
        }
        return true;
    }
public:
    Heap(const std::vector<int>& h){
        val=h;
        val.insert(val.begin(),0);
        if(IsMax()) type=0;
        else if(IsMin()) type=1;
    }
    void Type()const{
        switch(type){
            case -1:
                std::cout << "Not Heap" << std::endl;
                break;
            case 0:
                std::cout << "Max Heap" << std::endl;
                break;
            case 1:
                std::cout << "Min Heap" << std::endl;
                break;
        }
    }
};

void postorder(const std::vector<int>& a,int p,std::vector<int>& r){
    if(p>a.size()-1) return;
    postorder(a,2*p,r);
    postorder(a,2*p+1,r);
    r.push_back(a[p]);
}

int main(){
    int n,m;
    std::cin >> n >> m;
    for(int i=0;i<n;i++){
        std::vector<int> arr;
        for(int j=0;j<m;j++){
            int elem;
            std::cin >> elem;
            arr.push_back(elem);
        }
        Heap h(arr);
        h.Type();
        arr.insert(arr.begin(),0);
        std::vector<int> res={0};
        postorder(arr,1,res);
        for(int j=1;j<res.size();j++){
            std::cout << res[j] << " ";
        }
        std::cout << "\n";
    }
    return 0;
}