#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, x;
    std::cin >> n >> x;

    if (n % 2 != x % 2)  
    {
        std::cout << "0\n";
        return;
    }

    x--;
    auto work = [&](int num)
    {
        std::set<int> s;
        for (int i = 1; 1LL * i * i <= num; i++)
        {
            if (num % i == 0)
            {
                if (num / i != num)
                    s.emplace(num / i);
                if (i != num)
                    s.emplace(i);
            }
        }

        return s;
    };

    auto par = [&](int num) { return (num & 1); };

    auto s = work(n - x - 1);
    std::set<int> ok;
    for (auto num : s)
    {
        int k = num + 1;
        if (k > x and k <= n and par((n - x - 1) / (k - 1)) == 0)
            ok.emplace(k);
    }

    s = work(n + x - 1);
    for (auto num : s)
    {
        int k = num + 1;
        if (k > x and k <= n and par((n + x - 1) / (k - 1)) == 0 and (n + x - 1) / (k - 1) - 1 > 0)
            ok.emplace(k);
    }

    std::cout << std::size(ok) << "\n";
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