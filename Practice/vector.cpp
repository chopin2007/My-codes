#include<iostream>
#include<vector>

template <typename T>
class Vertex{
private:
    T x,y,z;
public:
    Vertex(const T& x,const T& y,const T& z):x(x),y(y),z(z){}
    Vertex(const Vertex& vertex):x(vertex.X()),y(vertex.Y()),z(vertex.Z()){
        std::cout << "Copied!" << std::endl;
    }
    T X()const{return x;}
    T Y()const{return y;}
    T Z()const{return z;}
};

int main(){
    std::vector<Vertex<float>> arr;

    //6 times 1+2+3
    arr.push_back({1,2,3});
    arr.push_back({4,5,6});
    arr.push_back({7,8,9});
    std::cout << "\n";

    arr.clear();
    //3 times reserve
    arr.reserve(3);
    arr.push_back({1,2,3});
    arr.push_back({4,5,6});
    arr.push_back({7,8,9});
    std::cout << "\n";

    arr.clear();
    //0 times reserve+emplace_back
    arr.emplace_back(1,2,3);
    arr.emplace_back(4,5,6);
    arr.emplace_back(7,8,9);
    std::cout << "\n";

    return 0;
}