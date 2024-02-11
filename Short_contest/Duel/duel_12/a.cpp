#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, p, k;
    std::cin >> n >> p >> k;

    std::string s;
    std::cin >> s;

    int x, y;
    std::cin >> x >> y;

    std::vector<std::vector<int>> sum(k);
    for (int i = 0; i < k; i++)  
    {
        for (int j = i; j < n; j += k)
        {
            if (sum[i].empty())                        
                sum[i].emplace_back(s[j] == '0');
            else
                sum[i].emplace_back(sum[i].back() + (s[j] == '0'));
        }
    }
    
    i64 best = 1e18;
    for (int i = p - 1; i < n; i++)
    {
        i64 cur = (i - p + 1LL) * y;
        int st = i % k;
        i64 add = sum[st].back();
        if (i / k - 1 >= 0)
            add -= sum[st][i / k - 1];
        cur += add * x;

        best = std::min(best, cur);
    }

    std::cout << best << "\n";
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