#include<iostream>
#include<string>
#include<algorithm>

class Plus{
private:
    std::string n1;
    std::string n2;
    int aob;
    std::string result;
public:
    Plus(const std::string& x1,const std::string& x2):n1(x1),n2(x2),aob(0),result(""){}
    bool GreaterOrEqual(const std::string& a, const std::string& b){
        if(a.size()!=b.size()){
            return a.size() > b.size();
        }
        for(int i=0;i<a.size();++i){
            if (a[i] != b[i]){
                return a[i] > b[i];
            }
        }
        return true;
    }
    void BigAddition(const std::string& num1,const std::string& num2){
        int p1=num1.size()-1;
        int p2=num2.size()-1;
        while(p1!=-1 && p2!=-1){
            int temp=(num1[p1--]-'0')+(num2[p2--]-'0')+aob;
            aob=0;
            if(temp>=10){
                aob+=1;
                temp%=10;
            }
            result.push_back(temp+'0');
        }
        while(p1!=-1 && p2==-1){
            int temp=(num1[p1--]-'0')+aob;
            aob=0;
            if(temp>=10){
                aob+=1;
                temp%=10;
            }
            result.push_back(temp+'0');
        }
        while(p1==-1 && p2!=-1){
            int temp=(num2[p2--]-'0')+aob;
            aob=0;
            if(temp>=10){
                aob+=1;
                temp%=10;
            }
            result.push_back(temp+'0');
        }
        if (aob!=0) result.push_back('1');
        std::reverse(result.begin(),result.end());
    }
    void BigSubstraction(const std::string& num1,const std::string& num2){
        int p1=num1.size()-1;
        int p2=num2.size()-1;
        while(p1!=-1 && p2!=-1){
            int temp=(num1[p1--]-'0')-(num2[p2--]-'0')-aob;
            aob=0;
            if(temp<0){
                aob+=1;
                temp+=10;
            }
            result.push_back(temp+'0');
        }
        while(p1!=-1){
            int temp=num1[p1--]-'0'-aob;
            aob=0;
            if (temp<0){
                temp+=10;
                aob=1;
            }
            result.push_back(temp+'0');
        }
        std::reverse(result.begin(),result.end());
        size_t start = 0;
        while (start < result.size() - 1 && result[start] == '0') {
            start++;
        }
        result=result.substr(start);
    }
    void Result(){
        if(n1.front()!='-'){
            if(n2.front()!='-'){
                BigAddition(n1,n2);
            }
            else{
                if(GreaterOrEqual(n1,n2.substr(1))) BigSubstraction(n1,n2.substr(1));
                else{
                    BigSubstraction(n2.substr(1),n1);
                    result.insert(result.begin(),'-');
                }
            }
        }
        else{
            if(n2.front()!='-'){
                if(GreaterOrEqual(n1.substr(1),n2)){
                    BigSubstraction(n1.substr(1),n2);
                    result.insert(result.begin(),'-');
                }
                else{
                    BigSubstraction(n2,n1.substr(1));
                }
            }
            else{
                BigAddition(n1.substr(1),n2.substr(1));
                result.insert(result.begin(),'-');
            }
        }
    }
    void printResult(){
        Result();
        for(int i=0;i<result.size()-1;i++){
            std::cout << result[i];
        }
        std::cout << result.back() << std::endl;
    }
};

int main(){
    std::string a;
    std::string b;
    std::cin >> a >> b;
    Plus* ab=new Plus(a,b);
    ab->printResult();
    return 0;
}