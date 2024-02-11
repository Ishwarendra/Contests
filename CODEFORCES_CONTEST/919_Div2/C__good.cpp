#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);  
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    auto factor = [&](int x)
    {
        std::vector<int> f;
        for (int i = 1; 1LL * i * i <= x; i++)
        {
            if (x % i == 0)
            {
                f.emplace_back(i);
                if (1LL * i * i != x)
                    f.emplace_back(x / i);
            }
        }

        return f;
    };

    int ans = 0;
    auto f = factor(n);
    for (int k : f)
    {
        for (int m = 2; m <= n; m++)   
        {
            auto b = a;
            for (int i = 0; i < n; i++)
                b[i] %= m;

            int ok = 1;
            for (int i = 0; i < k; i++)
            {
                for (int j = i; j < n; j += k)
                {
                    if (b[i] != b[j])                        
                        ok = 0;
                }
            }

            if (ok)
            {
                ans++;
                break;
            }
        }
    } 

    std::cout << std::max(1, ans) << "\n";
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