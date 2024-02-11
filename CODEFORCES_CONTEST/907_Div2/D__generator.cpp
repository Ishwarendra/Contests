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
        std::array<i64, 2> a{};
        i64 st = 3;
        for (int i = 0; i < 2; i++)
            a[i] = get_rand<i64>(st, st + 1e7);
        std::sort(std::begin(a), std::end(a));

        a[0] = 10;
        for (int i = 0; i < 2; i++)
            std::cout << a[i] << " \n"[i == 1];
    }
    
    return 0;
}