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

    while (t--)
    {
        int n = 10;
        std::cout << n << " 2\n";

        int sz = 1;
        for (int i = 0; i < n - 1; i++)
        {
            std::cout << sz + 1 << " " << get_rand(1, sz) << '\n';
            sz++;
        }

        std::string s;
        for (int i = 0; i < n; i++)
            s += get_rand(0, 1) ? '(' : ')';
        std::cout << s << "\n";

        int l = get_rand(1, n);
        std::cout << "2 " << l << " " << get_rand(l, n) << '\n';
        l = get_rand(1, n);
        std::cout << "1 " << l << " " << get_rand(l, n);
    }
    
    return 0;
}