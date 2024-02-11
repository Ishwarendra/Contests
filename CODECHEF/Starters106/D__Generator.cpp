#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

template<class T = int> 
T get_rand(T l, T r) 
{
    assert(l <= r);
    return std::uniform_int_distribution<T>(l, r)(rng);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t = 1;
    std::cout << t << "\n";

    while (t--)
    {
        int n = 1e4, m = 1e4 + 1879;
        std::cout << n << " " << m << "\n";
        for (int i = 0; i < m; i++)
            std::cout << get_rand(1, n) << " " << get_rand(1, n) << "\n";
    }
    
    return 0;
}