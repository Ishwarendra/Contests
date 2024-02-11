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
        int n = 1;
        int q = 8;
        std::cout << q << "\n";

        while (q--)
        {
            int t = get_rand(1, 2);
            std::cout << t << " ";

            if (t == 1)
            {
                int u = get_rand(1, n);
                std::cout << u << "\n";
                n++;
            }
            else
            {
                int u = get_rand(1, n);
                int x = get_rand<int>(1, 10);
                std::cout << u << " " << x << "\n";
            }
        }
    }
    
    return 0;
}