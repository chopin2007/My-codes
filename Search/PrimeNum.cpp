#include<iostream>
#include<vector>

void divide(long long& n){
    long long res=2;
    long long i=3;
    while(i<=n){
        bool IsPrime=true;
        for(long long j=2;j*j<=i;j++){
            if(i%j==0){
                IsPrime=false;
                break;
            }
        }
        if(IsPrime){
            res=i;
        }
        i+=2;
    }
    std::cout << res << "\n";
}

void Era(long long& n){
    long long res=2;
    std::vector<bool> isprime(n+1);
    isprime[1]=false;
    for(long long i=2;i<=n;i++){
        isprime[i]=true;
    }
    for(long long i=2;i<=n;i++){
        if(isprime[i]){
            res=i;
            long long m=i*2;
            while(m<=n){
                isprime[m]=false;
                m+=i;
            }
        }
    }
    std::cout << res << "\n";
}

void Euler(long long& n){
    long long res=2;
    std::vector<bool> isprime(n+1);
    std::vector<long long> primenum;
    isprime[1]=false;
    for(long long i=2;i<=n;i++){
        isprime[i]=true;
    }
    for(long long i=2;i<=n;i++){
        if(isprime[i]){
            primenum.push_back(i);
            res=i;
        }
        int j=0;
        while(i*primenum[j]<=n){
            isprime[i*primenum[j]]=false;
            if(i%primenum[j]==0){
                break;
            }
            else{
                j++;
            }
        }
    }
    std::cout << res << "\n";
}

int main(){
    long long n;
    std::cin >> n;
    Euler(n);
    Era(n);
    divide(n);
    return 0;
}