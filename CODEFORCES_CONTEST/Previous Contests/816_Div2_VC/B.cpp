#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, k, b;
    i64 s;
    std::cin >> n >> k >> b >> s;  

    if (s < 1LL * k * b or s > 1LL * k * (b + 1) - 1LL + 1LL * (n - 1) * (k - 1))
        std::cout << "-1\n";
    else
    {
        i64 need = s;
        if (s <= 1LL * k * (b + 1) - 1LL)
        {
            std::cout << s << " ";
            for (int i = 0; i < n - 1; ++i)
                std::cout << "0 ";
            std::cout << "\n";
        }
        else
        {
            std::cout << std::max(0LL, 1LL * k * (b + 1) - 1LL) << " ";
            int beauty = 0;
            beauty += std::max(0LL, 1LL * k * (b + 1) - 1LL) / k;

            need -= std::max(0LL, 1LL * k * (b + 1) - 1LL);

            for (int i = 0; i < n - 1; ++i)
            {
                if (need == 0)
                    std::cout << "0 ";
                else if (need <= k - 1)
                {
                    beauty += need / k;
                    std::cout << need << " ";
                    need = 0;
                }
                else
                {
                    beauty += (k - 1) / k;
                    std::cout << k - 1 << " ";
                    need -= (k - 1);
                }
            }
            assert(beauty == b);
            std::cout << "\n";
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}