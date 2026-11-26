#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>

using Clock = std::chrono::steady_clock;

template <typename F>
void timedRun(const char* name, F&& f) {
    auto t1 = Clock::now();
    f();
    auto t2 = Clock::now();
    double ms = std::chrono::duration<double, std::milli>(t2 - t1).count();
    std::cout << name << " time = " << ms << " ms\n";
}

void divide(long long n) {
    if (n < 2) { std::cout << -1 << "\n"; return; }
    long long res = 2;
    for (long long i = 3; i <= n; i += 2) {
        bool IsPrime = true;
        for (long long j = 2; j <= i / j; ++j) {   // 用除法防溢出
            if (i % j == 0) { IsPrime = false; break; }
        }
        if (IsPrime) res = i;
    }
    std::cout << res << "\n";
}

void Era(long long n) {
    if (n < 2) { std::cout << -1 << "\n"; return; }
    std::vector<bool> isprime(static_cast<size_t>(n + 1), true);
    isprime[0] = isprime[1] = false;
    long long res = 2;
    for (long long i = 2; i <= n; ++i) {
        if (isprime[i]) {
            res = i;
            if (i <= n / i) {                       // 防 i*i 溢出
                for (long long m = i * i; m <= n; m += i)
                    isprime[m] = false;
            }
        }
    }
    std::cout << res << "\n";
}

void Euler(long long n) {
    if (n < 2) { std::cout << -1 << "\n"; return; }
    std::vector<bool> isprime(static_cast<size_t>(n + 1), true);
    std::vector<long long> primenum;
    isprime[0] = isprime[1] = false;
    long long res = 2;
    for (long long i = 2; i <= n; ++i) {
        if (isprime[i]) {
            primenum.push_back(i);
            res = i;
        }
        for (long long p : primenum) {
            if (p > n / i) break;                   // 防 i*p 溢出
            isprime[i * p] = false;
            if (i % p == 0) break;
        }
    }
    std::cout << res << "\n";
}

int main() {
    long long n;
    if (!(std::cin >> n)) return 0;

    std::cout << std::fixed << std::setprecision(3);

    timedRun("Euler ", [&]{ Euler(n); });
    timedRun("Era   ", [&]{ Era(n);   });
    timedRun("Divide", [&]{ divide(n); });

    return 0;
}