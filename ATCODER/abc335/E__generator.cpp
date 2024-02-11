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
    // std::cout << t << "\n";

    while (t--)
    {
        int n = get_rand(2, 6);
        int m = get_rand(n - 1, std::min(10, n * (n - 1) / 2));

        std::cout << n << " " << m << "\n";
        for (int i = 0; i < n; i++)
            std::cout << get_rand(1, 10) << " \n"[i == n - 1];

        std::map<std::pair<int, int>, bool> done;
        int sz = 1;
        for (int i = 0; i < n - 1; i++)
        {
            int v = get_rand(1, sz);
            std::cout << v << " " << sz + 1 << "\n";
            sz++;
            done[{sz, v}] = done[{v, sz}] = true;
        }

        for (int i = n - 1; i < m; i++)
        {
            int u = get_rand(1, n);
            int v = get_rand(1, n);

            while (u == v || done[{u, v}])
                u = get_rand(1, n), v = get_rand(1, n);

            done[{u, v}] = done[{v, u}] = true;
            auto [x, y] = std::minmax(u, v);
            std::cout << x << " " << y << "\n";
        }
    }
    
    return 0;
}