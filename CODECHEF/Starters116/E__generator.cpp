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
        int n = 1 << get_rand(5, 5);
        std::cout << n << "\n";

        std::vector<int> a(n);
        std::iota(std::begin(a), std::end(a), 1);
        std::shuffle(std::begin(a), std::end(a), rng);

        for (int i = 0; i < n; i++)
            std::cout << a[i] << " \n"[i == n - 1];
    }
    
    return 0;
}