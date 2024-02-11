#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

template<class T, class G>
T power(T a, G b) 
{
    T res = 1;
    for (; b; b /= 2, a *= a) 
    {
        if (b % 2) 
            res *= a;
    }
    return res;
} 

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    auto s = std::set(std::begin(a), std::end(a));
    auto good = [&](int x, int limit)
    {
        for (int i = 2; 1LL * i * i <= x; i++)
        {
            int cnt = 0;
            while (x % i == 0)
                cnt++, x /= i;

            if (power<i64>(i, cnt) > limit)
                return false;
        }

        if (x > limit)
            return false;

        return true;
    };

    n = std::size(a);
    int ans = 0;
    for (int i = 0;; i++)
    {
        if (s.count(i + 1))
            continue;

        if (!good(i + 1, i))
        {
            std::cout << i + 1 << "\n";
            return;
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}