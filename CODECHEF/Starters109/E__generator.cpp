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
        int n = get_rand(1, 30);
        int d = 0;

        std::vector<int> a(n);
        for (int i = 0; i < n; i++)
            a[i] = get_rand(1, 30);

        // for (int i = 1; i < n; i++)
        //     d = std::max(d, std::abs(a[i] - a[i - 1]));

        std::cout << n << " " << get_rand(1, 15) << "\n";
        std::vector<int> max(n), min(n);
        max[0] = min[0] = a[0];

        for (int i = 1; i < n; i++)
        {
            max[i] = std::max(max[i - 1], a[i]);
            min[i] = std::min(min[i - 1], a[i]);
        }

        for (int i = 0; i < n; i++)
            std::cout << max[i] << " \n"[i == n - 1];
        for (int i = 0; i < n; i++)
            std::cout << min[i] << " \n"[i == n - 1];
    }
    
    return 0;
}